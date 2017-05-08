#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "../../libs/macros.h"

#include "pwm_timer_servo.h"
#include "../servo_pwm/servo_constants.h"



void pwm_timer_init_peripheral(pwm_timer_desc_t *timer){
    if(timer->initialized){
        return;
    }
    /* Enable timer clock. */
    rcc_peripheral_enable_clock(timer->peripheral_register, timer->periph_enable);

    /* Reset peripheral */
    timer_reset(timer->timer_peripheral);

    /* Set the timers global mode to:
     * - use no divider
     * - alignment edge
     * - count direction up
     */
    timer_set_mode(timer->timer_peripheral,
                    TIM_CR1_CKD_CK_INT,
                    TIM_CR1_CMS_EDGE,
                    TIM_CR1_DIR_UP);

    timer_set_prescaler(timer->timer_peripheral, timer->prescaler);
    timer_set_repetition_counter(timer->timer_peripheral, 0);
    timer_enable_preload(timer->timer_peripheral);
    timer_continuous_mode(timer->timer_peripheral);
    timer_set_period(timer->timer_peripheral, timer->period);

    timer->initialized = 1;
}


static int pwm_timer_servo_set_position(servo_desc_t *servo, uint32_t pos_us){
    pwm_timer_servo_desc_t *pwm_timer_servo = container_of(servo, pwm_timer_servo_desc_t, servo);
    timer_set_oc_value(pwm_timer_servo->timer_peripheral, pwm_timer_servo->oc_id, pos_us);
    return 0;
}


static int pwm_timer_servo_get_position(servo_desc_t *servo, uint32_t *pos_us){
    pwm_timer_servo_desc_t *pwm_timer_servo = container_of(servo, pwm_timer_servo_desc_t, servo);

    //see libopencm3\lib\stm32\common\timer_common_all.c, timer_set_oc_value
    switch (pwm_timer_servo->oc_id) {
    case TIM_OC1:
        *pos_us = TIM_CCR1(pwm_timer_servo->timer_peripheral);
        return 0;
    case TIM_OC2:
        *pos_us = TIM_CCR2(pwm_timer_servo->timer_peripheral);
        return 0;
    case TIM_OC3:
        *pos_us = TIM_CCR3(pwm_timer_servo->timer_peripheral);
        return 0;
    case TIM_OC4:
        *pos_us = TIM_CCR4(pwm_timer_servo->timer_peripheral);
        return 0;
    case TIM_OC1N:
    case TIM_OC2N:
    case TIM_OC3N:
       /* Ignoring as this option applies to the whole channel. */
        return 1;
    default:
        return 1;
    }
}


void pwm_timer_servo_init(pwm_timer_servo_desc_t *pwm_timer_servo,
        pwm_timer_desc_t *timer,
        enum tim_oc_id oc_id,
        volatile uint32_t *gpio_peripheral_register,
        uint32_t gpio_periph_enable,
        uint32_t gpio_port,
        uint16_t gpio_pin){

    pwm_timer_init_peripheral(timer);
    pwm_timer_servo->timer_peripheral = timer->timer_peripheral;
    pwm_timer_servo->oc_id = oc_id;

    rcc_peripheral_enable_clock(gpio_peripheral_register, gpio_periph_enable);

    /* Set timer channel to output */
    gpio_set_mode(gpio_port, GPIO_MODE_OUTPUT_50_MHZ,
                   GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
                   gpio_pin);
    timer_disable_oc_output(pwm_timer_servo->timer_peripheral, pwm_timer_servo->oc_id);
    timer_set_oc_mode(pwm_timer_servo->timer_peripheral, pwm_timer_servo->oc_id, TIM_OCM_PWM1);
    timer_set_oc_value(pwm_timer_servo->timer_peripheral, pwm_timer_servo->oc_id, 0);
    timer_enable_oc_output(pwm_timer_servo->timer_peripheral, pwm_timer_servo->oc_id);

    multiservo_init(&pwm_timer_servo->servo,
        pwm_timer_servo_set_position, pwm_timer_servo_get_position,
        SERVO_MIN, SERVO_MAX);
}


void pwm_timer_init(pwm_timer_desc_t *pwm_timer,
        volatile uint32_t *peripheral_register,
        uint32_t timer_peripheral,
        uint32_t periph_enable,
        uint32_t prescaler,
        uint32_t period){

    pwm_timer->initialized = 0;
    pwm_timer->peripheral_register = peripheral_register;
    pwm_timer->timer_peripheral = timer_peripheral;
    pwm_timer->periph_enable = periph_enable;
    pwm_timer->prescaler = prescaler;
    pwm_timer->period = period;
}


void pwm_timer_start(pwm_timer_desc_t *pwm_timer){
    timer_enable_counter(pwm_timer->timer_peripheral);
}
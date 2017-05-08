#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "../../libs/macros.h"

#include "softpwm_servo.h"
#include "../servo_pwm/servo_constants.h"


//TODO: check if copy is atomic?

static int softpwm_servo_set_position(servo_desc_t *servo, uint32_t pos_us){
    softpwm_servo_desc_t *soft_servo = container_of(servo, softpwm_servo_desc_t, servo);
    soft_servo->value = pos_us;
    return 0;
}


static int softpwm_servo_get_position(servo_desc_t *servo, uint32_t *pos_us){
    softpwm_servo_desc_t *soft_servo = container_of(servo, softpwm_servo_desc_t, servo);

    *pos_us = soft_servo->value;
    return 0;
}

void softpwm_servo_init(softpwm_servo_desc_t *softpwm_servo,
        volatile uint32_t *gpio_peripheral_register,
        uint32_t gpio_periph_enable,
        uint32_t gpio_port,
        uint16_t gpio_pin){

    rcc_peripheral_enable_clock(gpio_peripheral_register, gpio_periph_enable);

    /* Set output mode */
    gpio_set_mode(gpio_port, GPIO_MODE_OUTPUT_50_MHZ,
        GPIO_CNF_OUTPUT_PUSHPULL,
        gpio_pin);

    softpwm_servo->gpio_port = gpio_port;
    softpwm_servo->gpio_pin = gpio_pin;

    softpwm_servo->value = SERVO_NULL;

    multiservo_init(&softpwm_servo->servo,
        softpwm_servo_set_position, softpwm_servo_get_position,
        SERVO_MIN, SERVO_MAX);

}


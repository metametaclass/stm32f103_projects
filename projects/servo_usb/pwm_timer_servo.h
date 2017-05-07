#ifndef PWM_TIMER_SERVO_H
#define PWM_TIMER_SERVO_H

#include <libopencm3/stm32/timer.h>

#include "multi_servo.h"

typedef struct pwm_timer_desc_s pwm_timer_desc_t;


struct  pwm_timer_desc_s {
    volatile int initialized;
    volatile uint32_t *peripheral_register;
    uint32_t timer_peripheral;
    uint32_t periph_enable;
    uint32_t prescaler;
    uint32_t period;
};


typedef struct pwm_timer_servo_desc_s {
    servo_desc_t servo;
    uint32_t timer_peripheral;
    enum tim_oc_id oc_id;//channel
} pwm_timer_servo_desc_t;



void pwm_timer_init(pwm_timer_desc_t *pwm_timer,
    volatile uint32_t *peripheral_register,
    uint32_t timer_peripheral,
    uint32_t periph_enable);


void pwm_timer_start(pwm_timer_desc_t *pwm_timer);


void pwm_timer_servo_init(pwm_timer_servo_desc_t *pwm_timer_servo,
    pwm_timer_desc_t *timer,
    enum tim_oc_id oc_id,
    volatile uint32_t *gpio_peripheral_register,
    uint32_t gpio_periph_enable,
    uint32_t gpio_port,
    uint16_t gpio_pin);

#endif
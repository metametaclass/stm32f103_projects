#ifndef SOFTPWM_SERVO_H
#define SOFTPWM_SERVO_H

#include "multi_servo.h"

// 72/360 = 200 KHz
#define SOFTPWM_PRESCALE (360-1)


//timer reload 2 - 100 KHz - 10 us precision
#define SOFTPWM_REPEAT (2-1)

//10 us koeff
#define SOFTPWM_DIVIDER 10

//100 Khz/2000 - 50 Hz PWM freq
#define SOFTPWM_PERIOD (2000)


//indication led toggle interval
#define SOFTPWM_LED_INTERVAL 25


typedef struct softpwm_desc_s softpwm__desc_t;

typedef struct softpwm_servo_desc_s {
    servo_desc_t servo;
    uint32_t gpio_port;
    uint16_t gpio_pin;
    volatile uint32_t shadow_value;
    volatile uint32_t value;
    volatile uint32_t set;
} softpwm_servo_desc_t;


void softpwm_servo_init(softpwm_servo_desc_t *softpwm_servo,
    volatile uint32_t *gpio_peripheral_register,
    uint32_t gpio_periph_enable,
    uint32_t gpio_port,
    uint16_t gpio_pin);


#endif
#ifndef SOFTPWM_SERVO_H
#define SOFTPWM_SERVO_H

#include "multi_servo.h"

typedef struct softpwm_desc_s softpwm__desc_t;

typedef struct softpwm_servo_desc_s {
    servo_desc_t servo;
    uint32_t gpio_port;
    uint16_t gpio_pin;
    volatile uint32_t shadow_value;
    volatile uint32_t value;
} softpwm_servo_desc_t;


void softpwm_servo_init(softpwm_servo_desc_t *softpwm_servo,
    volatile uint32_t *gpio_peripheral_register,
    uint32_t gpio_periph_enable,
    uint32_t gpio_port,
    uint16_t gpio_pin);


#endif
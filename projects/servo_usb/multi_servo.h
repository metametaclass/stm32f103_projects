#ifndef MULTI_SERVO_H
#define MULTI_SERVO_H

#include <stdint.h>

typedef struct servo_desc_s servo_desc_t;

//typedef int (*init_servo_callback_t)(servo_desc_t *servo);

typedef int (*set_servo_callback_t)(servo_desc_t *servo, uint32_t pos_us);

typedef int (*get_servo_callback_t)(servo_desc_t *servo, uint32_t *pos_us);


typedef struct servo_desc_s {
    //init_servo_callback_t on_init;
    set_servo_callback_t on_set_position;
    get_servo_callback_t on_get_position;
    uint32_t min_value;
    uint32_t max_value;
} servo_desc_t;


void multiservo_init(servo_desc_t *servo,
    //init_servo_callback_t init,
    set_servo_callback_t set,
    get_servo_callback_t get,
    uint32_t min,
    uint32_t max
    );

int multiservo_set_position(servo_desc_t *servo, uint32_t pos_us);

int multiservo_get_position(servo_desc_t *servo, uint32_t *pos_us);


#endif
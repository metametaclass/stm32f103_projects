#include "multi_servo.h"


void multiservo_init(servo_desc_t *servo,
    //init_servo_callback_t init,
    set_servo_callback_t set,
    get_servo_callback_t get,
    uint32_t min,
    uint32_t max
    ){
    //servo->on_init = init;
    servo->on_set_position = set;
    servo->on_get_position = get;
    servo->min_value = min;
    servo->max_value = max;
}

int multiservo_set_position(servo_desc_t *servo, uint32_t pos_us){
    if(servo->min_value>pos_us){
        pos_us = servo->min_value;
    }
    if(servo->max_value<pos_us){
        pos_us = servo->max_value;
    }
    return servo->on_set_position(servo, pos_us);

}

int multiservo_get_position(servo_desc_t *servo, uint32_t *pos_us){
    return servo->on_get_position(servo, pos_us);
}


#include "multi_servo.h"


void multiservo_init_desc(servo_desc_t *servo,
    init_servo_callback_t init,
    set_servo_callback_t set,
    get_servo_callback_t get,
    uint32_t min,
    uint32_t max
    ){
    servo->on_init = init;
    servo->on_set_position = set;
    servo->on_get_position = get;
    servo->min_value = min;
    servo->max_value = max;
}

int multiservo_set_position(servo_desc_t *servo, uint32_t position){
    if(servo->min_value>position){
        position = servo->min_value;
    }
    if(servo->max_value<position){
        position = servo->max_value;
    }
    return servo->on_set_position(servo, position);

}

int multiservo_get_position(servo_desc_t *servo, uint32_t *position){
    return servo->on_get_position(servo, position);
}


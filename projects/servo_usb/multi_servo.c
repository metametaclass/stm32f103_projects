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


int multiservo_set_position2(servo_desc_t *servo, uint32_t *pos_us){
    int rc;
    rc = multiservo_set_position(servo, *pos_us);
    if(rc){
        return rc;
    }
    *pos_us = 0;
    return multiservo_get_position(servo, pos_us);
}


int multiservo_rotate(servo_desc_t *servo, int32_t delta_us, uint32_t *pos_us){
    uint32_t tmp_pos;
    int rc;

    rc = multiservo_get_position(servo, &tmp_pos);
    if(rc){
        return rc;
    }
    tmp_pos = tmp_pos+delta_us;
    if(tmp_pos<servo->min_value){
        tmp_pos = servo->min_value;
    }
    if(tmp_pos>servo->max_value){
        tmp_pos = servo->max_value;
    }
    rc = multiservo_set_position(servo, tmp_pos);
    if(rc){
        return rc;
    }
    *pos_us = tmp_pos;
    return 0;
}
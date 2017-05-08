#ifndef CONTROL_CONTEXT_H
#define CONTROL_CONTEXT_H

#include "../../libs/microrl/microrl.h"
#include "usb_cdcacm.h"
#include "pwm_timer_servo.h"
#include "softpwm_servo.h"


#define MAX_SERVO_COUNT 18


typedef union multi_servo_u {
    servo_desc_t servo;
    pwm_timer_servo_desc_t pwm_timer;
    softpwm_servo_desc_t softpwm;
} multi_servo_t;

typedef struct servo_usb_control_context_s {

    microrl_t readline;

    usb_cdcacm_context_t usb;

    pwm_timer_desc_t timer1;
    pwm_timer_desc_t timer2;
    pwm_timer_desc_t timer3;
    pwm_timer_desc_t timer4;

    int current_interactive;

    servo_desc_t *current_servo;

    uint32_t servo_pos_min;

    uint32_t servo_pos_max;

    int servo_count;

    multi_servo_t servos[MAX_SERVO_COUNT];

    int softpwm_servo_count;
    softpwm_servo_desc_t* softpwm_servos[MAX_SERVO_COUNT];

} servo_usb_control_context_t;


void control_context_init(servo_usb_control_context_t *ctx);

void control_context_create_servos(servo_usb_control_context_t *ctx);

void control_context_start_timers(servo_usb_control_context_t *ctx);

void command_line_process_usb(usb_cdcacm_context_t *usb, int len, char *buffer);

void set_all_servos(servo_usb_control_context_t *ctx, uint32_t us_pos);

#endif
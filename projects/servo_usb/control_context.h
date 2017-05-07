#ifndef CONTROL_CONTEXT_H
#define CONTROL_CONTEXT_H

#include "../../libs/microrl/microrl.h"
#include "usb_cdcacm.h"

typedef struct servo_usb_control_context_s {

    microrl_t readline;

    usb_cdcacm_context_t usb;

    int current_interactive;

    uint32_t servo_pos_min;

    uint32_t servo_pos_max;

} servo_usb_control_context_t;


void control_context_init(servo_usb_control_context_t *ctx);

void command_line_process_usb(usb_cdcacm_context_t *usb, int len, char *buffer);

#endif
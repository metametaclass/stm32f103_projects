#include <stdio.h>

#include "../../libs/macros.h"

#include "control_context.h"
#include "../servo_pwm/servo.h"



static void process_interactive(servo_usb_control_context_t *ctx, char cmd) {
  //enum tim_oc_id channel_id;
  uint32_t real_pos = 0;

  /*switch(ch){
     case 1:
       channel_id = SERVO_CH1;
       break;
     case 2:
       channel_id = SERVO_CH2;
       break;
     default:
       printf("WARN: servo number error: %d", ch);
       return;
  }

  switch(cmd){
    case 'q':
      usb_cmd_line.current_interactive = 0;
      printf("exit interactive mode\n");
      return;
    case 'w':
      real_pos = servo_rotate_limits(channel_id, -100, servo_pos_min, servo_pos_max);
      break;
    case 's':
      real_pos = servo_rotate_limits(channel_id, 100, servo_pos_min, servo_pos_max);
      break;
    case 'd':
      real_pos = servo_rotate_limits(channel_id, -10, servo_pos_min, servo_pos_max);
      break;
    case 'a':
      real_pos = servo_rotate_limits(channel_id, 10, servo_pos_min, servo_pos_max);
      break;
    case 93:
      real_pos = servo_set_position_limits(channel_id, 1000, servo_pos_min, servo_pos_max);
      break;
    case 91:
      real_pos = servo_set_position_limits(channel_id, 2000, servo_pos_min, servo_pos_max);
      break;
    case 'c':
      real_pos = servo_set_position_limits(channel_id, SERVO_NULL, servo_pos_min, servo_pos_max);
      break;
    default:
      return;
  }
  if(real_pos!=0){
    printf("set %lu\n", real_pos);
  }*/

}



void command_line_process_usb(usb_cdcacm_context_t *usb, int len, char *buffer){
  int i;
  servo_usb_control_context_t *ctx = container_of(usb, servo_usb_control_context_t, usb);
  for(i=0;i<len;i++){
    if (ctx->current_interactive) {
      printf("%d\n", (int)buffer[i]);
      process_interactive(ctx, buffer[i]);
    } else {
      microrl_insert_char(&ctx->readline, buffer[i]);
    }
  }
}



void control_context_init(servo_usb_control_context_t *ctx){
  ctx->servo_pos_min = SERVO_MIN;
  ctx->servo_pos_max = SERVO_MAX;
}
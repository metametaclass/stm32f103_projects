#include <stdio.h>

#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "../../libs/macros.h"

#include "control_context.h"
#include "../servo_pwm/servo_constants.h"

#include "pwm_timer_servo.h"
#include "multi_servo.h"



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


void set_all_servos(servo_usb_control_context_t *ctx, uint32_t us_pos){
  int i;
  for(i=0;i<ctx->servo_count;i++){
    multiservo_set_position(&ctx->servos[i].servo, us_pos);
  }
}

void control_context_init(servo_usb_control_context_t *ctx){
  ctx->servo_pos_min = SERVO_MIN;
  ctx->servo_pos_max = SERVO_MAX;

  pwm_timer_init(&ctx->timer2, &RCC_APB1ENR, TIM2, RCC_APB1ENR_TIM2EN);
  pwm_timer_init(&ctx->timer3, &RCC_APB1ENR, TIM3, RCC_APB1ENR_TIM3EN);
  pwm_timer_init(&ctx->timer4, &RCC_APB1ENR, TIM4, RCC_APB1ENR_TIM4EN);
}




void control_context_create_servos(servo_usb_control_context_t *ctx){
    pwm_timer_servo_init(&ctx->servos[0].pwm_timer, &ctx->timer2,
        TIM_OC1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH1_ETR);//PA0

    //TODO: fix duplicate peripheral init
    pwm_timer_servo_init(&ctx->servos[1].pwm_timer, &ctx->timer2,
        TIM_OC2, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH2);//PA1

    pwm_timer_servo_init(&ctx->servos[2].pwm_timer, &ctx->timer3,
        TIM_OC1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM3_CH1);//PA6

    pwm_timer_servo_init(&ctx->servos[3].pwm_timer, &ctx->timer3,
        TIM_OC2, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH2);//PA7


    pwm_timer_servo_init(&ctx->servos[4].pwm_timer, &ctx->timer4,
        TIM_OC1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOB, GPIO_TIM4_CH1); //PB6

    pwm_timer_servo_init(&ctx->servos[5].pwm_timer, &ctx->timer4,
        TIM_OC2, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOB, GPIO_TIM4_CH2);//PB7

    ctx->servo_count = 6;
}

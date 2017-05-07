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
  uint32_t real_pos = 0;
  int rc;


  switch(cmd){
    case 'q':
      ctx->current_interactive = 0;
      ctx->current_servo = NULL;
      printf("exit interactive mode\n");
      return;
    case 'w':
      rc = multiservo_rotate(ctx->current_servo, -100, &real_pos);
      break;
    case 's':
      rc = multiservo_rotate(ctx->current_servo, 100, &real_pos);
      break;
    case 'd':
      rc = multiservo_rotate(ctx->current_servo, -10, &real_pos);
      break;
    case 'a':
      rc = multiservo_rotate(ctx->current_servo, 10, &real_pos);
      break;
    case 93:
      real_pos = 1000;
      rc = multiservo_set_position2(ctx->current_servo, &real_pos);
      break;
    case 91:
      real_pos = 2000;
      rc = multiservo_set_position2(ctx->current_servo, &real_pos);
      break;
    case 'c':
      real_pos = SERVO_NULL;
      rc = multiservo_set_position2(ctx->current_servo, &real_pos);
      break;
    default:
      return;
  }

  printf("set %lu\n rc:%d", real_pos, rc);
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


void control_context_start_timers(servo_usb_control_context_t *ctx){
  pwm_timer_start(&ctx->timer2);
  pwm_timer_start(&ctx->timer3);
  pwm_timer_start(&ctx->timer4);
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


    pwm_timer_servo_init(&ctx->servos[6].pwm_timer, &ctx->timer2,
        TIM_OC3, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH3);//PA2

    pwm_timer_servo_init(&ctx->servos[7].pwm_timer, &ctx->timer2,
        TIM_OC4, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH4);//PA3

    ctx->servo_count = SERVO_COUNT;
}

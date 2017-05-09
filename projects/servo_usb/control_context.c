#include <stdio.h>

#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>

#include "../../libs/macros.h"

#include "control_context.h"
#include "../servo_pwm/servo_constants.h"

#include "multi_servo.h"
#include "pwm_timer_servo.h"
#include "softpwm_servo.h"

#include "blink.h"





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


static servo_usb_control_context_t *global_context;//for ISR

/*
volatile uint32_t irq_counter;
volatile uint32_t led_counter;


void tim1_up_isr(void){
  if (timer_get_flag(TIM1, TIM_SR_UIF)) {
    timer_clear_flag(TIM1, TIM_SR_UIF);
    irq_counter++;
    int i;

    if(irq_counter>=SOFTPWM_PERIOD){
      irq_counter=0;

      for(i=0;i<global_context->softpwm_servo_count;i++){
        softpwm_servo_desc_t *servo = global_context->softpwm_servos[i];
        servo->shadow_value = servo->value / SOFTPWM_DIVIDER;
        gpio_set(servo->gpio_port, servo->gpio_pin);
      }

#ifdef SOFTPWM_LED_INTERVAL
      led_counter++;
      if(led_counter>SOFTPWM_LED_INTERVAL){
        led_counter = 0;
        led_toggle();
      }
#endif
      return;
    }


    for(i=0;i<global_context->softpwm_servo_count;i++){
      softpwm_servo_desc_t *servo = global_context->softpwm_servos[i];
      if(irq_counter>servo->shadow_value){
        servo->shadow_value = 0xFFFFFFFF;//mark as already set
        gpio_clear(servo->gpio_port, servo->gpio_pin);
      }
    }

  }

}
*/

static void systick_setup(void) {
  /* 72MHz / 8 => 9000000 counts per second. */
  systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);

  /* 9000000/90 = 100000 overflows per second - every 10us one interrupt */
  /* SysTick interrupt every N clock pulses: set reload to N-1 */
  systick_set_reload(89);

  systick_interrupt_enable();

  /* Start counting. */
  systick_counter_enable();
}


void sys_tick_handler(void) {
  static uint32_t irq_counter = 0;
  static uint32_t led_counter = 0;

  irq_counter++;
  int i;

  if(irq_counter>=SOFTPWM_PERIOD){
    irq_counter=0;

    for(i=0;i<global_context->softpwm_servo_count;i++){
      softpwm_servo_desc_t *servo = global_context->softpwm_servos[i];
      servo->shadow_value = servo->value / SOFTPWM_DIVIDER;
      gpio_set(servo->gpio_port, servo->gpio_pin);
    }

#ifdef SOFTPWM_LED_INTERVAL
    led_counter++;
    if(led_counter>SOFTPWM_LED_INTERVAL){
      led_counter = 0;
      led_toggle();
    }
#endif
    return;
  }

  for(i=0;i<global_context->softpwm_servo_count;i++){
    softpwm_servo_desc_t *servo = global_context->softpwm_servos[i];
    if(irq_counter>servo->shadow_value){
      servo->shadow_value = 0xFFFFFFFF;//mark as already set
      gpio_clear(servo->gpio_port, servo->gpio_pin);
    }
  }

}


/*
void tim2_isr(void){
  if (timer_get_flag(TIM2, TIM_SR_UIF)) {
    timer_clear_flag(TIM2, TIM_SR_UIF);
    irq_counter++;

    if(irq_counter>=100){
      led_toggle();
      irq_counter=0;
    }
  }
}
*/

void control_context_init(servo_usb_control_context_t *ctx){
  global_context = ctx;
  ctx->servo_pos_min = SERVO_MIN;
  ctx->servo_pos_max = SERVO_MAX;

  //softpwm
  //pwm_timer_init(&ctx->timer1, &RCC_APB2ENR, TIM1, RCC_APB2ENR_TIM1EN, SOFTPWM_PRESCALE, SOFTPWM_REPEAT);

  //timer_pwm
  pwm_timer_init(&ctx->timer2, &RCC_APB1ENR, TIM2, RCC_APB1ENR_TIM2EN, PWM_PRESCALE, PWM_PERIOD);
  pwm_timer_init(&ctx->timer3, &RCC_APB1ENR, TIM3, RCC_APB1ENR_TIM3EN, PWM_PRESCALE, PWM_PERIOD);
  pwm_timer_init(&ctx->timer4, &RCC_APB1ENR, TIM4, RCC_APB1ENR_TIM4EN, PWM_PRESCALE, PWM_PERIOD);
}


void control_context_start_timers(servo_usb_control_context_t *ctx){

  systick_setup();
  /*nvic_enable_irq(NVIC_TIM1_UP_IRQ);
  timer_enable_irq(TIM1, TIM_DIER_UIE);
  nvic_set_priority(NVIC_TIM1_UP_IRQ, 1);*/

  //timer_enable_preload_complementry_enable_bits(TIM1);
  //timer_enable_break_main_output(TIM1);


  //pwm_timer_start(&ctx->timer1);
  pwm_timer_start(&ctx->timer2);
  pwm_timer_start(&ctx->timer3);
  pwm_timer_start(&ctx->timer4);
}


static void add_timer_pwm_servo(servo_usb_control_context_t *ctx,
      pwm_timer_desc_t *timer,
      enum tim_oc_id oc_id,
      volatile uint32_t *gpio_peripheral_register,
      uint32_t gpio_periph_enable,
      uint32_t gpio_port,
      uint16_t gpio_pin){
  if(ctx->servo_count>MAX_SERVO_COUNT){
    return;
  }
  pwm_timer_servo_init(&ctx->servos[ctx->servo_count++].pwm_timer, timer,
        oc_id, gpio_peripheral_register, gpio_periph_enable, gpio_port, gpio_pin);
}



static void add_softpwm_servo(servo_usb_control_context_t *ctx,
      volatile uint32_t *gpio_peripheral_register,
      uint32_t gpio_periph_enable,
      uint32_t gpio_port,
      uint16_t gpio_pin){
  if(ctx->servo_count>MAX_SERVO_COUNT){
    return;
  }

  //pwm_timer_init_peripheral(&ctx->timer1);//init irq timer

  softpwm_servo_desc_t *softpwm_servo = &ctx->servos[ctx->servo_count++].softpwm;
  softpwm_servo_init(softpwm_servo,
        gpio_peripheral_register, gpio_periph_enable, gpio_port, gpio_pin);
  ctx->softpwm_servos[ctx->softpwm_servo_count++] = softpwm_servo;
}



void control_context_create_servos(servo_usb_control_context_t *ctx){
  //TODO: fix duplicate peripheral init

  add_timer_pwm_servo(ctx, &ctx->timer2,
        TIM_OC1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH1_ETR);//PA0

  add_timer_pwm_servo(ctx, &ctx->timer2,
        TIM_OC2, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH2);//PA1

  add_timer_pwm_servo(ctx, &ctx->timer2,
        TIM_OC3, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH3);//PA2

  add_timer_pwm_servo(ctx, &ctx->timer2,
        TIM_OC4, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH4);//PA3


  add_softpwm_servo(ctx, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO4);//PA4

  add_softpwm_servo(ctx, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO5);//PA5


  add_timer_pwm_servo(ctx, &ctx->timer3,
        TIM_OC1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM3_CH1);//PA6

  add_timer_pwm_servo(ctx, &ctx->timer3,
        TIM_OC2, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM3_CH2);//PA7


  add_timer_pwm_servo(ctx, &ctx->timer3,
        TIM_OC3, &RCC_APB2ENR, RCC_APB2ENR_IOPBEN, GPIOB, GPIO_TIM3_CH3);//PB0

  add_timer_pwm_servo(ctx, &ctx->timer3,
        TIM_OC4, &RCC_APB2ENR, RCC_APB2ENR_IOPBEN, GPIOB, GPIO_TIM3_CH4);//PB1


  add_softpwm_servo(ctx, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO8);//PA8

  add_softpwm_servo(ctx, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO9);//PA9

  add_softpwm_servo(ctx, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO10);//PA10

  //A11 used for USB

  add_softpwm_servo(ctx, &RCC_APB2ENR, RCC_APB2ENR_IOPBEN, GPIOB, GPIO5);//PB5

  add_timer_pwm_servo(ctx, &ctx->timer4,
        TIM_OC1, &RCC_APB2ENR, RCC_APB2ENR_IOPBEN, GPIOB, GPIO_TIM4_CH1);//PB6

  add_timer_pwm_servo(ctx, &ctx->timer4,
        TIM_OC2, &RCC_APB2ENR, RCC_APB2ENR_IOPBEN, GPIOB, GPIO_TIM4_CH2);//PB7


  add_timer_pwm_servo(ctx, &ctx->timer4,
        TIM_OC3, &RCC_APB2ENR, RCC_APB2ENR_IOPBEN, GPIOB, GPIO_TIM4_CH3);//PB8

  add_timer_pwm_servo(ctx, &ctx->timer4,
        TIM_OC4, &RCC_APB2ENR, RCC_APB2ENR_IOPBEN, GPIOB, GPIO_TIM4_CH4);//PB9



  /*
  timer 1 can be used for 11-channel hardware pwm, but for 18 channel timer 1
  is used for software pwm generation irq

  add_timer_pwm_servo(ctx, &ctx->timer1,
        TIM_OC1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM1_CH1);//PA8

  add_timer_pwm_servo(ctx, &ctx->timer1,
        TIM_OC2, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM1_CH2);//PA9

  add_timer_pwm_servo(ctx, &ctx->timer1,
        TIM_OC3, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM1_CH3);//PA10
 */

  //used for usb
  //add_timer_pwm_servo(ctx, &ctx->timer1,
  //      TIM_OC4, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM1_CH4);//PA11

}

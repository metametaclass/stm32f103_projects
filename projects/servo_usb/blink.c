#include "blink.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>


void tim3_isr(void)
{
  if (timer_get_flag(TIM3, TIM_SR_UIF)) {
    gpio_toggle(GPIOC, GPIO13);   // LEDon/off.
    timer_clear_flag(TIM3, TIM_SR_UIF);
  }
}


/**
 * Initialize the GPIO port for the LED at pin 13 on port C.
 */
void led_gpio_init(void)
{
     /* enable GPIOC clock */
     //rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);
     rcc_periph_clock_enable(RCC_GPIOC);
     /*
      * set GPIO13 at PORTC (led) to 'output alternate function push-pull'.
      */
     gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}

void led_toggle(void){
  gpio_toggle(GPIOC, GPIO13);   // LEDon/off.
}

static void tim3_init(void)
{

     nvic_enable_irq(NVIC_TIM3_IRQ);
     nvic_set_priority(NVIC_TIM3_IRQ, 1);

     rcc_periph_clock_enable(RCC_TIM3);

     timer_set_prescaler(TIM3, 1439);

     timer_set_period(TIM3, 25000);

      /* Update interrupt enable. */
     timer_enable_irq(TIM3, TIM_DIER_UIE);

     /* Start timer. */
     //timer_enable_counter(TIM3);

}


void blink_init(void)
{
  led_gpio_init();
  tim3_init();
}



void blink_switch(int on)
{
  //gpio_set(GPIOC, GPIO13);
  if(on){
    timer_enable_counter(TIM3);
  }else {
    timer_disable_counter(TIM3);
  }
}
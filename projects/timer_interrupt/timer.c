/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/exti.h>

static void gpio_setup(void)
{
  /* Enable GPIOC clock. */
  rcc_periph_clock_enable(RCC_GPIOC);

  /* Set GPIO13 (in GPIO port C) to 'output push-pull' for the LEDs. */
  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
          GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}

static void nvic_setup(void)
{
  /* Without this the timer interrupt routine will never be called. */
  nvic_enable_irq(NVIC_TIM2_IRQ);
  //nvic_set_priority(NVIC_TIM2_IRQ, 1);
}


static void exti_enable_request1(uint32_t extis)
{
  /* Enable interrupts. */
  EXTI_IMR |= extis;

}


static void exti_setup(void)
{
  /* Enable GPIOA clock. */
  rcc_periph_clock_enable(RCC_GPIOA);

  /* Enable AFIO clock. */
  rcc_periph_clock_enable(RCC_AFIO);

  /* Enable EXTI0 interrupt. */
  nvic_enable_irq(NVIC_EXTI9_5_IRQ);

  /* Set GPIO0 (in GPIO port A) to 'input float'. */
  gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_PULL_UPDOWN, GPIO9 | GPIO8 | GPIO7 | GPIO6 | GPIO5 );

  //pull up
  gpio_set(GPIOA, GPIO9 | GPIO8 | GPIO7 | GPIO6 | GPIO5);

  /* Configure the EXTI subsystem. */
  exti_select_source(EXTI9, GPIOA);
  exti_select_source(EXTI8, GPIOA);
  exti_select_source(EXTI7, GPIOA);
  exti_select_source(EXTI6, GPIOA);
  exti_select_source(EXTI5, GPIOA);

  exti_set_trigger(EXTI9, EXTI_TRIGGER_BOTH);
  exti_set_trigger(EXTI8, EXTI_TRIGGER_BOTH);
  exti_set_trigger(EXTI7, EXTI_TRIGGER_BOTH);
  exti_set_trigger(EXTI6, EXTI_TRIGGER_BOTH);
  exti_set_trigger(EXTI5, EXTI_TRIGGER_BOTH);

  exti_enable_request1(EXTI9);
  exti_enable_request1(EXTI8);
  exti_enable_request1(EXTI7);
  exti_enable_request1(EXTI6);
  exti_enable_request1(EXTI5);
}


void exti9_5_isr(void){

  /*
  uint16_t exti_line_state = GPIOA_IDR;

  // The LED (PC12) is on, but turns off when the button is pressed.
  if ((exti_line_state & (1 << 0)) != 0) {
    timer_set_period(TIM2, 25000);
  } else {
    timer_set_period(TIM2, 6250);
  }
  exti_reset_request(EXTI0);*/

  if(exti_get_flag_status(EXTI5)){
    timer_set_period(TIM2, 2000);
    exti_reset_request(EXTI5);
  }

  if(exti_get_flag_status(EXTI6)){
    timer_set_period(TIM2, 4000);
    exti_reset_request(EXTI6);
  }

  if(exti_get_flag_status(EXTI7)){
    timer_set_period(TIM2, 8000);
    exti_reset_request(EXTI7);
  }

  if(exti_get_flag_status(EXTI8)){
    timer_set_period(TIM2, 16000);
    exti_reset_request(EXTI8);
  }

  if(exti_get_flag_status(EXTI9)){
    timer_set_period(TIM2, 32000);
    exti_reset_request(EXTI9);
  }
}



void tim2_isr(void)
{

  //pull request, which removes R-M-W from timer_clear_flag (all bits are rw_c0)
  //https://github.com/libopencm3/libopencm3/issues/392
  //https://github.com/libopencm3/libopencm3/pull/492
  //https://github.com/libopencm3/libopencm3/pull/492/commits/c7fcba49f4365ac190351ebc3813a6df635c1019z
  //timer_clear_flag  ->  TIM_SR(timer_peripheral) = ~flag;
  //but R-M-W actually needed when led toggled first?


  //original version - R-M-W
  //works, order doesn`t matter
  //gpio_toggle(GPIOC, GPIO13);   // LEDon/off.
  //TIM_SR(TIM2) &= ~TIM_SR_UIF; /* Clear interrupt flag. */


  //clear without check, clear first
  //works
  //timer_clear_flag(TIM2, TIM_SR_UIF);
  //gpio_toggle(GPIOC, GPIO13);   // LEDon/off.


  //clear without check, LED first
  //doesn`t work (!)
  //if call to timer_clear_flag removed, then blinks one time
  //gpio_toggle(GPIOC, GPIO13);   // LEDon/off.
  //timer_clear_flag(TIM2, TIM_SR_UIF);


  //paranoid version from timer_clear_flag above, clear first
  //works, order doesn`t matter
  //gpio_toggle(GPIOC, GPIO13);   // LEDon/off.
  //TIM_SR(TIM2) = ~TIM_SR_UIF | (TIM_SR(TIM2) & 0xffffe0c0);

  //copy of non-paranoid timer_clear_flag
  //works, order doesn`t matter
  //gpio_toggle(GPIOC, GPIO13);   // LEDon/off.
  //TIM_SR(TIM2) = ~TIM_SR_UIF;


  //check and clear
  //works, order doesn`t matter
  if (timer_get_flag(TIM2, TIM_SR_UIF)) {
    gpio_toggle(GPIOC, GPIO13);   // LEDon/off.
    timer_clear_flag(TIM2, TIM_SR_UIF);
  }
}

int main(void)
{
  rcc_clock_setup_in_hse_8mhz_out_72mhz();

  gpio_setup();

  nvic_setup();

  exti_setup();

  gpio_set(GPIOC, GPIO13); /* LED off */

  rcc_periph_clock_enable(RCC_TIM2);

  /*
   * The goal is to let the LED2 glow for a second and then be
   * off for a second.
   */

  /* Set timer start value. */
  //timer_set_counter(TIM2, 1);
  //TIM_CNT(TIM2) = 1;

  /* Set timer prescaler. 72MHz/1440 => 50000 counts per second. */
  //TIM_PSC(TIM2) = 1440;
  timer_set_prescaler(TIM2, 1439);

  /* End timer value. If this is reached an interrupt is generated. */
  //TIM_ARR(TIM2) = 50000;
  timer_set_period(TIM2, 25000);

  /* Update interrupt enable. */
  //TIM_DIER(TIM2) |= TIM_DIER_UIE;
  timer_enable_irq(TIM2, TIM_DIER_UIE);

  /* Start timer. */
  //TIM_CR1(TIM2) |= TIM_CR1_CEN;
  timer_enable_counter(TIM2);

  while (1); /* Halt. */

  return 0;
}

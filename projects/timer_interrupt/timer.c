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

static void gpio_setup(void)
{
  /* Enable GPIOB clock. */
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

void tim2_isr(void)
{

  //original version - R-M-W working 
  //TIM_SR(TIM2) &= ~TIM_SR_UIF; /* Clear interrupt flag. */

  //clear without check - doesn`t working
  //timer_clear_flag(TIM2, TIM_SR_UIF);

  //pull request, which removes R-M-W from timer_clear_flag (all bits are rw_c0)
  //https://github.com/libopencm3/libopencm3/issues/392
  //https://github.com/libopencm3/libopencm3/pull/492
  //https://github.com/libopencm3/libopencm3/pull/492/commits/c7fcba49f4365ac190351ebc3813a6df635c1019z
  //timer_clear_flag ->  TIM_SR(timer_peripheral) = ~flag;

  //but R-M-W actually needed, interrupt flag should be checked before clearing ?

  if (timer_get_flag(TIM2, TIM_SR_UIF)) {
    timer_clear_flag(TIM2, TIM_SR_UIF);

    gpio_toggle(GPIOC, GPIO13);   /* LED2 on/off. */
    
  }
}

int main(void)
{
  rcc_clock_setup_in_hse_8mhz_out_72mhz();
  gpio_setup();
  nvic_setup();

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

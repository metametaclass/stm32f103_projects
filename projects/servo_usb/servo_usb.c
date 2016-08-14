/*
 * This file is part of the PWM-Servo example.
 *
 * Copyright (C) 2011 Stefan Wendler <sw@kaltpost.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>

#include "../servo_pwm/servo.h"
#include "usb_cdcacm.h"

/**
 * Setup the system clock to 72MHz.
 */
static void clock_init(void)
{
     rcc_clock_setup_in_hse_8mhz_out_72mhz();
}

/**
 * Initialize the GPIO port for the LED at pin 13 on port C.
 */
static void gpio_init(void)
{
     /* enable GPIOC clock */
     //rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);
     rcc_periph_clock_enable(RCC_GPIOC);
     /*
      * set GPIO13 at PORTC (led) to 'output alternate function push-pull'.
      */
     gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}

/**
 * Delay by executing some "nop"s.
 *
 * @param[in] d number of "nop"s to performe.
 */
static void delay(int d)
{

     int i;

     for(i = 0; i < d; i++) {
          __asm("nop");
     }
}

static void set_servos(uint32_t pos1_us, uint32_t pos2_us)
{
     gpio_toggle(GPIOC, GPIO13); /* LED on/off */   
     servo_set_position(SERVO_CH1, pos1_us);
     servo_set_position(SERVO_CH2, pos2_us);
     //delay(45000000);
}


void tim3_isr(void)
{
  if (timer_get_flag(TIM3, TIM_SR_UIF)) {
    gpio_toggle(GPIOC, GPIO13);   // LEDon/off.    
    timer_clear_flag(TIM3, TIM_SR_UIF);
  }
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
     timer_enable_counter(TIM3);

}


int main(void)
{
     int i;
     //usbd_device* usbd_dev;

     clock_init();
     gpio_init();
     servo_init();

     //init timer 3 interrupts
     tim3_init(); 


     //gpio_set(GPIOC, GPIO13);
     //delay(1500000);
     //gpio_clear(GPIOC, GPIO13);  
     /*
     for(i=0;i<50;i++){
       gpio_toggle(GPIOC, GPIO13); // LED on/off 
       delay(1500000);
     }*/



     set_servos(SERVO_NULL, SERVO_NULL);

     init_usb_cdcacm();

     gpio_clear(GPIOC, GPIO13);
     for (i = 0; i < 0x800000; i++)
       __asm__("nop");
     gpio_set(GPIOC, GPIO13);  

     usb_poll_loop();

     /*
     // let pan-til "look around a little"
     while(1) {
          set_servos(SERVO_MIN, SERVO_MAX);

          set_servos(SERVO_NULL, SERVO_NULL);

          set_servos(SERVO_MAX, SERVO_MIN);

          set_servos(SERVO_NULL, SERVO_NULL);

          set_servos(SERVO_MIN, SERVO_MIN);

          set_servos(SERVO_MAX, SERVO_MAX);

          set_servos(SERVO_NULL, SERVO_NULL);

          set_servos(SERVO_MIN, SERVO_NULL);

          set_servos(SERVO_MAX, SERVO_NULL);

          set_servos(SERVO_NULL, SERVO_NULL);

          set_servos(SERVO_NULL, SERVO_MIN);

          set_servos(SERVO_NULL, SERVO_MAX);

          set_servos(SERVO_NULL, SERVO_NULL);

     }
     */

     return 0;
}

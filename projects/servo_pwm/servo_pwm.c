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

#include "servo.h"

/**
 * Setup the system clock to 72MHz.
 */
static void clock_init(void)
{
     rcc_clock_setup_in_hse_8mhz_out_72mhz();
}

/**
 * Initialize the GPIO port for the LED at pin 12 on port C.
 */
static void gpio_init(void)
{
     /* enable GPIOC clock */
     rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);

     /*
      * set GPIO12 at PORTC (led) to 'output alternate function push-pull'.
      */
     gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
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
     delay(45000000);
}

int main(void)
{
     int i;
     clock_init();
     gpio_init();
     servo_init();

     //gpio_set(GPIOC, GPIO13);

     for(i=0;i<100;i++){
       gpio_toggle(GPIOC, GPIO13); /* LED on/off */   
       delay(1500000);
     }

     gpio_clear(GPIOC, GPIO13);  

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

     return 0;
}

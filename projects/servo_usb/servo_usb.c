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

#include "../servo_pwm/servo.h"
#include "blink.h"
#include "usb_cdcacm.h"

/**
 * Setup the system clock to 72MHz.
 */
static void clock_init(void)
{
     rcc_clock_setup_in_hse_8mhz_out_72mhz();
}



static void set_servos(uint32_t pos1_us, uint32_t pos2_us)
{
     gpio_toggle(GPIOC, GPIO13); /* LED on/off */   
     servo_set_position(SERVO_CH1, pos1_us);
     servo_set_position(SERVO_CH2, pos2_us);
     //delay(45000000);
}



int main(void)
{

     clock_init();

     servo_init();

     //init timer 3 interrupts
     blink_init(); 

     set_servos(SERVO_NULL, SERVO_NULL);

     init_usb_cdcacm();

     gpio_clear(GPIOC, GPIO13);
     delay(0x800000);
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

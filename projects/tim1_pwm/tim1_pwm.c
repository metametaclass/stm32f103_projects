
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "../servo_pwm/pwm.h"
#include "../servo_pwm/servo_constants.h"

static void clock_init(void)
{
     rcc_clock_setup_in_hse_8mhz_out_72mhz();
}

static void gpio_init(void)
{
     /* enable GPIOC clock */
     rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);

     /*
      * set GPIO12 at PORTC (led) to 'output alternate function push-pull'.
      */
     gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}


static void servo_init(void){
     /* init timer1 with a period of 20ms */
     pwm_init_timer(&RCC_APB2ENR, RCC_APB2ENR_TIM1EN, TIM1, PWM_PRESCALE, PWM_PERIOD);
     pwm_init_timer(&RCC_APB1ENR, RCC_APB1ENR_TIM2EN, TIM2, PWM_PRESCALE, PWM_PERIOD);

     /* init output of channel2 of timer1 */
     pwm_init_output_channel(TIM1, TIM_OC1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM1_CH1);
     pwm_init_output_channel(TIM1, TIM_OC2, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM1_CH2);

     /* init output of channel2 of timer1 */
     pwm_init_output_channel(TIM2, TIM_OC1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH1_ETR);
     pwm_init_output_channel(TIM2, TIM_OC2, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH2);

     pwm_set_pulse_width(TIM1, TIM_OC1, SERVO_NULL);
     pwm_set_pulse_width(TIM1, TIM_OC2, SERVO_NULL);
     pwm_set_pulse_width(TIM2, TIM_OC1, 950);
     pwm_set_pulse_width(TIM2, TIM_OC2, 1050);

     /* start timer1 */
     timer_enable_preload_complementry_enable_bits(TIM1);

     timer_enable_break_main_output(TIM1);

     pwm_start_timer(TIM1);

     pwm_start_timer(TIM2);
}



static void delay(int d)
{

     int i;

     for(i = 0; i < d; i++) {
          __asm("nop");
     }
}





int main(void)
{
     int i;
     clock_init();
     gpio_init();
     servo_init();

     //gpio_set(GPIOC, GPIO13);

     for(i=0;i<10;i++){
       gpio_toggle(GPIOC, GPIO13); /* LED on/off */
       delay(1500000);
     }

     gpio_clear(GPIOC, GPIO13);


     return 0;
}

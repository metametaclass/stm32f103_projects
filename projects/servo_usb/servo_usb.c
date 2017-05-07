#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "../../libs/macros.h"
#include "../../libs/utils.h"

//#include "../servo_pwm/servo.h"
#include "blink.h"


#include "usb_cdcacm.h"
#include "command_line.h"
#include "control_context.h"


/**
 * Setup the system clock to 72MHz.
 */
static void clock_init(void) {
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
}



/*static void set_servos(uint32_t pos1_us, uint32_t pos2_us) {
    gpio_toggle(GPIOC, GPIO13); //LED on/off
    servo_set_position(SERVO_CH1, pos1_us);
    servo_set_position(SERVO_CH2, pos2_us);
}*/


static void usb_print_callback(microrl_t *this, const char * str){
    servo_usb_control_context_t *ctx = container_of(this, servo_usb_control_context_t, readline);
    usb_prints(&ctx->usb, str);
}



int main(void) {

    clock_init();

    //init led blink
    blink_init();

    servo_usb_control_context_t ctrl_context = {{0},{0},0,0,0};

    control_context_init(&ctrl_context);

    //servo_init();
    //set_servos(SERVO_NULL, SERVO_NULL);

    command_line_init(&ctrl_context.readline, usb_print_callback);

    usb_cdcacm_init(&ctrl_context.usb, command_line_process_usb);

    gpio_clear(GPIOC, GPIO13);
    delay(0x800000);
    gpio_set(GPIOC, GPIO13);

    usb_cdcacm_poll_loop(&ctrl_context.usb);


    return 0;
}

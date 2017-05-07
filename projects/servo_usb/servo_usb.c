#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <string.h>

#include "../../libs/macros.h"
#include "../../libs/utils.h"

#include "../servo_pwm/servo_constants.h"
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



static void usb_print_callback(microrl_t *this, const char * str){
    servo_usb_control_context_t *ctx = container_of(this, servo_usb_control_context_t, readline);
    usb_prints(&ctx->usb, str);
}



int main(void) {

    clock_init();

    //init led blink
    led_gpio_init();
    //blink_init();

    servo_usb_control_context_t ctrl_context;
    memset(&ctrl_context, 0, sizeof(ctrl_context));

    control_context_init(&ctrl_context);

    control_context_create_servos(&ctrl_context);

    set_all_servos(&ctrl_context, SERVO_NULL);

    control_context_start_timers(&ctrl_context);

    command_line_init(&ctrl_context.readline, usb_print_callback);

    usb_cdcacm_init(&ctrl_context.usb, command_line_process_usb);

    gpio_clear(GPIOC, GPIO13);
    delay(0x800000);
    gpio_set(GPIOC, GPIO13);

    usb_cdcacm_poll_loop(&ctrl_context.usb);
    //while(1);


    return 0;
}

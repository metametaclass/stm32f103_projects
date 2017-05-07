#include <string.h>
#include <stdio.h>

#include "../../libs/macros.h"
#include "../../libs/utils.h"

#include "command_line.h"
#include "control_context.h"
#include "blink.h"

static void CLI_blink_switch(servo_usb_control_context_t *ctx, int on){
  (void) ctx;
  blink_switch(on);
}


//set limits for servo
static void cli_LIMITS(servo_usb_control_context_t *ctx, int p1, int p2) {
  char out[80];

  if (p1<500 || p1>1000)  {
    printf(out, "ERROR: invalid low limit %d. min:%lu max:%lu\n",
      p1, ctx->servo_pos_min, ctx->servo_pos_max);
    //print(out);
    return;
  }
  if (p2<2000 || p2>2500)  {
    printf(out, "ERROR: invalid high limit %d. min:%lu max:%lu\n",
      p2, ctx->servo_pos_min, ctx->servo_pos_max);
    //print(out);
    return;
  }

  ctx->servo_pos_min = p1;
  ctx->servo_pos_max = p2;

  printf(out, "min:%lu max:%lu\n", ctx->servo_pos_min, ctx->servo_pos_max);
  //print(out);
}


static void cli_DUMP(servo_usb_control_context_t *ctx) {
  char out[80];
  uint32_t pos_ch1 = 0;//servo_get_position(SERVO_CH1);
  uint32_t pos_ch2 = 0;//servo_get_position(SERVO_CH2);

  printf(out, "ch1:%lu  ch2: %lu min:%lu max:%lu\n",
    pos_ch1, pos_ch2, ctx->servo_pos_min, ctx->servo_pos_max);
  //print(out);
}


//set servo position
static void cli_SET(servo_usb_control_context_t *ctx, int p1, int p2) {
  (void) ctx;
  char out[80];
  uint32_t real_pos = 0;
  /*outlen = */printf(out, "servo:%d value:%d\n", p1, p2);
  //print(out);

  switch(p1){
     case 1:
       //real_pos = servo_set_position_limits(SERVO_CH1, p2, servo_pos_min, servo_pos_max);
       break;
     case 2:
       //real_pos = servo_set_position_limits(SERVO_CH2, p2, servo_pos_min, servo_pos_max);
       break;
     default:
       /*outlen = */printf(out, "WARN: servo number error. servo:%d value:%d\n", p1, p2);
       //print(out);
       break;
  }
  if(real_pos!=0){
    printf(out, "set %lu\n", real_pos);
    //print(out);
  }
}


static void cli_ROTATE(servo_usb_control_context_t *ctx, int p1, int p2) {
  (void) ctx;
  char out[80];
  uint32_t real_pos = 0;
  printf(out, "rotate servo:%d angle(ms):%d\n", p1, p2);
  //print(out);

  switch(p1){
     case 1:
       //real_pos = servo_rotate_limits(SERVO_CH1, p2, servo_pos_min, servo_pos_max);
       break;
     case 2:
       //real_pos = servo_rotate_limits(SERVO_CH2, p2, servo_pos_min, servo_pos_max);
       break;
     default:
       printf("WARN: servo number error: %d", p1);
       //print(out);
       break;
  }
  if(real_pos!=0){
    printf(out, "position %lu\n", real_pos);
    //print(out);
  }
}

static void cli_INTERACTIVE(servo_usb_control_context_t *ctx, int p1) {
  if(p1>=1 && p1<=2) {
    printf("enter interactive mode ch:%d\n", p1);
    ctx->current_interactive = p1;
  }
}




#include "ragel/servo_command_line.inc"



static void execute_cmd_line(microrl_t *prl, int argc, const char * const * argv) {
  servo_usb_control_context_t *ctx = container_of(prl, servo_usb_control_context_t, readline);

  (void) argc;
  (void) argv;
  int i;
  //gpio_toggle(GPIOC, GPIO13);
  for(i=0;i<argc;i++){
    if(argv[i]) {
      parse_stdin_command(ctx, argv[i], strlen(argv[i]));
    }
  }
}



void command_line_init(microrl_t *prl, print_t print){
  microrl_init (prl, print);
  microrl_set_execute_callback (prl, execute_cmd_line);
}
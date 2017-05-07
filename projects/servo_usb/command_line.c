#include <string.h>
#include <stdio.h>

#include "../../libs/macros.h"
#include "../../libs/utils.h"

#include "command_line.h"
#include "control_context.h"
#include "blink.h"

#include "multi_servo.h"

static void CLI_blink_switch(servo_usb_control_context_t *ctx, int on){
  (void) ctx;
  blink_switch(on);
}


//set limits for servo
static void cli_LIMITS(servo_usb_control_context_t *ctx, int p1, int p2) {
  //char out[80];

  if (p1<500 || p1>1000)  {
    printf("ERROR: invalid low limit %d. min:%lu max:%lu\n",
      p1, ctx->servo_pos_min, ctx->servo_pos_max);
    //print(out);
    return;
  }
  if (p2<2000 || p2>2500)  {
    printf("ERROR: invalid high limit %d. min:%lu max:%lu\n",
      p2, ctx->servo_pos_min, ctx->servo_pos_max);
    //print(out);
    return;
  }

  ctx->servo_pos_min = p1;
  ctx->servo_pos_max = p2;

  printf("min:%lu max:%lu\n", ctx->servo_pos_min, ctx->servo_pos_max);
  //print(out);
}


static void cli_DUMP(servo_usb_control_context_t *ctx) {
  //char out[80];
  int i;
  uint32_t us_pos;
  for(i=0;i<ctx->servo_count;i++){
    int rc = multiservo_get_position(&ctx->servos[i].servo, &us_pos);
    printf("get ch:%d pos:%lu rc:%d\n", i, us_pos, rc);
    delay(10000);
  }
}


//set servo position
static void cli_SET(servo_usb_control_context_t *ctx, int p1, int p2) {
  //char out[80];
  uint32_t us_pos = (uint32_t)p2;
  /*outlen = */printf("servo:%d value:%lu\n", p1, us_pos);
  //print(out);

  if (p1<0 || p1>=ctx->servo_count) {
    printf("invalid servo num %d\n", p1);
    return;
  }
  if(us_pos<ctx->servo_pos_min) {
    printf("position %lu less than min %lu\n", us_pos, ctx->servo_pos_min);
    us_pos = ctx->servo_pos_min;
  }
  if(us_pos>ctx->servo_pos_max) {
    printf("position %lu greater than max %lu\n", us_pos, ctx->servo_pos_max);
    us_pos = ctx->servo_pos_max;
  }
  int rc = multiservo_set_position(&ctx->servos[p1].servo, us_pos);
  printf("set ch:%d pos:%lu rc:%d\n", p1, us_pos, rc);
}


static void cli_ROTATE(servo_usb_control_context_t *ctx, int p1, int p2) {
  (void) ctx;
  //char out[80];
  uint32_t real_pos = 0;
  printf("rotate servo:%d angle(ms):%d\n", p1, p2);
  //print(out);

  switch(p1){
     case 1:
       //real_pos = servo_rotate_limits(SERVO_CH1, p2, servo_pos_min, servo_pos_max);
       break;
     case 2:
       //real_pos = servo_rotate_limits(SERVO_CH2, p2, servo_pos_min, servo_pos_max);
       break;
     default:
       printf("WARN: servo number error: %d\n", p1);
       //print(out);
       break;
  }
  if(real_pos!=0){
    printf("position %lu\n", real_pos);
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
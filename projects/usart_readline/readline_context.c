#include <stdio.h>

#include "../../libs/macros.h"
#include "readline_context.h"


static void execute_cmd_line(microrl_t *prl, int argc, const char * const * argv) {
  (void) prl;
  //readline_context_t *ctx = container_of(prl, readline_context_t, readline);

  int i;
  for(i=0;i<argc;i++){
    if(argv[i]) {
      printf("%s\r\n", argv[i]);
      //parse_stdin_command(ctx, argv[i], strlen(argv[i]));
    }
  }
}


void readline_context_init(readline_context_t *ctx, print_t print){
  microrl_init(&ctx->readline, print);
  microrl_set_execute_callback(&ctx->readline, execute_cmd_line);
}
#ifdef TEST_RAGEL_PARSER

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#endif

#define MAX_CALL_PARAMS 3

%%{
    machine servo_command_line;
    write data;
}%%

#ifdef TEST_RAGEL_PARSER

static void for_debug(void)
{
  printf("for_debug\n");
}

static int parse_stdin_command(const char *data, int length)
#else
static int parse_stdin_command(servo_usb_control_context_t *ctx, const char *data, int length) 
#endif
{

    //int rc;
    const char *p = data, *pe = data + length;
    const char *eof = pe;    
    const char *start = data;

    int tmp;
    int sign = 1;
   
    int params[MAX_CALL_PARAMS] = {0};
    int param_num = 0;

    int cs;

    %%{

        action begin_literal { 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", fpc-data); 
#else
#endif
            start = fpc;
            //sign = 1;
        }

        action start { 
#ifdef TEST_RAGEL_PARSER
            printf("start: %ld\n", fpc-data); 
#else
#endif
            start = fpc;
        }


        action end_literal { 
#ifdef TEST_RAGEL_PARSER
            printf(">>end_literal: %ld \"%.*s\"\n", fpc-data, (int)(fpc-start), start); 
#else
#endif
        }      

        action signed {
#ifdef TEST_RAGEL_PARSER
            printf(">>signed: %ld \"%.*s\"\n", fpc-data, (int)(fpc-start), start); 
#else
#endif
            sign = -1;
        }

        action reset_sign {
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", fpc-data, (int)(fpc-start), start); 
#else
#endif
            sign = 1;
        }


        action end_numeric { 
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %ld \"%.*s\"\n", fpc-data, (int)(fpc-start), start); 
            for_debug(); 
#endif
            tmp = 0;
            while(start<fpc){
               tmp = tmp*10 + (*start - '0');
               start++;
            }
            if(param_num<MAX_CALL_PARAMS){
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }


        action error { 
#ifdef TEST_RAGEL_PARSER
            printf("error at %d \"%s\"\n", (int)(fpc-start), fpc); 
#endif
            //return -1;
        }

        action on_eof { 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(fpc-start));
#endif
        }

        action set { 
#ifdef TEST_RAGEL_PARSER
            printf("SET %d %d\n", params[0], params[1]);
#else
            
            cli_SET(ctx, params[0], params[1]);
            
#endif
        }

        action dump { 
#ifdef TEST_RAGEL_PARSER
            printf("DUMP\n");
#else
            
            cli_DUMP(ctx);            
#endif
        }

        action limits { 
#ifdef TEST_RAGEL_PARSER
            printf("LIMITS %d %d\n", params[0], params[1]);
#else
            
            cli_LIMITS(ctx, params[0], params[1]);
#endif
        }

        action rotate { 
#ifdef TEST_RAGEL_PARSER
            printf("ROTATE %d %d\n", params[0], params[1]);
#else            
            cli_ROTATE(ctx, params[0], params[1]);
#endif
        }

        action delay { 
#ifdef TEST_RAGEL_PARSER
            printf("DELAY %d\n", params[0]);
#else            
            delay(params[0]);
#endif
        }


        action interact { 
#ifdef TEST_RAGEL_PARSER
            printf("INTERACTIVE %d\n", params[0]);
#else            
            cli_INTERACTIVE(ctx, params[0]);
#endif
        }


        action unknown_command { 
            if(start<fpc){
#ifdef TEST_RAGEL_PARSER
            printf("unknown_command at %d %s\n", (int)(fpc-start), fpc); 
#else            
            printf("unknown_command\n");
#endif
            }
        }

        action comment { 
#ifdef TEST_RAGEL_PARSER
            printf("COMMENT\n");
#else            
#endif
        }


        action blink_on { 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_ON\n");
#else
            printf("blink_on");
            CLI_blink_switch(ctx, 1);
#endif
        }

        action blink_off { 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_OFF\n");
#else
            printf("blink_off");
            CLI_blink_switch(ctx, 0);
#endif
        }


        str_literal = '"' ((any - '"')** >begin_literal %end_literal)  '"' ;
        param = space* str_literal space* ;

        param_numeric = space* ( (('-' @signed)? >reset_sign) digit+ >begin_literal %end_numeric) space* ; 

        # | ( (any*) %unknown_command )

        main := (( ("set"  space* '(' param_numeric ',' param_numeric ')') %set space* )  | 
                 ( ("rotate"  space* '(' param_numeric ',' param_numeric ')') %rotate space* ) |
                 ( "bon" %blink_on space*  )  | 
                 ( "boff" %blink_off space*  )  | 
                 ( ("interact"  '(' param_numeric ')') %interact space* )  |  
                 ( ("delay" space* '(' param_numeric ')')  %delay space* )  | 
                 ( ("limits"  space* '(' param_numeric ',' param_numeric ')' ) %limits space* ) |
                 ( "dump"  %dump space* )  | 
                 ( ( "//" any*) %comment)                 
                ) $err(error) $eof(on_eof);
                      
        # Initialize and execute.
        write init;
        write exec;
    }%%

#ifdef TEST_RAGEL_PARSER
    printf("cs: %d\n", cs);
#endif

    if(cs==servo_command_line_error){
       printf("error\n");
       return -1;
    }

    if(cs>=servo_command_line_first_final){
#ifdef TEST_RAGEL_PARSER
       printf("ok\n");
#endif

       return 0;
    }
    printf("unknown command");


    return -2;
};


#ifdef TEST_RAGEL_PARSER


#define BUFSIZE 1024

int main()
{
    int rc;
    int is_quit=0;
    char buf[BUFSIZE];

    //rc = parse_stdin_command("quit\r\n", &is_quit);

    while ( fgets( buf, sizeof(buf), stdin ) != 0 ) {
        printf( "buf:%s", buf);
        rc = parse_stdin_command(buf, strlen(buf));
        printf( "rc:%d\n\n", rc );
        if(is_quit){
           break;
        }
    }
    return 0;
}

#endif
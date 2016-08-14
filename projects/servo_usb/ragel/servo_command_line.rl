#ifdef TEST_RAGEL_PARSER

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#endif


%%{
    machine servo_command_line;
    write data;
}%%

#ifdef TEST_RAGEL_PARSER
static int parse_stdin_command(const char *data, int length)
#else
static int parse_stdin_command(const char *data, int length) 
#endif
{

    //int rc;
    const char *p = data, *pe = data + length;
    const char *eof = pe;    
    const char *start = data;

    int p1 = 0;
#ifdef TEST_RAGEL_PARSER
    int p2 = 0;
#else
    int p2 = SERVO_NULL;
#endif
    //int outlen;
    char out[80];


    int cs;

    %%{

        action begin_literal { 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", fpc-data); 
#else
#endif
            start = fpc;
        }


        action end_literal { 
#ifdef TEST_RAGEL_PARSER
            printf(">>end_literal: %ld \"%.*s\"\n", fpc-data, (int)(fpc-start), start); 
#else
            //TODO: atoi with length!
#endif
        }


        action error { 
#ifndef TEST_RAGEL_PARSER
            printf("error at %d %s\n", (int)(fpc-start), fpc); 
#endif
            return 0;
        }

        action on_eof { 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(fpc-start));
#endif
        }

        action set { 
#ifdef TEST_RAGEL_PARSER
            printf("SET\n");
#else
            
            /*outlen = */sprintf(out, "servo:%d value:%d\n", p1, p2);
            print(out);
            //while (usbd_ep_write_packet(usbd_dev, 0x82, out, outlen) == 0);

            switch(p1){
               case 1:
                 servo_set_position(SERVO_CH1, p2); 
                 break;
               case 2:
                 servo_set_position(SERVO_CH2, p2); 
                 break;
               default:
                  
                 /*outlen = */sprintf(out, "WARN: servo number error. servo:%d value:%d\n", p1, p2);
                 print(out); 
                 //while (usbd_ep_write_packet(usbd_dev, 0x82, out, outlen) == 0);
                 break;
            }
            
#endif
        }

        action blink_on { 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_ON\n");
#else
            print("blink_on");
            blink_switch(1);
#endif
        }

        action blink_off { 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_OFF\n");
#else
            print("blink_off");
            blink_switch(0);
#endif
        }


        str_literal = '"' ((any - '"')** >begin_literal %end_literal)  '"' ;
        param = space* str_literal space* ;

        param_numeric = space* (digit+ >begin_literal %end_literal) space* ; 


        main := (( "set"  space* '(' param_numeric ',' param_numeric ')' @set space* )  | 
                 ( "bon"  @blink_on space* )  | 
                 ( "boff"  @blink_off space* )  | 
                 ( "//" any*)                 
                ) $err(error) $eof(on_eof);
                      
        # Initialize and execute.
        write init;
        write exec;
    }%%

    return 0;
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
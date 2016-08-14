
/* #line 1 "servo_command_line.rl" */
#ifdef TEST_RAGEL_PARSER

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#endif

#define MAX_CALL_PARAMS 3


/* #line 15 "servo_command_line.inc" */
static const int servo_command_line_start = 1;
static const int servo_command_line_first_final = 15;
static const int servo_command_line_error = 0;

static const int servo_command_line_en_main = 1;


/* #line 14 "servo_command_line.rl" */


#ifdef TEST_RAGEL_PARSER

static void for_debug(void)
{
  printf("for_debug\n");
}

static int parse_stdin_command(const char *data, int length)
#else
static int parse_stdin_command(const char *data, int length) 
#endif
{

    //int rc;
    const char *p = data, *pe = data + length;
    const char *eof = pe;    
    const char *start = data;

    int tmp;
   
    int params[MAX_CALL_PARAMS] = {0};
    int param_num = 0;

    int cs;

    
/* #line 52 "servo_command_line.inc" */
	{
	cs = servo_command_line_start;
	}

/* #line 57 "servo_command_line.inc" */
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 47: goto st2;
		case 98: goto st3;
		case 115: goto st6;
	}
	goto tr0;
tr0:
/* #line 79 "servo_command_line.rl" */
	{ 
#ifndef TEST_RAGEL_PARSER
            printf("error at %d %s\n", (int)(p-start), p); 
#endif
            return 0;
        }
	goto st0;
/* #line 79 "servo_command_line.inc" */
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 47 )
		goto st15;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	goto st15;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 111 )
		goto st4;
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	switch( (*p) ) {
		case 102: goto st5;
		case 110: goto tr7;
	}
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 102 )
		goto tr8;
	goto tr0;
tr7:
/* #line 102 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_ON\n");
#else
            print("blink_on");
            blink_switch(1);
#endif
        }
	goto st16;
tr8:
/* #line 111 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_OFF\n");
#else
            print("blink_off");
            blink_switch(0);
#endif
        }
	goto st16;
tr20:
/* #line 58 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
            for_debug(); 
#endif
            tmp = 0;
            while(start<p){
               tmp = tmp*10 + (*start - '0');
               start++;
            }
            if(param_num<MAX_CALL_PARAMS){
               params[param_num] = tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
/* #line 92 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("SET\n");
#else
            
            cli_SET(params[0], params[1]);
            
#endif
        }
	goto st16;
tr23:
/* #line 92 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("SET\n");
#else
            
            cli_SET(params[0], params[1]);
            
#endif
        }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
/* #line 188 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto st16;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st16;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 101 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 116 )
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	switch( (*p) ) {
		case 32: goto st8;
		case 40: goto st9;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st8;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 32 )
		goto st9;
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr12;
	} else if ( (*p) >= 9 )
		goto st9;
	goto tr0;
tr12:
/* #line 43 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
        }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
/* #line 245 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr13;
		case 44: goto tr14;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st10;
	} else if ( (*p) >= 9 )
		goto tr13;
	goto tr0;
tr13:
/* #line 58 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
            for_debug(); 
#endif
            tmp = 0;
            while(start<p){
               tmp = tmp*10 + (*start - '0');
               start++;
            }
            if(param_num<MAX_CALL_PARAMS){
               params[param_num] = tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
/* #line 282 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st11;
		case 44: goto st12;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st11;
	goto tr0;
tr14:
/* #line 58 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
            for_debug(); 
#endif
            tmp = 0;
            while(start<p){
               tmp = tmp*10 + (*start - '0');
               start++;
            }
            if(param_num<MAX_CALL_PARAMS){
               params[param_num] = tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
/* #line 316 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto st12;
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr18;
	} else if ( (*p) >= 9 )
		goto st12;
	goto tr0;
tr18:
/* #line 43 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
        }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
/* #line 339 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr19;
		case 41: goto tr20;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st13;
	} else if ( (*p) >= 9 )
		goto tr19;
	goto tr0;
tr19:
/* #line 58 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
            for_debug(); 
#endif
            tmp = 0;
            while(start<p){
               tmp = tmp*10 + (*start - '0');
               start++;
            }
            if(param_num<MAX_CALL_PARAMS){
               params[param_num] = tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
/* #line 376 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st14;
		case 41: goto tr23;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st14;
	goto tr0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 15: 
	case 16: 
/* #line 86 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
/* #line 79 "servo_command_line.rl" */
	{ 
#ifndef TEST_RAGEL_PARSER
            printf("error at %d %s\n", (int)(p-start), p); 
#endif
            return 0;
        }
/* #line 86 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
/* #line 442 "servo_command_line.inc" */
	}
	}

	_out: {}
	}

/* #line 136 "servo_command_line.rl" */


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
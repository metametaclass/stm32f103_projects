
/* #line 1 "servo_command_line.rl" */
#ifdef TEST_RAGEL_PARSER

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#endif

#define MAX_CALL_PARAMS 3


/* #line 15 "servo_command_line.inc" */
static const int servo_command_line_start = 1;
static const int servo_command_line_first_final = 56;
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
    int sign = 1;
   
    int params[MAX_CALL_PARAMS] = {0};
    int param_num = 0;

    int cs;

    
/* #line 53 "servo_command_line.inc" */
	{
	cs = servo_command_line_start;
	}

/* #line 58 "servo_command_line.inc" */
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 47: goto st2;
		case 98: goto st3;
		case 100: goto st6;
		case 108: goto st17;
		case 114: goto st31;
		case 115: goto st45;
	}
	goto tr0;
tr0:
/* #line 107 "servo_command_line.rl" */
	{ 
#ifndef TEST_RAGEL_PARSER
            printf("error at %d %s\n", (int)(p-start), p); 
#endif
            return 0;
        }
	goto st0;
/* #line 83 "servo_command_line.inc" */
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 47 )
		goto st56;
	goto tr0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	goto st56;
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
		case 110: goto tr10;
	}
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 102 )
		goto tr11;
	goto tr0;
tr10:
/* #line 183 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_ON\n");
#else
            print("blink_on");
            blink_switch(1);
#endif
        }
	goto st57;
tr11:
/* #line 192 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_OFF\n");
#else
            print("blink_off");
            blink_switch(0);
#endif
        }
	goto st57;
tr22:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
/* #line 156 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("DELAY %d\n", params[0]);
#else            
            delay(params[0]);
#endif
        }
	goto st57;
tr25:
/* #line 156 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("DELAY %d\n", params[0]);
#else            
            delay(params[0]);
#endif
        }
	goto st57;
tr27:
/* #line 130 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("DUMP\n");
#else
            
            cli_DUMP();            
#endif
        }
	goto st57;
tr46:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
/* #line 139 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("LIMITS %d %d\n", params[0], params[1]);
#else
            
            cli_LIMITS(params[0], params[1]);                        
#endif
        }
	goto st57;
tr49:
/* #line 139 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("LIMITS %d %d\n", params[0], params[1]);
#else
            
            cli_LIMITS(params[0], params[1]);                        
#endif
        }
	goto st57;
tr68:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
/* #line 148 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("ROTATE %d %d\n", params[0], params[1]);
#else            
            cli_ROTATE(params[0], params[1]);
#endif
        }
	goto st57;
tr71:
/* #line 148 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("ROTATE %d %d\n", params[0], params[1]);
#else            
            cli_ROTATE(params[0], params[1]);
#endif
        }
	goto st57;
tr87:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
/* #line 120 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("SET %d %d\n", params[0], params[1]);
#else
            
            cli_SET(params[0], params[1]);
            
#endif
        }
	goto st57;
tr90:
/* #line 120 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("SET %d %d\n", params[0], params[1]);
#else
            
            cli_SET(params[0], params[1]);
            
#endif
        }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
/* #line 325 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto st57;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st57;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	switch( (*p) ) {
		case 101: goto st7;
		case 117: goto st15;
	}
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 108 )
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 97 )
		goto st9;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 121 )
		goto st10;
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	switch( (*p) ) {
		case 32: goto st10;
		case 40: goto st11;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st10;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	switch( (*p) ) {
		case 32: goto st11;
		case 45: goto tr18;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr19;
	} else if ( (*p) >= 9 )
		goto st11;
	goto tr0;
tr18:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 69 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>signed: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = -1;
        }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
/* #line 408 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr20;
	goto tr0;
tr19:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st13;
tr20:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
/* #line 446 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr21;
		case 41: goto tr22;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st13;
	} else if ( (*p) >= 9 )
		goto tr21;
	goto tr0;
tr21:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
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
/* #line 483 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st14;
		case 41: goto tr25;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st14;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 109 )
		goto st16;
	goto tr0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 112 )
		goto tr27;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 105 )
		goto st18;
	goto tr0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 109 )
		goto st19;
	goto tr0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 105 )
		goto st20;
	goto tr0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 116 )
		goto st21;
	goto tr0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 115 )
		goto st22;
	goto tr0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 32: goto st22;
		case 40: goto st23;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st22;
	goto tr0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 32: goto st23;
		case 45: goto tr34;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr35;
	} else if ( (*p) >= 9 )
		goto st23;
	goto tr0;
tr34:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 69 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>signed: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = -1;
        }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
/* #line 587 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr36;
	goto tr0;
tr35:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st25;
tr36:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
/* #line 625 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr37;
		case 44: goto tr38;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st25;
	} else if ( (*p) >= 9 )
		goto tr37;
	goto tr0;
tr37:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
/* #line 662 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto st27;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st26;
	goto tr0;
tr38:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
/* #line 696 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st27;
		case 45: goto tr42;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr43;
	} else if ( (*p) >= 9 )
		goto st27;
	goto tr0;
tr42:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 69 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>signed: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = -1;
        }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
/* #line 729 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr44;
	goto tr0;
tr43:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st29;
tr44:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
/* #line 767 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr45;
		case 41: goto tr46;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st29;
	} else if ( (*p) >= 9 )
		goto tr45;
	goto tr0;
tr45:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
/* #line 804 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st30;
		case 41: goto tr49;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st30;
	goto tr0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 111 )
		goto st32;
	goto tr0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 116 )
		goto st33;
	goto tr0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 97 )
		goto st34;
	goto tr0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 116 )
		goto st35;
	goto tr0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 101 )
		goto st36;
	goto tr0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 32: goto st36;
		case 40: goto st37;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st36;
	goto tr0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 32: goto st37;
		case 45: goto tr56;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr57;
	} else if ( (*p) >= 9 )
		goto st37;
	goto tr0;
tr56:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 69 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>signed: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = -1;
        }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
/* #line 894 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr58;
	goto tr0;
tr57:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st39;
tr58:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
/* #line 932 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr59;
		case 44: goto tr60;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st39;
	} else if ( (*p) >= 9 )
		goto tr59;
	goto tr0;
tr59:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
/* #line 969 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st40;
		case 44: goto st41;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st40;
	goto tr0;
tr60:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
/* #line 1003 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st41;
		case 45: goto tr64;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr65;
	} else if ( (*p) >= 9 )
		goto st41;
	goto tr0;
tr64:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 69 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>signed: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = -1;
        }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
/* #line 1036 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr66;
	goto tr0;
tr65:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st43;
tr66:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
/* #line 1074 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr67;
		case 41: goto tr68;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st43;
	} else if ( (*p) >= 9 )
		goto tr67;
	goto tr0;
tr67:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
/* #line 1111 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st44;
		case 41: goto tr71;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st44;
	goto tr0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 101 )
		goto st46;
	goto tr0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 116 )
		goto st47;
	goto tr0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 32: goto st47;
		case 40: goto st48;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st47;
	goto tr0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 32: goto st48;
		case 45: goto tr75;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr76;
	} else if ( (*p) >= 9 )
		goto st48;
	goto tr0;
tr75:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 69 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>signed: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = -1;
        }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
/* #line 1180 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr77;
	goto tr0;
tr76:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st50;
tr77:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
/* #line 1218 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr78;
		case 44: goto tr79;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st50;
	} else if ( (*p) >= 9 )
		goto tr78;
	goto tr0;
tr78:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
/* #line 1255 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st51;
		case 44: goto st52;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st51;
	goto tr0;
tr79:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
/* #line 1289 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st52;
		case 45: goto tr83;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr84;
	} else if ( (*p) >= 9 )
		goto st52;
	goto tr0;
tr83:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 69 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>signed: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = -1;
        }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
/* #line 1322 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr85;
	goto tr0;
tr84:
/* #line 77 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>reset_sign: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = 1;
        }
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st54;
tr85:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
/* #line 1360 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr86;
		case 41: goto tr87;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st54;
	} else if ( (*p) >= 9 )
		goto tr86;
	goto tr0;
tr86:
/* #line 86 "servo_command_line.rl" */
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
               params[param_num] = sign*tmp;
               param_num++;
            }
#ifdef TEST_RAGEL_PARSER
            printf(">>end_numeric: %d %d\n", param_num, tmp); 
#endif

        }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
/* #line 1397 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st55;
		case 41: goto tr90;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st55;
	goto tr0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 57: 
/* #line 114 "servo_command_line.rl" */
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
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
	case 22: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
	case 29: 
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
	case 37: 
	case 38: 
	case 39: 
	case 40: 
	case 41: 
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
	case 55: 
/* #line 107 "servo_command_line.rl" */
	{ 
#ifndef TEST_RAGEL_PARSER
            printf("error at %d %s\n", (int)(p-start), p); 
#endif
            return 0;
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 56: 
/* #line 175 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("COMMENT\n");
#else            
#endif
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
/* #line 1559 "servo_command_line.inc" */
	}
	}

	_out: {}
	}

/* #line 222 "servo_command_line.rl" */


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
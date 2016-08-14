
/* #line 1 "servo_command_line.rl" */
#ifdef TEST_RAGEL_PARSER

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#endif

#define MAX_CALL_PARAMS 3


/* #line 15 "servo_command_line.inc" */
static const int servo_command_line_start = 1;
static const int servo_command_line_first_final = 48;
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
		case 108: goto st9;
		case 114: goto st23;
		case 115: goto st37;
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
		goto st48;
	goto tr0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	goto st48;
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
/* #line 174 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_ON\n");
#else
            print("blink_on");
            blink_switch(1);
#endif
        }
	goto st49;
tr11:
/* #line 183 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_OFF\n");
#else
            print("blink_off");
            blink_switch(0);
#endif
        }
	goto st49;
tr14:
/* #line 130 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("DUMP\n");
#else
            
            cli_DUMP();            
#endif
        }
	goto st49;
tr33:
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
	goto st49;
tr36:
/* #line 139 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("LIMITS %d %d\n", params[0], params[1]);
#else
            
            cli_LIMITS(params[0], params[1]);                        
#endif
        }
	goto st49;
tr55:
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
	goto st49;
tr58:
/* #line 148 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("ROTATE %d %d\n", params[0], params[1]);
#else            
            cli_ROTATE(params[0], params[1]);
#endif
        }
	goto st49;
tr74:
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
	goto st49;
tr77:
/* #line 120 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("SET %d %d\n", params[0], params[1]);
#else
            
            cli_SET(params[0], params[1]);
            
#endif
        }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
/* #line 285 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto st49;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st49;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 117 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 109 )
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 112 )
		goto tr14;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 105 )
		goto st10;
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 109 )
		goto st11;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 105 )
		goto st12;
	goto tr0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 116 )
		goto st13;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 115 )
		goto st14;
	goto tr0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case 32: goto st14;
		case 40: goto st15;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st14;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case 32: goto st15;
		case 45: goto tr21;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr22;
	} else if ( (*p) >= 9 )
		goto st15;
	goto tr0;
tr21:
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
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
/* #line 394 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr23;
	goto tr0;
tr22:
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
	goto st17;
tr23:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
/* #line 432 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr24;
		case 44: goto tr25;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st17;
	} else if ( (*p) >= 9 )
		goto tr24;
	goto tr0;
tr24:
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
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
/* #line 469 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st18;
		case 44: goto st19;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st18;
	goto tr0;
tr25:
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
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
/* #line 503 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st19;
		case 45: goto tr29;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr30;
	} else if ( (*p) >= 9 )
		goto st19;
	goto tr0;
tr29:
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
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
/* #line 536 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr31;
	goto tr0;
tr30:
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
	goto st21;
tr31:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
/* #line 574 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr32;
		case 41: goto tr33;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st21;
	} else if ( (*p) >= 9 )
		goto tr32;
	goto tr0;
tr32:
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
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
/* #line 611 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st22;
		case 41: goto tr36;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st22;
	goto tr0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 111 )
		goto st24;
	goto tr0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 116 )
		goto st25;
	goto tr0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 97 )
		goto st26;
	goto tr0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 116 )
		goto st27;
	goto tr0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 101 )
		goto st28;
	goto tr0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 32: goto st28;
		case 40: goto st29;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st28;
	goto tr0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 32: goto st29;
		case 45: goto tr43;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr44;
	} else if ( (*p) >= 9 )
		goto st29;
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
/* #line 69 "servo_command_line.rl" */
	{
#ifdef TEST_RAGEL_PARSER
            printf(">>signed: %ld \"%.*s\"\n", p-data, (int)(p-start), start); 
#else
#endif
            sign = -1;
        }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
/* #line 701 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr45;
	goto tr0;
tr44:
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
	goto st31;
tr45:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
/* #line 739 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr46;
		case 44: goto tr47;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st31;
	} else if ( (*p) >= 9 )
		goto tr46;
	goto tr0;
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
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
/* #line 776 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st32;
		case 44: goto st33;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st32;
	goto tr0;
tr47:
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
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
/* #line 810 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st33;
		case 45: goto tr51;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr52;
	} else if ( (*p) >= 9 )
		goto st33;
	goto tr0;
tr51:
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
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
/* #line 843 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr53;
	goto tr0;
tr52:
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
	goto st35;
tr53:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
/* #line 881 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr54;
		case 41: goto tr55;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st35;
	} else if ( (*p) >= 9 )
		goto tr54;
	goto tr0;
tr54:
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
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
/* #line 918 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st36;
		case 41: goto tr58;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st36;
	goto tr0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 101 )
		goto st38;
	goto tr0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) == 116 )
		goto st39;
	goto tr0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 32: goto st39;
		case 40: goto st40;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st39;
	goto tr0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 32: goto st40;
		case 45: goto tr62;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr63;
	} else if ( (*p) >= 9 )
		goto st40;
	goto tr0;
tr62:
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
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
/* #line 987 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr64;
	goto tr0;
tr63:
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
	goto st42;
tr64:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
/* #line 1025 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr65;
		case 44: goto tr66;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st42;
	} else if ( (*p) >= 9 )
		goto tr65;
	goto tr0;
tr65:
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
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
/* #line 1062 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st43;
		case 44: goto st44;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st43;
	goto tr0;
tr66:
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
/* #line 1096 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st44;
		case 45: goto tr70;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr71;
	} else if ( (*p) >= 9 )
		goto st44;
	goto tr0;
tr70:
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
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
/* #line 1129 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr72;
	goto tr0;
tr71:
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
	goto st46;
tr72:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
/* #line 1167 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr73;
		case 41: goto tr74;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st46;
	} else if ( (*p) >= 9 )
		goto tr73;
	goto tr0;
tr73:
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
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
/* #line 1204 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st47;
		case 41: goto tr77;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st47;
	goto tr0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
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

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 49: 
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
	case 48: 
/* #line 166 "servo_command_line.rl" */
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
/* #line 1350 "servo_command_line.inc" */
	}
	}

	_out: {}
	}

/* #line 212 "servo_command_line.rl" */


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
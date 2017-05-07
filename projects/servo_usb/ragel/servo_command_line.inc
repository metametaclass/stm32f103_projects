
/* #line 1 "servo_command_line.rl" */
#ifdef TEST_RAGEL_PARSER

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#endif

#define MAX_CALL_PARAMS 3


/* #line 15 "servo_command_line.inc" */
static const int servo_command_line_start = 1;
static const int servo_command_line_first_final = 68;
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
		case 105: goto st17;
		case 108: goto st29;
		case 114: goto st43;
		case 115: goto st57;
	}
	goto tr0;
tr0:
/* #line 107 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("error at %d \"%s\"\n", (int)(p-start), p); 
#endif
            //return -1;
        }
	goto st0;
/* #line 84 "servo_command_line.inc" */
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 47 )
		goto st68;
	goto tr0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	goto st68;
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
		case 110: goto st71;
	}
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 102 )
		goto st69;
	goto tr0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 32 )
		goto tr108;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr108;
	goto tr0;
tr108:
/* #line 201 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_OFF\n");
#else
            printf("blink_off");
            CLI_blink_switch(ctx, 0);
#endif
        }
	goto st70;
tr110:
/* #line 192 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_ON\n");
#else
            printf("blink_on");
            CLI_blink_switch(ctx, 1);
#endif
        }
	goto st70;
tr111:
/* #line 156 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("DELAY %d\n", params[0]);
#else            
            delay(params[0]);
#endif
        }
	goto st70;
tr112:
/* #line 130 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("DUMP\n");
#else
            
            cli_DUMP(ctx);            
#endif
        }
	goto st70;
tr113:
/* #line 165 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("INTERACTIVE %d\n", params[0]);
#else            
            cli_INTERACTIVE(ctx, params[0]);
#endif
        }
	goto st70;
tr114:
/* #line 139 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("LIMITS %d %d\n", params[0], params[1]);
#else
            
            cli_LIMITS(ctx, params[0], params[1]);
#endif
        }
	goto st70;
tr115:
/* #line 148 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("ROTATE %d %d\n", params[0], params[1]);
#else            
            cli_ROTATE(ctx, params[0], params[1]);
#endif
        }
	goto st70;
tr116:
/* #line 120 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("SET %d %d\n", params[0], params[1]);
#else
            
            cli_SET(ctx, params[0], params[1]);
            
#endif
        }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
/* #line 222 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto st70;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st70;
	goto tr0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 32 )
		goto tr110;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr110;
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
		case 45: goto tr19;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr20;
	} else if ( (*p) >= 9 )
		goto st11;
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
/* #line 314 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr21;
	goto tr0;
tr20:
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
tr21:
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
/* #line 352 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr22;
		case 41: goto tr23;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st13;
	} else if ( (*p) >= 9 )
		goto tr22;
	goto tr0;
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
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
/* #line 389 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st14;
		case 41: goto st72;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st14;
	goto tr0;
tr23:
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
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
/* #line 423 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto tr111;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr111;
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
		goto st73;
	goto tr0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 32 )
		goto tr112;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr112;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 110 )
		goto st18;
	goto tr0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 116 )
		goto st19;
	goto tr0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 101 )
		goto st20;
	goto tr0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 114 )
		goto st21;
	goto tr0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 97 )
		goto st22;
	goto tr0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) == 99 )
		goto st23;
	goto tr0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 116 )
		goto st24;
	goto tr0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 40 )
		goto st25;
	goto tr0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 32: goto st25;
		case 45: goto tr37;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr38;
	} else if ( (*p) >= 9 )
		goto st25;
	goto tr0;
tr37:
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
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
/* #line 544 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr39;
	goto tr0;
tr38:
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
	goto st27;
tr39:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
/* #line 582 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr40;
		case 41: goto tr41;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st27;
	} else if ( (*p) >= 9 )
		goto tr40;
	goto tr0;
tr40:
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
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
/* #line 619 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st28;
		case 41: goto st74;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st28;
	goto tr0;
tr41:
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
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
/* #line 653 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto tr113;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr113;
	goto tr0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 105 )
		goto st30;
	goto tr0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) == 109 )
		goto st31;
	goto tr0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 105 )
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
	if ( (*p) == 115 )
		goto st34;
	goto tr0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 32: goto st34;
		case 40: goto st35;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st34;
	goto tr0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 32: goto st35;
		case 45: goto tr51;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr52;
	} else if ( (*p) >= 9 )
		goto st35;
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
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
/* #line 741 "servo_command_line.inc" */
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
	goto st37;
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
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
/* #line 779 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr54;
		case 44: goto tr55;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st37;
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
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
/* #line 816 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st38;
		case 44: goto st39;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st38;
	goto tr0;
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
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
/* #line 850 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st39;
		case 45: goto tr59;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr60;
	} else if ( (*p) >= 9 )
		goto st39;
	goto tr0;
tr59:
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
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
/* #line 883 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr61;
	goto tr0;
tr60:
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
	goto st41;
tr61:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
/* #line 921 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr62;
		case 41: goto tr63;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st41;
	} else if ( (*p) >= 9 )
		goto tr62;
	goto tr0;
tr62:
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
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
/* #line 958 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st42;
		case 41: goto st75;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st42;
	goto tr0;
tr63:
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
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
/* #line 992 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto tr114;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr114;
	goto tr0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 111 )
		goto st44;
	goto tr0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 116 )
		goto st45;
	goto tr0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 97 )
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
	if ( (*p) == 101 )
		goto st48;
	goto tr0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 32: goto st48;
		case 40: goto st49;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st48;
	goto tr0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 32: goto st49;
		case 45: goto tr73;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr74;
	} else if ( (*p) >= 9 )
		goto st49;
	goto tr0;
tr73:
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
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
/* #line 1080 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr75;
	goto tr0;
tr74:
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
	goto st51;
tr75:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
/* #line 1118 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr76;
		case 44: goto tr77;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st51;
	} else if ( (*p) >= 9 )
		goto tr76;
	goto tr0;
tr76:
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
/* #line 1155 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st52;
		case 44: goto st53;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st52;
	goto tr0;
tr77:
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
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
/* #line 1189 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st53;
		case 45: goto tr81;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr82;
	} else if ( (*p) >= 9 )
		goto st53;
	goto tr0;
tr81:
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
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
/* #line 1222 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr83;
	goto tr0;
tr82:
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
	goto st55;
tr83:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
/* #line 1260 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr84;
		case 41: goto tr85;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st55;
	} else if ( (*p) >= 9 )
		goto tr84;
	goto tr0;
tr84:
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
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
/* #line 1297 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st56;
		case 41: goto st76;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st56;
	goto tr0;
tr85:
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
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
/* #line 1331 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto tr115;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr115;
	goto tr0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 101 )
		goto st58;
	goto tr0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) == 116 )
		goto st59;
	goto tr0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 32: goto st59;
		case 40: goto st60;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st59;
	goto tr0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 32: goto st60;
		case 45: goto tr92;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr93;
	} else if ( (*p) >= 9 )
		goto st60;
	goto tr0;
tr92:
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
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
/* #line 1398 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr94;
	goto tr0;
tr93:
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
	goto st62;
tr94:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
/* #line 1436 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr95;
		case 44: goto tr96;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st62;
	} else if ( (*p) >= 9 )
		goto tr95;
	goto tr0;
tr95:
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
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
/* #line 1473 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st63;
		case 44: goto st64;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st63;
	goto tr0;
tr96:
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
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
/* #line 1507 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st64;
		case 45: goto tr100;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr101;
	} else if ( (*p) >= 9 )
		goto st64;
	goto tr0;
tr100:
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
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
/* #line 1540 "servo_command_line.inc" */
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr102;
	goto tr0;
tr101:
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
	goto st66;
tr102:
/* #line 44 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("begin_literal: %ld\n", p-data); 
#else
#endif
            start = p;
            //sign = 1;
        }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
/* #line 1578 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto tr103;
		case 41: goto tr104;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st66;
	} else if ( (*p) >= 9 )
		goto tr103;
	goto tr0;
tr103:
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
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
/* #line 1615 "servo_command_line.inc" */
	switch( (*p) ) {
		case 32: goto st67;
		case 41: goto st77;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st67;
	goto tr0;
tr104:
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
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
/* #line 1649 "servo_command_line.inc" */
	if ( (*p) == 32 )
		goto tr116;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr116;
	goto tr0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
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
	_test_eof74: cs = 74; goto _test_eof; 
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
	_test_eof75: cs = 75; goto _test_eof; 
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
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 70: 
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
	case 56: 
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
	case 67: 
/* #line 107 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("error at %d \"%s\"\n", (int)(p-start), p); 
#endif
            //return -1;
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 77: 
/* #line 120 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("SET %d %d\n", params[0], params[1]);
#else
            
            cli_SET(ctx, params[0], params[1]);
            
#endif
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 73: 
/* #line 130 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("DUMP\n");
#else
            
            cli_DUMP(ctx);            
#endif
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 75: 
/* #line 139 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("LIMITS %d %d\n", params[0], params[1]);
#else
            
            cli_LIMITS(ctx, params[0], params[1]);
#endif
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 76: 
/* #line 148 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("ROTATE %d %d\n", params[0], params[1]);
#else            
            cli_ROTATE(ctx, params[0], params[1]);
#endif
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 72: 
/* #line 156 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("DELAY %d\n", params[0]);
#else            
            delay(params[0]);
#endif
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 74: 
/* #line 165 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("INTERACTIVE %d\n", params[0]);
#else            
            cli_INTERACTIVE(ctx, params[0]);
#endif
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 68: 
/* #line 184 "servo_command_line.rl" */
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
	case 71: 
/* #line 192 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_ON\n");
#else
            printf("blink_on");
            CLI_blink_switch(ctx, 1);
#endif
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
	case 69: 
/* #line 201 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("BLINK_OFF\n");
#else
            printf("blink_off");
            CLI_blink_switch(ctx, 0);
#endif
        }
/* #line 114 "servo_command_line.rl" */
	{ 
#ifdef TEST_RAGEL_PARSER
            printf("eof at %d\n", (int)(p-start));
#endif
        }
	break;
/* #line 1975 "servo_command_line.inc" */
	}
	}

	_out: {}
	}

/* #line 232 "servo_command_line.rl" */


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
#define TEST_RAGEL_PARSER 1

#define WMQ_LOG(level, message, ...) \
    do {\
        printf(message, __VA_ARGS__);\
    } while(0)

#include "servo_command_line.inc"

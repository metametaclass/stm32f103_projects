#ifndef READLINE_CONTEXT_H
#define READLINE_CONTEXT_H

#include "../../libs/microrl/microrl.h"
#include "../../libs/ringbuffer/ringbuffer.h"


#define BUFFER_SIZE 1024


typedef struct readline_context_s {
    microrl_t readline;
    struct ring output_ring;
    uint8_t output_ring_buffer[BUFFER_SIZE];
} readline_context_t;


void readline_context_init(readline_context_t *ctx, print_t print);

#endif
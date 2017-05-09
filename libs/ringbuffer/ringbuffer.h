/******************************************************************************
 * Simple ringbuffer implementation from open-bldc's libgovernor that
 * you can find at:
 * https://github.com/open-bldc/open-bldc/tree/master/source/libgovernor
 *****************************************************************************/

#include <stdint.h>

typedef int32_t ring_size_t;

struct ring {
  uint8_t *data;
  ring_size_t size;
  uint32_t begin;
  uint32_t end;
};

void ring_init(struct ring *ring, uint8_t *buf, ring_size_t size);

int32_t ring_write_ch(struct ring *ring, uint8_t ch);

int32_t ring_write(struct ring *ring, uint8_t *data, ring_size_t size);

int32_t ring_read_ch(struct ring *ring, uint8_t *ch);

int32_t ring_read(struct ring *ring, uint8_t *data, ring_size_t size);


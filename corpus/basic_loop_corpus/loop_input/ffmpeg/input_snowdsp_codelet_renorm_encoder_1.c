#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct RangeCoder {
    int low;
    int range;
    int outstanding_count;
    int outstanding_byte;
    uint8_t zero_state[256];
    uint8_t one_state[256];
    uint8_t *bytestream_start;
    uint8_t *bytestream;
    uint8_t *bytestream_end;
    int overread;
} RangeCoder;

RangeCoder *c;

static uint8_t *bytestream_buffer;
static RangeCoder c_instance;

void init_vars() {
    const size_t buffer_size = 134217728; // 128 MB to target ~0.01 sec runtime

    bytestream_buffer = (uint8_t *)calloc(buffer_size, sizeof(uint8_t));
    if (!bytestream_buffer) exit(1);

    c = &c_instance;
    c->low = 0;
    c->range = 0;
    c->outstanding_count = 1000000; // Large enough for measurable loop
    c->outstanding_byte = 0;
    for (int i = 0; i < 256; ++i) {
        c->zero_state[i] = (uint8_t)(i % 256);
        c->one_state[i] = (uint8_t)((255 - i) % 256);
    }
    c->bytestream_start = bytestream_buffer;
    c->bytestream = bytestream_buffer;
    c->bytestream_end = bytestream_buffer + buffer_size;
    c->overread = 0;
}
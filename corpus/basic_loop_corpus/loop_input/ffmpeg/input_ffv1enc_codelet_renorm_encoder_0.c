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

static uint8_t *global_bytestream_mem;
RangeCoder *c;

void init_vars() {
    const size_t data_size = 134217728; // ~128MB to target ~0.01 sec runtime

    global_bytestream_mem = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!global_bytestream_mem) exit(1);

    c = (RangeCoder*)malloc(sizeof(RangeCoder));
    if (!c) exit(1);

    c->low = 0;
    c->range = 0;
    c->outstanding_count = 1000000; // Large enough to take ~0.01s
    c->outstanding_byte = 0;
    for (int i = 0; i < 256; i++) {
        c->zero_state[i] = 0;
        c->one_state[i] = 1;
    }
    c->bytestream_start = global_bytestream_mem;
    c->bytestream = global_bytestream_mem;
    c->bytestream_end = global_bytestream_mem + data_size;
    c->overread = 0;
}
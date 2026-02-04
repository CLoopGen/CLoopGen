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

static uint8_t *global_bytestream_data;
static RangeCoder *c_instance;
RangeCoder *c;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data

    global_bytestream_data = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!global_bytestream_data) exit(1);

    c_instance = (RangeCoder*)malloc(sizeof(RangeCoder));
    if (!c_instance) exit(1);

    c = c_instance;
    c->outstanding_count = 255; 
    c->bytestream_start = global_bytestream_data;
    c->bytestream = global_bytestream_data;
    c->bytestream_end = global_bytestream_data + data_size;
    c->overread = 0;

    for (int i = 0; i < 256; i++) {
        c->zero_state[i] = i;
        c->one_state[i] = 255 - i;
    }
}
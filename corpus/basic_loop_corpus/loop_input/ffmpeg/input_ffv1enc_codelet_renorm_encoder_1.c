#include <stdint.h>
#include <stdlib.h>

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

static uint8_t *global_bytestream_buffer;
static RangeCoder global_coder;

void init_vars() {
    const size_t buffer_size = 134217728; // 128 MB to target ~0.01 sec runtime

    global_bytestream_buffer = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));
    if (!global_bytestream_buffer) exit(1);

    c = &global_coder;
    c->outstanding_count = 67108864; // Set loop count to half of buffer size for safety
    c->bytestream_start = global_bytestream_buffer;
    c->bytestream = global_bytestream_buffer;
    c->bytestream_end = global_bytestream_buffer + buffer_size;

    c->low = 0;
    c->range = 0;
    c->outstanding_byte = 0;
    c->overread = 0;

    for (int i = 0; i < 256; ++i) {
        c->zero_state[i] = 1;
        c->one_state[i] = 1;
    }
}
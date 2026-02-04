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

static uint8_t *global_bytestream_buffer;
static RangeCoder global_coder;

RangeCoder *c = &global_coder;

void init_vars() {
    const size_t buffer_size = 134217728; // 128 MB to target ~0.01s runtime

    global_bytestream_buffer = (uint8_t*)malloc(buffer_size);
    if (!global_bytestream_buffer) {
        exit(1);
    }

    global_coder.low = 0;
    global_coder.range = 0;
    global_coder.outstanding_count = 65536; // Large enough to dominate loop time
    global_coder.outstanding_byte = 0;
    for (int i = 0; i < 256; i++) {
        global_coder.zero_state[i] = 0;
        global_coder.one_state[i] = 1;
    }
    global_coder.bytestream_start = global_bytestream_buffer;
    global_coder.bytestream = global_bytestream_buffer;
    global_coder.bytestream_end = global_bytestream_buffer + buffer_size;
    global_coder.overread = 0;
}
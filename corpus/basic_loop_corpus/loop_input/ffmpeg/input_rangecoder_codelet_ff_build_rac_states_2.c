#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
int factor;
int max_p;
int64_t one;
int64_t p;
int last_p8;
int p8;
int i;

static uint8_t *global_bytestream_buffer;
static RangeCoder global_coder;

void init_vars() {
    // Allocate a large enough buffer to make loop run for ~0.01s
    // The loop runs 128 iterations, so we don't need huge data
    // but initialize structures completely
    
    global_bytestream_buffer = (uint8_t*)calloc(1, 65536);
    
    if (!global_bytestream_buffer) {
        exit(1);
    }
    
    // Initialize the coder structure
    memset(&global_coder, 0, sizeof(global_coder));
    global_coder.bytestream_start = global_bytestream_buffer;
    global_coder.bytestream = global_bytestream_buffer;
    global_coder.bytestream_end = global_bytestream_buffer + 65536;
    
    // Initialize states
    for (int j = 0; j < 256; j++) {
        global_coder.zero_state[j] = (uint8_t)(j * 179 % 251);
        global_coder.one_state[j] = (uint8_t)(j * 199 % 251);
    }
    
    // Assign pointer
    c = &global_coder;
    
    // Initialize scalar values
    factor = 150000000;
    max_p = 255;
    one = ((int64_t)1) << 32;
    p = one >> 2;
    last_p8 = 1;
    p8 = 0;
    i = 0;
}
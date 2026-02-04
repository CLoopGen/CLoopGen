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
static RangeCoder global_c;

RangeCoder *c = &global_c;

void init_vars() {
    // Allocate a large buffer to ensure loop takes ~0.01 seconds
    // Assuming each iteration is fast, we need many iterations
    // Let's target around 10 million iterations for ~0.01s on modern CPU
    const int outstanding_count_target = 10000000;
    
    // Allocate buffer with extra space to prevent overflow
    global_bytestream_buffer = (uint8_t*)malloc(outstanding_count_target + 1024);
    if (!global_bytestream_buffer) {
        exit(1);
    }
    
    // Initialize the RangeCoder structure
    global_c.low = 0;
    global_c.range = 0x1000000; // typical initial range
    global_c.outstanding_count = outstanding_count_target;
    global_c.outstanding_byte = 0;
    
    // Initialize state arrays
    for (int i = 0; i < 256; i++) {
        global_c.zero_state[i] = (uint8_t)(i * 0xFF / 255);
        global_c.one_state[i] = (uint8_t)((255 - i) * 0xFF / 255);
    }
    
    // Set up bytestream pointers
    global_c.bytestream_start = global_bytestream_buffer;
    global_c.bytestream = global_bytestream_buffer;
    global_c.bytestream_end = global_bytestream_buffer + outstanding_count_target + 1024;
    global_c.overread = 0;
}
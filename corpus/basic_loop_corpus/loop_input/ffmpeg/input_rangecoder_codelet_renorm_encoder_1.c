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
    // Allocate a large enough buffer to make the loop take ~0.01 seconds
    // Assuming simple byte assignment, 10 million iterations should be around 0.01s
    size_t buffer_size = 10000000;
    
    global_bytestream_buffer = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));
    if (!global_bytestream_buffer) {
        exit(1);
    }
    
    // Initialize the RangeCoder structure
    global_c.low = 0;
    global_c.range = 0;
    global_c.outstanding_count = 10000000;  // 10M iterations
    global_c.outstanding_byte = 0;
    
    // Initialize state arrays
    for (int i = 0; i < 256; i++) {
        global_c.zero_state[i] = i & 0xFF;
        global_c.one_state[i] = (i + 42) & 0xFF;
    }
    
    global_c.bytestream_start = global_bytestream_buffer;
    global_c.bytestream = global_bytestream_buffer;
    global_c.bytestream_end = global_bytestream_buffer + buffer_size;
    global_c.overread = 0;
}
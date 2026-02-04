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
RangeCoder *c;

void init_vars() {
    // Allocate a large buffer to ensure loop runs for ~0.01 seconds
    // Assuming each iteration is fast, we use ~16M iterations as estimate
    // Each iteration does c->outstanding_count--, so set it to ~16M
    size_t buffer_size = 16 << 20; // 16 MB

    global_bytestream_buffer = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));
    if (!global_bytestream_buffer) exit(1);

    c = (RangeCoder*)malloc(sizeof(RangeCoder));
    if (!c) exit(1);

    // Initialize c fields
    c->low = 0;
    c->range = 0;
    c->outstanding_count = (int)(buffer_size / 2); // Ensure it's large enough to take time
    c->outstanding_byte = 0;
    
    // Initialize state arrays
    for (int i = 0; i < 256; i++) {
        c->zero_state[i] = (uint8_t)i;
        c->one_state[i] = (uint8_t)(255 - i);
    }

    // Set up bytestream pointers within allocated buffer
    c->bytestream_start = global_bytestream_buffer;
    c->bytestream = global_bytestream_buffer;
    c->bytestream_end = global_bytestream_buffer + buffer_size;
    c->overread = 0;
}
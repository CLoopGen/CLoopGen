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

extern RangeCoder *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory write with pointer arithmetic unrolled by 2x
    int count = c->outstanding_count;
    uint8_t* ptr = c->bytestream;
    for (; count >= 2; count -= 2) {
        *ptr++ = 0;
        *ptr++ = 0;
    }
    for (; count > 0; count--) {
        *ptr++ = 0;
    }
    c->bytestream = ptr;
    c->outstanding_count = 0;
}

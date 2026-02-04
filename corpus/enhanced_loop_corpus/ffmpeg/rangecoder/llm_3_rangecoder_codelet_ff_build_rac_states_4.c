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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (step of 2) with bounds adjustment
    for (i = 1; i < 255; i += 2) {
        c->zero_state[i] = 256 - c->one_state[256 - i];
        if (i + 1 < 255) {
            c->zero_state[i + 1] = 256 - c->one_state[256 - (i + 1)];
        }
    }
}

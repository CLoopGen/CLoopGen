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
    for (i = 1; i < 255; i++) {
        if (c->one_state[256 - i] < 256) {
            c->zero_state[i] = 256 - c->one_state[256 - i];
        } else {
            c->zero_state[i] = 0;
        }
    }
}

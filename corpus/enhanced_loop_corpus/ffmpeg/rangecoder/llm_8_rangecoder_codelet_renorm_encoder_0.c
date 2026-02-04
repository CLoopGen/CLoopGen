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
    int count = c->outstanding_count;
    c->outstanding_count = 0;
    for (int i = 0; i < count; i += 4) {
        *c->bytestream++ = 255;
        if (i + 1 < count) *c->bytestream++ = 255;
        if (i + 2 < count) *c->bytestream++ = 255;
        if (i + 3 < count) *c->bytestream++ = 255;
    }
}

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
    uint8_t *stream = c->bytestream;
    int count = c->outstanding_count;
    for (int i = 0; i < count; i += 4) {
        stream[i] = 255;
        if (i+1 < count) stream[i+1] = 255;
        if (i+2 < count) stream[i+2] = 255;
        if (i+3 < count) stream[i+3] = 255;
    }
    c->bytestream += c->outstanding_count;
    c->outstanding_count = 0;
}

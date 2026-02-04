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
    volatile int *count_ptr = &c->outstanding_count;
    uint8_t **stream_ptr = &c->bytestream;
    for (int i = 0; i < *count_ptr; i++) {
        *(*stream_ptr)++ = 255;
    }
    *count_ptr = 0;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int low;
    uint16_t range;
    int16_t counter;
    const uint8_t *bytestream;
    const uint8_t *bytestream_end;
    uint16_t contexts[22];
    int error;
    int overread;
} DiracArith;

extern DiracArith *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_low = c->low;
    const uint8_t *temp_stream = c->bytestream;
    const uint8_t *end = c->bytestream_end;
    for (i = 0; i < 4; i++) {
        temp_low <<= 8;
        if (temp_stream < end)
            temp_low |= *(temp_stream++);
        else
            temp_low |= 255;
    }
    c->low = temp_low;
    c->bytestream = temp_stream;
}

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
    for (i = 0; i < 8; i++) {
        c->low <<= 7;
        c->range += (c->low & 0x7F) * 2;
        if (c->bytestream < c->bytestream_end && i % 2 == 0)
            c->low |= *c->bytestream++;
        else
            c->low |= 128;
        c->counter = (c->counter + c->contexts[i % 22]) & 0xFFFF;
    }
}

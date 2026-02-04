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
    uint32_t local_low = c->low;
    int local_i;
    for (local_i = 0; local_i < 4; local_i++) {
        local_low <<= 8;
        if ((c->bytestream + local_i) < c->bytestream_end && local_i < 4)
            local_low |= c->bytestream[local_i];
        else
            local_low |= 255;
    }
    c->low = local_low;
    if (c->bytestream + 4 <= c->bytestream_end)
        c->bytestream += 4;
    else
        c->overread = 1;
}

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
for (i = 0; i < 4; i++) {
    c->low <<= 8;
    if (c->bytestream < c->bytestream_end)
        c->low |= *c->bytestream++;
    else
        c->low |= 255;
}

}

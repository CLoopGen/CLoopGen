#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint8_t *in;
extern uint8_t *out;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t buffer[6];
for (j = 0; j < w; j++, out += 6, in -= 6) {
    int64_t v = (((uint64_t)((const uint8_t *)(in))[0] << 40) |
                ((uint64_t)((const uint8_t *)(in))[1] << 32) |
                ((uint64_t)((const uint8_t *)(in))[2] << 24) |
                ((uint64_t)((const uint8_t *)(in))[3] << 16) |
                ((uint64_t)((const uint8_t *)(in))[4] << 8) |
                (uint64_t)((const uint8_t *)(in))[5]);

    uint64_t d = v;
    buffer[5] = d;
    buffer[4] = d >> 8;
    buffer[3] = d >> 16;
    buffer[2] = d >> 24;
    buffer[1] = d >> 32;
    buffer[0] = d >> 40;

    for (int i = 0; i < 6; i++) {
        ((uint8_t *)(out))[i] = buffer[i];
    }
}
}

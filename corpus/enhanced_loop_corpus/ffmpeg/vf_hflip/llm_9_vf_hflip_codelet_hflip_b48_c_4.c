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
int stride = 12;
for (j = 0; j < w * 2; j += 2, out += stride, in -= stride) {
    // Process two 6-byte chunks per iteration to increase computational intensity
    const uint8_t *in1 = in;
    const uint8_t *in2 = in - 6;

    int64_t v1 = (((uint64_t)(in1[0]) << 40) | ((uint64_t)(in1[1]) << 32) | ((uint64_t)(in1[2]) << 24) |
                  ((uint64_t)(in1[3]) << 16) | ((uint64_t)(in1[4]) << 8) | (uint64_t)(in1[5]));

    int64_t v2 = (((uint64_t)(in2[0]) << 40) | ((uint64_t)(in2[1]) << 32) | ((uint64_t)(in2[2]) << 24) |
                  ((uint64_t)(in2[3]) << 16) | ((uint64_t)(in2[4]) << 8) | (uint64_t)(in2[5]));

    // Reverse bytes and store first chunk
    uint64_t d1 = v1;
    ((uint8_t *)(out + 6))[5] = d1;
    ((uint8_t *)(out + 6))[4] = d1 >> 8;
    ((uint8_t *)(out + 6))[3] = d1 >> 16;
    ((uint8_t *)(out + 6))[2] = d1 >> 24;
    ((uint8_t *)(out + 6))[1] = d1 >> 32;
    ((uint8_t *)(out + 6))[0] = d1 >> 40;

    // Second chunk
    uint64_t d2 = v2;
    ((uint8_t *)(out))[5] = d2;
    ((uint8_t *)(out))[4] = d2 >> 8;
    ((uint8_t *)(out))[3] = d2 >> 16;
    ((uint8_t *)(out))[2] = d2 >> 24;
    ((uint8_t *)(out))[1] = d2 >> 32;
    ((uint8_t *)(out))[0] = d2 >> 40;
}
}

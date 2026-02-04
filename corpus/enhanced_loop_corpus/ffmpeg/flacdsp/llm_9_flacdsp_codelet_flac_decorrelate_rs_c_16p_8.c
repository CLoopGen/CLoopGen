#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t **samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    unsigned int a = in[0][i];
    unsigned int b = in[1][i];
    unsigned int sum = a + b;
    unsigned int scaled_sum = sum << shift;
    unsigned int scaled_b = b << shift;
    unsigned int mask = (1 << (shift + 1)) - 1;
    samples[0][i] = scaled_sum & mask;
    samples[1][i] = scaled_b & mask;
}
}

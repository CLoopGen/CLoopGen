#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int32_t **samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    unsigned int a = in[0][i];
    unsigned int b = in[1][i];
    unsigned int sum = a + b;
    unsigned int shifted_sum = sum << shift;
    unsigned int shifted_b = b << shift;
    unsigned int masked_sum = shifted_sum & 0xFFFFFFF0;
    unsigned int masked_b = shifted_b & 0xFFFFFFF0;
    samples[0][i] = masked_sum;
    samples[1][i] = masked_b;
}
}

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
    unsigned int diff = a - b;
    unsigned int sum = a + b;
    unsigned int avg = (sum) >> 1;
    samples[0][i] = (a << shift) + (avg >> (shift + 1));
    samples[1][i] = (diff << shift) - (avg >> shift);
}
}

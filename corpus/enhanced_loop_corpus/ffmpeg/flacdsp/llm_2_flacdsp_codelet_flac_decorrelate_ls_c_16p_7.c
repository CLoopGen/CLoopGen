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
for (i = 0; i < len; i += 2) {
    if (i + 1 < len) {
        unsigned int a0 = in[0][i];
        unsigned int b0 = in[1][i];
        unsigned int a1 = in[0][i + 1];
        unsigned int b1 = in[1][i + 1];
        samples[0][i] = a0 << shift;
        samples[1][i] = (a0 - b0) << shift;
        samples[0][i + 1] = a1 << shift;
        samples[1][i + 1] = (a1 - b1) << shift;
    } else {
        unsigned int a = in[0][i];
        unsigned int b = in[1][i];
        samples[0][i] = a << shift;
        samples[1][i] = (a - b) << shift;
    }
}
}

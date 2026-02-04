#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int32_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i += 2) {
    unsigned int a1 = in[0][i];
    int b1 = in[1][i];
    a1 -= b1 >> 1;
    (*samples++) = (a1 + b1) << shift;
    (*samples++) = a1 << shift;

    if (i + 1 < len) {
        unsigned int a2 = in[0][i+1];
        int b2 = in[1][i+1];
        a2 -= b2 >> 1;
        (*samples++) = (a2 + b2) << shift;
        (*samples++) = a2 << shift;
    }
}
}

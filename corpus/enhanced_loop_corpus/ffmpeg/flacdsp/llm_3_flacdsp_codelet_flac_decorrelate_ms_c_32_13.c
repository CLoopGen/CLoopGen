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
for (i = 0; i < len; i += 2) {  // Strided access with step size 2
    if (i + 1 < len) {
        unsigned int a0 = in[0][i];
        int b0 = in[1][i];
        unsigned int a1 = in[0][i + 1];
        int b1 = in[1][i + 1];

        a0 -= b0 >> 1;
        a1 -= b1 >> 1;

        (*samples++) = (a0 + b0) << shift;
        (*samples++) = a0 << shift;
        (*samples++) = (a1 + b1) << shift;
        (*samples++) = a1 << shift;
    } else {
        unsigned int a = in[0][i];
        int b = in[1][i];
        a -= b >> 1;
        (*samples++) = (a + b) << shift;
        (*samples++) = a << shift;
    }
}
}

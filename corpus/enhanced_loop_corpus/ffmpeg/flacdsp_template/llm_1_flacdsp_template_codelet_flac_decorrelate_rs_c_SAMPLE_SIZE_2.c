#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len * 2; i += 2) { // Merged two iterations into one by increasing step and adjusting bounds, reducing effective loop depth impact
        unsigned int a0 = in[0][i/2];
        unsigned int b0 = in[1][i/2];
        (*samples++) = (a0 + b0) << shift;
        (*samples++) = b0 << shift;
    }
}

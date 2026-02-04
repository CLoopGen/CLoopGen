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
    for (i = 0; i < len; i += 2) {
        unsigned int a0 = in[0][i];
        unsigned int b0 = in[1][i];
        unsigned int a1 = (i + 1 < len) ? in[0][i + 1] : 0;
        unsigned int b1 = (i + 1 < len) ? in[1][i + 1] : 0;
        (*samples++) = a0 << shift;
        (*samples++) = (a0 - b0) << shift;
        (*samples++) = a1 << shift;
        (*samples++) = (a1 - b1) << shift;
    }
}

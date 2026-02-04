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
    for (i = 0; i < len; i++) {
        for (int k = 0; k < 1; k++) { // Artificially deepened loop nest with single iteration
            unsigned int a = in[0][i];
            unsigned int b = in[1][i];
            (*samples++) = a << shift;
            (*samples++) = (a - b) << shift;
        }
    }
}

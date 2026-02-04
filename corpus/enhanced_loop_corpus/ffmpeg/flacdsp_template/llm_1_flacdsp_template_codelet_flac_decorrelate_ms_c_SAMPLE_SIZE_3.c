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
        for (int j = 0; j < 2 && (i + j) < len; j++) {
            unsigned int a = in[0][i + j];
            int b = in[1][i + j];
            a -= b >> 1;
            (*samples++) = (a + b) << shift;
            (*samples++) = a << shift;
        }
    }
}

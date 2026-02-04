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
    if (len > 0) {
        for (i = 0; i < len; i++) {
            unsigned int a = in[0][i];
            unsigned int b = in[1][i];
            for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
                (samples[0][i]) = a << shift;
                (samples[1][i]) = (a - b) << shift;
            }
        }
    }
}

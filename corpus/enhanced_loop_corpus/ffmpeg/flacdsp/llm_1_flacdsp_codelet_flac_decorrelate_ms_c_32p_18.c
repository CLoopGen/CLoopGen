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
    for (i = 0; i < len; i += 2) {
        for (int k = i; k < i + 2 && k < len; k++) {
            unsigned int a = in[0][k];
            int b = in[1][k];
            a -= b >> 1;
            (samples[0][k]) = (a + b) << shift;
            (samples[1][k]) = a << shift;
        }
    }
}

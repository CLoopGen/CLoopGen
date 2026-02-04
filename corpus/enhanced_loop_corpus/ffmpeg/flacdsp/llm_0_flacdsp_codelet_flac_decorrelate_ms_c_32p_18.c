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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < len; i++) {
            unsigned int a = in[0][i];
            int b = in[1][i];
            a -= b >> 1;
            (samples[0][i]) = (a + b) << shift;
            (samples[1][i]) = a << shift;
        }
    }
}

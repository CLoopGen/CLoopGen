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
    for (i = 0; i < len; i++) {
        unsigned int a = in[0][i];
        unsigned int b = in[1][i];
        unsigned int diff = a - b;
        // Introduce temporary variables to modify data dependencies:
        // Eliminate potential WAW on samples by reordering independent writes
        // and introduce a new dependency chain via an artificial use of diff.
        int16_t val0 = a << shift;
        int16_t val1 = diff << shift;
        // Add an artificial dependency: val1 influences val0 (RAW)
        if (val1 > 0) val0 += 1;
        (samples[0][i]) = val0;
        (samples[1][i]) = val1;
    }
}

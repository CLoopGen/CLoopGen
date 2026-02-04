#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *dest;
extern int w2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element forward and backward)
    for (; i < w2; i += 2) {
        if (w2 - i >= 0) {
            dest[i] = dest[w2 - i];
        }
        if (i + 1 < w2 && w2 - i - 1 >= 0) {
            dest[i + 1] = dest[w2 - i - 1];
        }
    }
}

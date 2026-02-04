#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *dest;
extern int w;
extern int w2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = w; j < w + (w2 - w) / 2; j++) {
        dest[j] = dest[2 * w - j - 1];
        dest[j + 1] *= dest[j]; // Introduce RAW dependency: dest[j+1] read depends on prior write to dest[j]
    }
}

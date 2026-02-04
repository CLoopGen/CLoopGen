#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern int i;
extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using a temporary pointer
    FFTSample *src = tab + 1;
    FFTSample *dst = tab + (m / 2 - 1);
    int limit = m / 4;
    for (i = 1; i < limit; i++) {
        *(dst - i) = *(src + i);
    }
}

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
    FFTSample *d = dest;
    int w = w2;
    for (int j = i; j < w; j++)
        d[j] = d[w - (j - i) - 1];
}

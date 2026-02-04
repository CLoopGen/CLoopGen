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
    int start = w;
    int end = w + (w2 - w) / 2;
    for (i = start; i < end; i++) {
        if (i >= 0) {
            dest[i] = dest[2 * w - i - 1];
        }
    }
}

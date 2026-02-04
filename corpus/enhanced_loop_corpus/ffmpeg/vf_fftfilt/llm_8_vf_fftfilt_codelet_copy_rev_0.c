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
    for (i = start; i < end; i += 2) {
        dest[i] = dest[2 * w - i - 1];
        if (i + 1 < end) {
            dest[i + 1] = dest[2 * w - (i + 1) - 1];
        }
    }
}

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
    int trip_count = (w2 - w) / 2;
    for (i = 0; i < trip_count; i++) {
        int src_idx = 2 * w - (w + i) - 1;
        int dst_idx = w + i;
        dest[dst_idx] = dest[src_idx];
    }
}

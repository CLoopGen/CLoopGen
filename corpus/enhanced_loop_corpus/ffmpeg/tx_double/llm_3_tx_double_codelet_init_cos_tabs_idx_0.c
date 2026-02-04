#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride of 2, skipping elements
    int stride = 2;
    int limit = (m / 4) / stride;
    for (int i = 1; i < limit; i++) {
        int src_idx = i * stride;
        tab[m / 2 - src_idx] = tab[src_idx];
    }
}

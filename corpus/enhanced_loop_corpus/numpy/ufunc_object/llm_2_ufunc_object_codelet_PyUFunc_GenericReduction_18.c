#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int naxes;
extern int axes[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element forward, then fill remaining)
    int stride = 2;
    for (i = 0; i < naxes; i += stride) {
        axes[i] = i;
    }
    // Fill the odd indices in a second pass
    for (i = 1; i < naxes; i += stride) {
        axes[i] = i;
    }
}

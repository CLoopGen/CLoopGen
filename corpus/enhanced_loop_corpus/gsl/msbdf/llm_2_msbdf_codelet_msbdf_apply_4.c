#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t * ordprev;
extern size_t * ordprevbackup;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle boundary
    size_t stride = 2;
    for (i = 0; i < 5; i += stride) {
        if (i < 5) ordprevbackup[i] = ordprev[i];
        if (i + 1 < 5) ordprevbackup[i + 1] = ordprev[i + 1];
    }
}

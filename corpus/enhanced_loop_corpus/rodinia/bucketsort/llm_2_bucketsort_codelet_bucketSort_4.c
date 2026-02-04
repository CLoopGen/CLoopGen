#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < (1 << 10); i += 2) {
        if ((h_offsets[i] % 4) != 0)
            h_offsets[i] = (h_offsets[i] & ~3) + 4;
    }
}

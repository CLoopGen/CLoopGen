#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element)
    for (int i = 2; i < (1 << 10); i += 2) {
        h_offsets[i] = h_offsets[i - 2] + h_offsets[i];
    }
}

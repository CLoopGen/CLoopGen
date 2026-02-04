#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward traversal)
    for (int i = 0; i < (1 << 10) - 1; i += 2) {
        if (i + 1 < (1 << 10)) {
            h_offsets[i + 1] = h_offsets[i];
        }
    }
}

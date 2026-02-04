#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *indices;
extern ssize_t i;
extern size_t a;
extern size_t b;
extern unsigned char remapped[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process every other element
    // This changes the access pattern from sequential to strided (i += 2)
    for (i = 0; i < 16; i += 2) {
        ssize_t idx = i;
        if (a < b)
            remapped[idx] = (indices[idx] ^ 1) & 3;
        else if (a == b)
            remapped[idx] = 0;
        else
            remapped[idx] = indices[idx];
        
        // Handle next index within bounds
        idx = i + 1;
        if (idx < 16) {
            if (a < b)
                remapped[idx] = (indices[idx] ^ 1) & 3;
            else if (a == b)
                remapped[idx] = 0;
            else
                remapped[idx] = indices[idx];
        }
    }
}

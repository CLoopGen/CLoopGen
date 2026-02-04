#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offsets[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: offsets[0], offsets[2], offsets[4], offsets[6]
    for (i = 0; i < 8; i += 2)
        offsets[i] = -1;

    // Handle any potential odd-sized cases if needed, but here size is fixed at 8
}

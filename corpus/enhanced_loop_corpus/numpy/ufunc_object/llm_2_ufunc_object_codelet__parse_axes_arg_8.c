#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **remap_axis;
extern int nin;
extern int nop;
extern int iop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal, unrolled by factor of 2
    // This improves spatial locality and allows potential vectorization
    int i;
    for (i = nin; i < nop; i += 2) {
        remap_axis[i] = NULL;
        if (i + 1 < nop) {
            remap_axis[i + 1] = NULL;
        }
    }
}

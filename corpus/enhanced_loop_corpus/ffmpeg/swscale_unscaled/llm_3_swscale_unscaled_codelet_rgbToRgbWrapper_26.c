#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int srcSliceY;
extern int srcSliceH;
extern int dstStride[];
extern uint8_t *dstPtr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index array (simulating irregular access pattern)
    // Assuming we have an external index map, here we simulate it with a simple offset table
    int *indices = (int*)malloc(srcSliceH * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (int j = 0; j < srcSliceH; j++) {
        indices[j] = dstStride[0] * (srcSliceY + j);
    }
    for (i = 0; i < srcSliceH; i++) {
        dstPtr[indices[i]] = 255;
    }
    free(indices);
}

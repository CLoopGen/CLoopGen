#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Forward Access with Base Offset
    // Reorganize access pattern to use a base pointer offset and strictly consecutive reads
    // Introduce local pointer to simplify access and simulate different memory traversal
    int *base = &(PredPel[1]); // Base shifted to PredPel[1] to allow safe indexing from i=2
    for (i = 2; i < 16; i++) {
        int idx = i - 2; // Convert loop index to sequential offset into base array
        LoopArray[i] = (base[idx] + (base[idx + 1] << 1) + base[idx + 2] + 2) >> 2;
    }
}

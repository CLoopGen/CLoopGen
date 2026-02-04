#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int inv_reg_alloc_order[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two iterations per loop step
    for (i = 0; i < 53; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;
        if (idx1 < 53)
            inv_reg_alloc_order[reg_alloc_order[idx1]] = idx1;
        if (idx2 < 53)
            inv_reg_alloc_order[reg_alloc_order[idx2]] = idx2;
    }
}

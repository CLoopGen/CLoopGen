#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int intra_pred_mode;
extern int candidate[3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 1 (equivalent to original but expressed differently)
    // Here we maintain logical equivalence but emphasize strided traversal by using pointer arithmetic
    int *ptr = candidate;
    for (i = 0; i < 3; i++, ptr++) {
        if (intra_pred_mode >= *ptr)
            intra_pred_mode++;
    }
}

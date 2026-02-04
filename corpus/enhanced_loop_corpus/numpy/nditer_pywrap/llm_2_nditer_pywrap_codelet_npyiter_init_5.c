#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nop;
extern int *op_axes_storage;
extern int **op_axes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive blocks of 64 elements per iop,
    // we now access elements with a stride of 128, leaving gaps (simulating sparse or padded layout).
    // This maintains correctness as long as op_axes_storage is sized appropriately.
    int stride = 128;
    for (int iop = 0; iop < nop; ++iop) {
        op_axes[iop] = &op_axes_storage[iop * stride];
    }
}

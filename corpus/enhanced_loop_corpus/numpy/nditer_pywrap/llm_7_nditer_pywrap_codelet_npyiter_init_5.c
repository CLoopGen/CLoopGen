#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nop;
extern int *op_axes_storage;
extern int **op_axes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_offset = 0;
    for (int iop = 0; iop < nop; ++iop) {
        base_offset += 64;
        op_axes[iop] = &op_axes_storage[base_offset - 64];
    }
}

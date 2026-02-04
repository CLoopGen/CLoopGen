#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nop;
extern int *op_axes_storage;
extern int **op_axes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int iop = 1; iop < nop; ++iop) {
        op_axes[iop] = &op_axes_storage[(iop - 1) * 64];
        op_axes[iop - 1] = &op_axes_storage[iop * 64];
    }
    if (nop > 0) {
        op_axes[nop - 1] = &op_axes_storage[(nop - 1) * 64];
    }
}

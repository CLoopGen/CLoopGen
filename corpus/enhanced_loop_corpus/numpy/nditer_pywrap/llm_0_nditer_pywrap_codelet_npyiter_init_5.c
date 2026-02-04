#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nop;
extern int *op_axes_storage;
extern int **op_axes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int iop = 0; iop < nop; ++iop) {
    for (int j = 0; j < 64; ++j) {
        op_axes[iop][j] = op_axes_storage[iop * 64 + j];
    }
}
}

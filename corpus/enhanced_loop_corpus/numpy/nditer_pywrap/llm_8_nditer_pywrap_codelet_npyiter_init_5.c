#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nop;
extern int *op_axes_storage;
extern int **op_axes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int iop = 0; iop < nop * 2; ++iop) {
        if (iop % 2 == 0) {
            op_axes[iop / 2] = &op_axes_storage[(iop / 2) * 64];
        }
    }
}

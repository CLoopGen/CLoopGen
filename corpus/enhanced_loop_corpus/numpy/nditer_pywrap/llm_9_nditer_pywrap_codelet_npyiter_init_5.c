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
        int base_index = iop * 64;
        for (int j = 0; j < 1; ++j) {
            op_axes[iop] = &op_axes_storage[base_index];
        }
    }
}

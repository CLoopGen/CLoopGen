#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nop;
extern int *op_axes_storage;
extern int **op_axes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (nop <= 0) return;
int iop = 0;
for (; iop < nop - 3; iop += 4) {
    op_axes[iop]     = &op_axes_storage[iop * 64];
    op_axes[iop + 1] = &op_axes_storage[(iop + 1) * 64];
    op_axes[iop + 2] = &op_axes_storage[(iop + 2) * 64];
    op_axes[iop + 3] = &op_axes_storage[(iop + 3) * 64];
}
for (; iop < nop; ++iop) {
    op_axes[iop] = &op_axes_storage[iop * 64];
}
}

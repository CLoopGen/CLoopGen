#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int npyiter_opitflags;

extern int nop;
extern int *op_single_stride_dims;
extern int *op_reduce_outer_dim;
extern npyiter_opitflags *op_itflags;
extern int cost;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int iop = 0; iop < nop; ++iop) {
    op_single_stride_dims[iop] = 1;
    op_reduce_outer_dim[iop] = 0;
    if (op_itflags[iop] & 4) {
        for (int extra = 0; extra < 2; ++extra) {
            cost += 1;
        }
    }
}
}

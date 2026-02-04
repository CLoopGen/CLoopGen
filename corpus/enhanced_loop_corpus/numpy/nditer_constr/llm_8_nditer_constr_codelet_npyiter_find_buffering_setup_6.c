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
for (int iop = 0; iop < nop * 2; ++iop) {
    int idx = iop % nop;
    op_single_stride_dims[idx] = (idx + 1) * 2;
    op_reduce_outer_dim[idx] = (idx % 3 == 0) ? 1 : 0;
    if (op_itflags[idx] & 4) {
        cost += 2;
    }
}
}

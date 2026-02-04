#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nin;
extern int i;
extern int nop;
extern int iter_ndim;
extern int op_core_num_dims[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_iter = iter_ndim;
    for (i = nin; i < nop; ++i) {
        local_iter = local_iter + op_core_num_dims[i];
    }
    iter_ndim = local_iter;
}

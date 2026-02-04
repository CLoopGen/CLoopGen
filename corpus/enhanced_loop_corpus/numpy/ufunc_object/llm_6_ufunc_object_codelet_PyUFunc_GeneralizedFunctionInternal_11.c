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
    int temp_iter = 0;
    for (i = nin; i < nop; ++i) {
        temp_iter += op_core_num_dims[i];
    }
    iter_ndim += temp_iter;
}

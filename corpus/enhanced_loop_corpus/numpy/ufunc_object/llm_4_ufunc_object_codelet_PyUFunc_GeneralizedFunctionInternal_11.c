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
for (i = nin; i < nop; ++i) {
    if (op_core_num_dims[i] > 0) {
        iter_ndim += op_core_num_dims[i];
    }
}
}

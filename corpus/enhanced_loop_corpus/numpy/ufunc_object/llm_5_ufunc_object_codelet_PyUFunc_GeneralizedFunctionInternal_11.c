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
if (nin < nop) {
    for (i = nin; i < nop; ++i) {
        if (i % 2 == 0) {
            iter_ndim += op_core_num_dims[i];
        }
    }
} else {
    iter_ndim += 0;
}
}

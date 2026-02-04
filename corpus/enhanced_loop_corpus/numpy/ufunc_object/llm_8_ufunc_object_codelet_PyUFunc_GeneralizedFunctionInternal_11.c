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
    int temp = 0;
    for (i = nin; i < nop; i += 2) {
        if (i + 1 < nop) {
            temp += op_core_num_dims[i] + op_core_num_dims[i + 1];
        } else {
            temp += op_core_num_dims[i];
        }
    }
    iter_ndim += temp;
}

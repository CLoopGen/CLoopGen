#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nin;
extern int i;
extern int nop;
extern int op_core_num_dims[32];
extern int num_dims;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = nin; i < nop; ++i) {
        if (i % 2 == 0) {
            op_core_num_dims[i] = num_dims;
        } else {
            op_core_num_dims[i] = 0;
        }
    }
}

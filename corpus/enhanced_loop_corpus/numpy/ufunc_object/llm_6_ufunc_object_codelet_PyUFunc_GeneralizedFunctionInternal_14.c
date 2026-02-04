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
    int temp = num_dims;
    for (i = nin; i < nop; ++i) {
        op_core_num_dims[i] = temp;
    }
}

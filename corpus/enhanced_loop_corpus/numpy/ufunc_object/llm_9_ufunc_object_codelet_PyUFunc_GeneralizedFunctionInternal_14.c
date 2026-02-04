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
    for (i = nin; i < nop && i < nin + 16; ++i) {
        int temp = num_dims + i - nin;
        op_core_num_dims[i] = temp * temp;
    }
}

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nin;
int i;
int nop;
int op_core_num_dims[32];
int num_dims;

void init_vars() {
    nin = 0;
    num_dims = 5;
    nop = 32;
    for (int j = 0; j < 32; ++j) {
        op_core_num_dims[j] = 0;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nin;
int i;
int nop;
int iter_ndim;
int op_core_num_dims[32];

void init_vars() {
    nin = 0;
    nop = 32;
    iter_ndim = 0;
    for (int idx = 0; idx < 32; ++idx) {
        op_core_num_dims[idx] = rand() % 10 + 1;
    }
}
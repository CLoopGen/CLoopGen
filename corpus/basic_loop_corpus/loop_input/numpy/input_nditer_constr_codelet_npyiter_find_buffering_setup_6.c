#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int npyiter_opitflags;

int nop = 1000000;
int *op_single_stride_dims;
int *op_reduce_outer_dim;
npyiter_opitflags *op_itflags;
int cost = 0;

void init_vars() {
    op_single_stride_dims = (int*)calloc(nop, sizeof(int));
    op_reduce_outer_dim = (int*)calloc(nop, sizeof(int));
    op_itflags = (npyiter_opitflags*)calloc(nop, sizeof(npyiter_opitflags));

    for (int i = 0; i < nop; ++i) {
        op_itflags[i] = (i % 7 == 0) ? 4 : 0;
    }
}
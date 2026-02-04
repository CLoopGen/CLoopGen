#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nop = 4096;
int *op_axes_storage;
int **op_axes;

void init_vars() {
    op_axes_storage = (int *)aligned_alloc(64, nop * 64 * sizeof(int));
    op_axes = (int **)aligned_alloc(64, nop * sizeof(int *));

    for (int i = 0; i < nop * 64; ++i) {
        op_axes_storage[i] = 0;
    }

    for (int i = 0; i < nop; ++i) {
        op_axes[i] = &op_axes_storage[i * 64];
    }
}
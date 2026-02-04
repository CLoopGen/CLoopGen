#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int axis = 3;
int op_axes_arrays[3][64];
int idim = 0;
int ndim = 64;

void init_vars() {
    axis = 3;
    ndim = 64;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 64; ++j) {
            op_axes_arrays[i][j] = 0;
        }
    }
}
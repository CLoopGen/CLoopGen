#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int op_axes_arrays[2][64];
int idim;
int ndim;

void init_vars() {
    ndim = 64; // Set ndim to match the declared array size to prevent out-of-bounds access
}
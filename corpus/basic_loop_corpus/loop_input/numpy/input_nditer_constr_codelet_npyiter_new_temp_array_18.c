#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int op_ndim = 5;
npy_intp *shape;
npy_intp strides[64];
int i;
npy_intp factor = 1;
npy_intp itemsize = 8;
npy_intp new_strides[64];

void init_vars() {
    shape = (npy_intp *)malloc(op_ndim * sizeof(npy_intp));
    if (!shape) {
        exit(1);
    }

    npy_intp total_size = 1 << 23; // ~8MB of data (assuming itemsize=8)
    npy_intp base_dim_size = total_size;
    for (int d = 0; d < op_ndim; ++d) {
        npy_intp dim_size = base_dim_size > 1 ? (npy_intp)(total_size / (1 << (op_ndim - d))) : 1;
        if (dim_size < 1) dim_size = 1;
        shape[d] = dim_size;
        base_dim_size /= dim_size;
    }

    for (int d = 0; d < op_ndim; ++d) {
        if (d == 0) {
            strides[d] = (npy_intp)9223372036854775807L;
        } else {
            strides[d] = (rand() % 2) ? (npy_intp)9223372036854775807L : rand() % (1024 * 1024);
        }
    }

    factor = 1;
    itemsize = 8;

    for (int d = 0; d < 64; ++d) {
        new_strides[d] = 0;
    }
}
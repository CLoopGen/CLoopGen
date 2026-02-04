#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef unsigned char npy_bool;

int nd;
int j;
npy_intp size;
npy_intp i;
npy_bool *ptr;
npy_intp coords[64];
npy_intp dims_m1[64];
npy_intp *dptr[64];

void init_vars() {
    nd = 4;
    size = 1 << 20; // 1M iterations for ~0.01 sec runtime on modern CPU

    ptr = (npy_bool *)aligned_alloc(64, sizeof(npy_bool) * size);
    for (i = 0; i < size; i++) {
        ptr[i] = (i & 7) ? 0 : 1; // every 8th element is true
    }

    for (j = 0; j < nd; j++) {
        coords[j] = 0;
        dims_m1[j] = (1 << (nd - j)) - 1; // e.g., [15,7,3,1] for nd=4
    }
    for (; j < 64; j++) {
        dims_m1[j] = 0;
    }

    for (j = 0; j < nd; j++) {
        dptr[j] = (npy_intp *)aligned_alloc(64, sizeof(npy_intp) * size);
    }
    for (; j < 64; j++) {
        dptr[j] = NULL;
    }
}
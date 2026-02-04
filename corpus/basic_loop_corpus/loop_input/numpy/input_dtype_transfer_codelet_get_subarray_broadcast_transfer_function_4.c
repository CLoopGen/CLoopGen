#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

typedef struct {
    npy_intp offset;
    npy_intp count;
} _subarray_broadcast_offsetrun;

npy_intp dst_size = 10000000;
npy_intp loop_index;
npy_intp run;
npy_intp run_size;
_subarray_broadcast_offsetrun *offsetruns;

void init_vars() {
    offsetruns = malloc(dst_size * sizeof(_subarray_broadcast_offsetrun));
    if (!offsetruns) {
        exit(1);
    }

    // Initialize the first element
    offsetruns[0].offset = 0;
    offsetruns[0].count = 0;

    // Fill the rest with a pattern that triggers both branches
    for (npy_intp i = 1; i < dst_size; ++i) {
        if (i % 17 == 0) {
            offsetruns[i].offset = -1;
        } else {
            offsetruns[i].offset = i * 2;
        }
        offsetruns[i].count = 0;
    }

    // Initialize loop variables
    loop_index = 0;
    run = 0;
    run_size = 1;
}
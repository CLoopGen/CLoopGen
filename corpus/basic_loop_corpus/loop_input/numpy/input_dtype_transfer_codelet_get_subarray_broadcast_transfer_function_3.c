#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef struct {
    npy_intp *ptr;
    int len;
} PyArray_Dims;

typedef struct {
    npy_intp offset;
    npy_intp count;
} _subarray_broadcast_offsetrun;

npy_intp dst_size = 1048576; // ~1M iterations for ~0.01 sec runtime

npy_intp src_shape_data[4] = {1, 256, 1, 1024};
PyArray_Dims src_shape = {src_shape_data, 4};

npy_intp dst_shape_data[5] = {1, 256, 1, 1024, 4};
PyArray_Dims dst_shape = {dst_shape_data, 5};

npy_intp loop_index;
npy_intp src_index;
npy_intp dst_index;
npy_intp i;
npy_intp ndim = 5;
_subarray_broadcast_offsetrun *offsetruns;

void init_vars() {
    offsetruns = malloc(dst_size * sizeof(_subarray_broadcast_offsetrun));
    if (!offsetruns) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}
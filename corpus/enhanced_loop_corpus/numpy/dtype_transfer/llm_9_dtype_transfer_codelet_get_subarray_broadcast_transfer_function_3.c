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

extern npy_intp dst_size;
extern PyArray_Dims src_shape;
extern PyArray_Dims dst_shape;
extern npy_intp loop_index;
extern npy_intp src_index;
extern npy_intp dst_index;
extern npy_intp i;
extern npy_intp ndim;
extern _subarray_broadcast_offsetrun *offsetruns;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
npy_intp stride_accum = 1;
npy_intp *src_strides = malloc((src_shape.len) * sizeof(npy_intp));
if (src_shape.len > 0) {
    src_strides[src_shape.len - 1] = 1;
    for (i = src_shape.len - 2; i >= 0; --i) {
        src_strides[i] = src_strides[i + 1] * src_shape.ptr[i + 1];
    }
}
for (loop_index = 0; loop_index < dst_size; ++loop_index) {
    dst_index = loop_index;
    src_index = 0;
    npy_intp running_coord = 0;
    int overflow = 0;
    for (i = ndim - 1; i >= 0; --i) {
        npy_intp coord = 0, shape;
        if (i >= ndim - dst_shape.len) {
            shape = dst_shape.ptr[i - (ndim - dst_shape.len)];
            coord = dst_index % shape;
            dst_index /= shape;
        }
        if (i >= ndim - src_shape.len && !overflow) {
            shape = src_shape.ptr[i - (ndim - src_shape.len)];
            if (shape == 1) {
                coord = 0;
            } else {
                if (coord >= shape) {
                    overflow = 1;
                } else {
                    src_index += src_strides[i - (ndim - src_shape.len)] * coord;
                }
            }
        }
    }
    offsetruns[loop_index].offset = overflow ? -1 : src_index;
}
free(src_strides);
}

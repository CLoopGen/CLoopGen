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
for (loop_index = 0; loop_index < dst_size; loop_index += 2) {
    npy_intp src_factor1 = 1, src_factor2 = 1;
    npy_intp dst_idx1 = loop_index;
    npy_intp dst_idx2 = loop_index + 1;
    npy_intp src_idx1 = 0;
    npy_intp src_idx2 = 0;
    int valid1 = 1, valid2 = 1;

    for (i = ndim - 1; i >= 0; --i) {
        npy_intp coord1 = 0, coord2 = 0, shape;
        if (i >= ndim - dst_shape.len) {
            shape = dst_shape.ptr[i - (ndim - dst_shape.len)];
            coord1 = dst_idx1 % shape;
            dst_idx1 /= shape;
            coord2 = dst_idx2 % shape;
            dst_idx2 /= shape;
        }
        if (i >= ndim - src_shape.len) {
            shape = src_shape.ptr[i - (ndim - src_shape.len)];
            if (shape == 1) {
                coord1 = coord2 = 0;
            } else {
                if (coord1 < shape) {
                    src_idx1 += src_factor1 * coord1;
                    src_factor1 *= shape;
                } else {
                    valid1 = 0;
                }
                if (coord2 < shape) {
                    src_idx2 += src_factor2 * coord2;
                    src_factor2 *= shape;
                } else {
                    valid2 = 0;
                }
            }
        }
    }

    offsetruns[loop_index].offset = valid1 ? src_idx1 : -1;
    if (loop_index + 1 < dst_size) {
        offsetruns[loop_index + 1].offset = valid2 ? src_idx2 : -1;
    }
}
}

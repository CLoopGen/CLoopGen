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
for (loop_index = 0; loop_index < dst_size; ++loop_index) {
    npy_intp src_factor = 1;
    dst_index = loop_index;
    src_index = 0;
    npy_intp temp_offset = 0;
    int valid = 1;
    for (i = ndim - 1; i >= 0 && valid; --i) {
        npy_intp coord = 0, shape;
        if (i >= ndim - dst_shape.len) {
            shape = dst_shape.ptr[i - (ndim - dst_shape.len)];
            coord = dst_index % shape;
            dst_index /= shape;
        }
        if (i >= ndim - src_shape.len) {
            shape = src_shape.ptr[i - (ndim - src_shape.len)];
            if (shape != 1) {
                if (coord >= shape) {
                    valid = 0;
                } else {
                    temp_offset += src_factor * coord;
                    src_factor *= shape;
                }
            }
        }
    }
    offsetruns[loop_index].offset = valid ? temp_offset : -1;
}
}

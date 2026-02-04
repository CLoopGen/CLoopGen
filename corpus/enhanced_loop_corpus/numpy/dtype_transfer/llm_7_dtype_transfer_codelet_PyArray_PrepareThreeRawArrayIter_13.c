#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern npy_intp *out_shape;
extern npy_intp *out_stridesA;
extern npy_intp *out_stridesB;
extern npy_intp *out_stridesC;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp base_shape_i, base_strideA_i, base_strideB_i, base_strideC_i;
    for (j = 1; j < ndim; ++j) {
        base_shape_i = out_shape[i];
        base_strideA_i = out_stridesA[i];
        base_strideB_i = out_stridesB[i];
        base_strideC_i = out_stridesC[i];

        if (base_shape_i == 1) {
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
            out_stridesC[i] = out_stridesC[j];
        } else if (out_shape[j] == 1) {
            continue;
        } else if (base_strideA_i * base_shape_i == out_stridesA[j] && 
                   base_strideB_i * base_shape_i == out_stridesB[j] && 
                   base_strideC_i * base_shape_i == out_stridesC[j]) {
            out_shape[i] = base_shape_i * out_shape[j];
        } else {
            ++i;
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
            out_stridesC[i] = out_stridesC[j];
        }
    }
}

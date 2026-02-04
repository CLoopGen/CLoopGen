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
    npy_intp temp_shape, temp_strideA, temp_strideB, temp_strideC;
    for (j = 1; j < ndim; ++j) {
        temp_shape = out_shape[j];
        temp_strideA = out_stridesA[j];
        temp_strideB = out_stridesB[j];
        temp_strideC = out_stridesC[j];

        if (out_shape[i] == 1) {
            out_shape[i] = temp_shape;
            out_stridesA[i] = temp_strideA;
            out_stridesB[i] = temp_strideB;
            out_stridesC[i] = temp_strideC;
        } else if (temp_shape == 1) {
            continue;
        } else if (out_stridesA[i] * out_shape[i] == temp_strideA && 
                   out_stridesB[i] * out_shape[i] == temp_strideB && 
                   out_stridesC[i] * out_shape[i] == temp_strideC) {
            out_shape[i] *= temp_shape;
        } else {
            ++i;
            out_shape[i] = temp_shape;
            out_stridesA[i] = temp_strideA;
            out_stridesB[i] = temp_strideB;
            out_stridesC[i] = temp_strideC;
        }
    }
}

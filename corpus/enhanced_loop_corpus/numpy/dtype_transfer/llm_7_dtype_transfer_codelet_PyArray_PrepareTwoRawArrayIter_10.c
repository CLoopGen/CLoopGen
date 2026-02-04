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
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp combined_shape;
    npy_intp base_strideA_i, base_strideB_i;

    for (j = 1; j < ndim; ++j) {
        if (out_shape[j] == 1) {
            continue;
        }

        base_strideA_i = out_stridesA[i];
        base_strideB_i = out_stridesB[i];
        combined_shape = out_shape[i];

        if (out_shape[i] == 1) {
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
        }
        else if (base_strideA_i * combined_shape == out_stridesA[j] && base_strideB_i * combined_shape == out_stridesB[j]) {
            out_shape[i] = combined_shape * out_shape[j];
        }
        else {
            ++i;
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
        }
    }
}

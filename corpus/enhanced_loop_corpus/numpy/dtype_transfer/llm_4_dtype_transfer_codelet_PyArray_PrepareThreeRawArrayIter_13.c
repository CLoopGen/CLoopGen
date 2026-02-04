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
    for (j = 1; j < ndim; ++j) {
        if (out_shape[i] == 1) {
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
            out_stridesC[i] = out_stridesC[j];
        }
        else if (out_shape[j] != 1 && 
                 out_stridesA[i] * out_shape[i] == out_stridesA[j] && 
                 out_stridesB[i] * out_shape[i] == out_stridesB[j] && 
                 out_stridesC[i] * out_shape[i] == out_stridesC[j]) {
            out_shape[i] *= out_shape[j];
        }
        else if (out_shape[j] != 1) {
            ++i;
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
            out_stridesC[i] = out_stridesC[j];
        }
    }
}

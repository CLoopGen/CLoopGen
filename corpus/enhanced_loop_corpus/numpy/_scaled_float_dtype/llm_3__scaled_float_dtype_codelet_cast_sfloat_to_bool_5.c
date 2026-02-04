#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef unsigned char npy_bool;

extern  npy_intp strides[];
extern npy_intp N;
extern char *in;
extern char *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp *indices = (npy_intp *)malloc(N * sizeof(npy_intp));
    for (npy_intp i = 0; i < N; i++) {
        indices[i] = i;
    }
    for (npy_intp i = 0; i < N; i++) {
        npy_intp idx = indices[i]; 
        *(npy_bool *)(out + idx * strides[1]) = *(double *)(in + idx * strides[0]) != 0;
    }
    free(indices);
}

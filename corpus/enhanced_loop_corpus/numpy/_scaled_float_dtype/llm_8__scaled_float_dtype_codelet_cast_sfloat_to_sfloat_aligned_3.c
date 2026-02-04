#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp strides[];
extern double factor;
extern npy_intp N;
extern char *in;
extern char *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp i;
    double *out_d = (double *)out;
    double *in_d = (double *)in;
    npy_intp stride_in = strides[0];
    npy_intp stride_out = strides[1];
    
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            out_d[0] = in_d[0] * factor;
            out_d[stride_out / sizeof(double)] = in_d[stride_in / sizeof(double)] * factor;
            in_d = (double *)((char *)in_d + 2 * stride_in);
            out_d = (double *)((char *)out_d + 2 * stride_out);
        } else {
            *(double *)out_d = *(double *)in_d * factor;
        }
    }
}

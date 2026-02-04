#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *rio = NULL;
R *iio = NULL;
R *W = NULL;
stride rs = NULL;
stride vs = NULL;
INT mb = 0;
INT me = 10000;
INT ms = 6;

E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386; // Approximation of sqrt(3)/2

INT m;

void init_vars() {
    // Allocate data arrays with size to target ~10ms computation
    // Each iteration accesses up to vs[5] and rs[5], so we need at least 6 elements in each
    const INT N = 10000; // Number of loop iterations
    const INT vec_size = 6; // vs has indices 0..5
    const INT row_stride_max = 5; // rs has indices 0..5

    // Total memory needed: rio and iio are accessed as [rs[i]] and [vs[j] + rs[k]]
    // Max offset: vs[5] + rs[5] => need at least (max_vs + max_rs + 1) per vector row
    const INT max_offset = vec_size + row_stride_max;

    // Allocate large enough buffers
    const INT buffer_size = N * max_offset;
    rio = (R*)aligned_alloc(sizeof(R), buffer_size * sizeof(R));
    iio = (R*)aligned_alloc(sizeof(R), buffer_size * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), 10 * N * sizeof(R)); // W is indexed up to [9] per iteration, advanced by 10 per step

    if (!rio || !iio || !W) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize rs and vs strides
    rs = (INT*)aligned_alloc(sizeof(INT), vec_size * sizeof(INT));
    vs = (INT*)aligned_alloc(sizeof(INT), vec_size * sizeof(INT));

    if (!rs || !vs) {
        fprintf(stderr, "Stride allocation failed\n");
        exit(1);
    }

    // Set reasonable strides: rs[i] = i, vs[i] = i * max_offset
    for (INT i = 0; i < vec_size; ++i) {
        rs[i] = i;
        vs[i] = i * max_offset;
    }

    // Initialize all data to avoid NaN or extreme values
    for (INT i = 0; i < buffer_size; ++i) {
        rio[i] = sin(i * 0.01);
        iio[i] = cos(i * 0.01);
    }

    // Initialize W: each block of 10 values corresponds to one m
    for (INT i = 0; i < N; ++i) {
        R angle = 2.0 * M_PI * i / N;
        for (INT k = 0; k < 10; ++k) {
            W[i * 10 + k] = cos(angle * k);
        }
    }

    // Set loop bounds
    mb = 0;
    me = N;
    ms = max_offset; // consistent with vs stride
}
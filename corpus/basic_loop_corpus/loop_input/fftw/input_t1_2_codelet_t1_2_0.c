#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
INT m;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(R))

void init_vars() {
    const INT N = 1 << 18; // ~256K elements, adjust for ~0.01s runtime
    mb = 0;
    me = N / 2;
    ms = 2;
    
    ri = (R*)aligned_alloc(32, N * sizeof(R));
    ii = (R*)aligned_alloc(32, N * sizeof(R));
    W = (R*)aligned_alloc(32, 2 * me * sizeof(R));
    rs = (INT*)aligned_alloc(32, N * sizeof(INT));

    if (!ri || !ii || !W || !rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT i = 0; i < N; i++) {
        ri[i] = sin(i * 0.01);
        ii[i] = cos(i * 0.01);
        rs[i] = (i % (N/2)) * 2;
    }

    for (INT i = 0; i < me; i++) {
        W[2*i] = cos(i * M_PI / me);     // Real part of twiddle
        W[2*i+1] = -sin(i * M_PI / me);  // Imaginary part
    }
}
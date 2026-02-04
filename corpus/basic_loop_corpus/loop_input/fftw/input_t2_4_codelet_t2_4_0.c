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
INT mb = 0;
INT me;
INT ms;
INT m;

static size_t data_size;

void init_vars() {
    const INT vector_width = 4;
    const INT n = (1 << 20) / sizeof(R); // ~1MB of scalar elements
    data_size = n;

    me = n / vector_width; 
    ms = vector_width;
    
    ri = (R*)aligned_alloc(32, n * sizeof(R));
    ii = (R*)aligned_alloc(32, n * sizeof(R));
    W = (R*)aligned_alloc(32, me * vector_width * sizeof(R));
    rs = (INT*)aligned_alloc(32, vector_width * sizeof(INT));

    if (!ri || !ii || !W || !rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT i = 0; i < n; ++i) {
        ri[i] = sin(i * 0.01);
        ii[i] = cos(i * 0.01);
    }

    for (INT i = 0; i < me; ++i) {
        R angle = i * 2 * M_PI / n;
        W[i * 4 + 0] = cos(angle);
        W[i * 4 + 1] = sin(angle);
        W[i * 4 + 2] = cos(3 * angle);
        W[i * 4 + 3] = sin(3 * angle);
    }

    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;
}
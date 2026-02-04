#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP250000000;
E KP587785252;
E KP951056516;
E KP559016994;
INT m;

#define ALIGNMENT 32
#define ALIGNED_MALLOC(size) aligned_alloc(ALIGNMENT, (size))

void init_vars() {
    const size_t alignment = ALIGNMENT;
    const INT vector_size = 5; 
    const INT max_iter = 1000000;
    const INT data_size = max_iter * vector_size;

    cr = (R*)ALIGNED_MALLOC((data_size + 10) * sizeof(R));
    ci = (R*)ALIGNED_MALLOC((data_size + 10) * sizeof(R));
    W = (R*)ALIGNED_MALLOC((max_iter * 4 + 10) * sizeof(R));
    rs = (INT*)ALIGNED_MALLOC((vector_size + 10) * sizeof(INT));

    if (!cr || !ci || !W || !rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT i = 0; i < data_size + 10; i++) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }
    for (INT i = 0; i < max_iter * 4 + 10; i++) {
        W[i] = 0.5 + sin(i * 0.1);
    }
    for (INT i = 0; i < vector_size + 10; i++) {
        rs[i] = 1 + (i % 4);
    }

    KP250000000 = 0.25;
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
    KP559016994 = 0.559016994;

    mb = 1;
    me = max_iter;
    ms = vector_size / 2;

    m = mb;
}
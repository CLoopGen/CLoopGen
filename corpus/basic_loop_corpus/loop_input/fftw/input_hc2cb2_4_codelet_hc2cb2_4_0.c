#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
INT m;

static size_t data_size;
static void allocate_aligned(double **ptr, size_t n) {
    *ptr = (double*)aligned_alloc(64, n * sizeof(double));
    if (!*ptr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    memset(*ptr, 0, n * sizeof(double));
}

void init_vars() {
    const double target_time_seconds = 0.01;
    const double est_operations_per_second = 2e9;
    const double ops_per_iteration = 50;
    INT estimated_iterations_for_0_01s = (INT)(target_time_seconds * est_operations_per_second / ops_per_iteration);
    if (estimated_iterations_for_0_01s < 1000) estimated_iterations_for_0_01s = 1000;

    mb = 1;
    me = estimated_iterations_for_0_01s + mb;
    ms = 1;
    m = mb;

    data_size = (me - mb + 10) * 4 + 100;

    allocate_aligned(&Rp, data_size);
    allocate_aligned(&Ip, data_size);
    allocate_aligned(&Rm, data_size);
    allocate_aligned(&Im, data_size);

    size_t w_size = ((me - mb) * 4) + 8;
    allocate_aligned(&W, w_size);

    for (size_t i = 0; i < w_size; ++i) {
        W[i] = sin(i + 1); 
    }

    rs = (INT*)malloc(sizeof(INT) * 2);
    if (!rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    rs[0] = 0;
    rs[1] = 1;

    for (size_t i = 0; i < data_size; ++i) {
        Rp[i] = rand() / (double)RAND_MAX;
        Ip[i] = rand() / (double)RAND_MAX;
        Rm[i] = rand() / (double)RAND_MAX;
        Im[i] = rand() / (double)RAND_MAX;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

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
E KP500000000;
INT m;

static size_t data_size;
static size_t alignment = 32;

void init_vars() {
    const double target_time_seconds = 0.01;
    const double est_iterations_per_sec = 1e9;
    const double est_ops_per_iter = 20;
    const size_t total_ops_target = (size_t)(target_time_seconds * est_iterations_per_sec * est_ops_per_iter);
    data_size = total_ops_target / est_ops_per_iter;

    if (data_size == 0) data_size = 1 << 20; // fallback: 1MB worth

    ms = 1;
    mb = 1;
    me = data_size - 1;
    KP500000000 = 0.5;

    size_t alloc_size = data_size * sizeof(R);

    int ret;
    ret = posix_memalign((void**)&Rp, alignment, alloc_size); if (ret) abort();
    ret = posix_memalign((void**)&Ip, alignment, alloc_size); if (ret) abort();
    ret = posix_memalign((void**)&Rm, alignment, alloc_size); if (ret) abort();
    ret = posix_memalign((void**)&Im, alignment, alloc_size); if (ret) abort();
    ret = posix_memalign((void**)&W,  alignment, (data_size * 2 + 2) * sizeof(R)); if (ret) abort();

    rs = &ms;

    for (size_t i = 0; i < data_size; i++) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = sin(i * 0.02);
        Im[i] = cos(i * 0.02);
    }

    for (size_t i = 0; i < data_size * 2 + 2; i++) {
        W[i] = (i % 2 == 0) ? cos(i * 0.1) : sin(i * 0.1);
    }
}
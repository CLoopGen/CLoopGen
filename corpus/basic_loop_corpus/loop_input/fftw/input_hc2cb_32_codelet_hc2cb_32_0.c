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
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP555570233;
E KP831469612;
E KP980785280;
E KP195090322;
E KP923879532;
E KP382683432;
E KP707106781;
INT m;

void init_vars() {
    const size_t N = 1 << 20;
    const INT vector_size = 16;
    const INT total_size = (N / vector_size) * 62;
    
    Rp = (R*)aligned_alloc(64, N * sizeof(R));
    Ip = (R*)aligned_alloc(64, N * sizeof(R));
    Rm = (R*)aligned_alloc(64, N * sizeof(R));
    Im = (R*)aligned_alloc(64, N * sizeof(R));
    W = (R*)aligned_alloc(64, total_size * sizeof(R));
    rs = (stride)malloc(sizeof(INT));
    
    *rs = 1;
    ms = 1;
    mb = 1;
    me = N / vector_size;
    
    KP555570233 = sin(M_PI / 8.0);
    KP831469612 = cos(M_PI / 8.0);
    KP980785280 = cos(M_PI / 16.0);
    KP195090322 = sin(M_PI / 16.0);
    KP923879532 = cos(M_PI / 8.0) * 0.707106781;
    KP382683432 = sin(M_PI / 8.0) * 0.707106781;
    KP707106781 = 0.707106781;

    for (size_t i = 0; i < N; ++i) {
        Rp[i] = ((double)rand() / RAND_MAX) - 0.5;
        Ip[i] = ((double)rand() / RAND_MAX) - 0.5;
        Rm[i] = ((double)rand() / RAND_MAX) - 0.5;
        Im[i] = ((double)rand() / RAND_MAX) - 0.5;
    }

    for (size_t i = 0; i < total_size; ++i) {
        W[i] = sin(i * M_PI / 32.0);
    }
}
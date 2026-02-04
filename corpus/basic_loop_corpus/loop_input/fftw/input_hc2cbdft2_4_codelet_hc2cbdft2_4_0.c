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

static R *Rp_storage;
static R *Ip_storage;
static R *Rm_storage;
static R *Im_storage;
static R *W_storage;
static INT *rs_storage;

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

void init_vars() {
    const size_t N = (1 << 20) / sizeof(R); // ~1MB of data per array
    const INT vector_size = N / 2;

    Rp_storage = (R*)aligned_alloc(64, N * sizeof(R));
    Ip_storage = (R*)aligned_alloc(64, N * sizeof(R));
    Rm_storage = (R*)aligned_alloc(64, N * sizeof(R));
    Im_storage = (R*)aligned_alloc(64, N * sizeof(R));
    W_storage = (R*)aligned_alloc(64, 6 * vector_size * sizeof(R));
    rs_storage = (INT*)aligned_alloc(64, 2 * sizeof(INT));

    for (size_t i = 0; i < N; ++i) {
        Rp_storage[i] = sin(i * 0.01);
        Ip_storage[i] = cos(i * 0.01);
        Rm_storage[i] = sin(i * 0.02);
        Im_storage[i] = cos(i * 0.02);
    }

    for (size_t i = 0; i < 6 * vector_size; ++i) {
        W_storage[i] = sin(i * 0.1) * 0.5;
    }

    rs_storage[0] = 0;
    rs_storage[1] = 1;

    Rp = Rp_storage;
    Ip = Ip_storage;
    Rm = Rm_storage;
    Im = Im_storage;
    W = W_storage;
    rs = rs_storage;

    mb = 1;
    me = vector_size;
    ms = 1;
}
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

static R *Rp_arr;
static R *Ip_arr;
static R *Rm_arr;
static R *Im_arr;
static R *W_arr;
static INT *rs_arr;

R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;

INT mb;
INT me;
INT ms;

E KP125000000 = 0.125;
E KP500000000 = 0.5;
E KP279508497 = 0.279508497;
E KP293892626 = 0.293892626;
E KP475528258 = 0.475528258;

INT m;

void init_vars() {
    const INT N = 10;
    const INT total_size = 1 << 20; // ~1MB of data for R arrays (each R is 8 bytes)
    const INT stride_size = N;
    const INT complex_size = total_size / (N * 8); // number of complex vectors fitting in ~1MB

    Rp_arr = (R*)aligned_alloc(64, sizeof(R) * N * complex_size);
    Ip_arr = (R*)aligned_alloc(64, sizeof(R) * N * complex_size);
    Rm_arr = (R*)aligned_alloc(64, sizeof(R) * N * complex_size);
    Im_arr = (R*)aligned_alloc(64, sizeof(R) * N * complex_size);
    W_arr = (R*)aligned_alloc(64, sizeof(R) * 38 * complex_size);
    rs_arr = (INT*)aligned_alloc(64, sizeof(INT) * stride_size);

    if (!Rp_arr || !Ip_arr || !Rm_arr || !Im_arr || !W_arr || !rs_arr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT i = 0; i < N * complex_size; ++i) {
        Rp_arr[i] = (R)(i + 1) * 0.01;
        Ip_arr[i] = (R)(i + 1) * 0.02;
        Rm_arr[i] = (R)(i + 1) * 0.03;
        Im_arr[i] = (R)(i + 1) * 0.04;
    }
    for (INT i = 0; i < 38 * complex_size; ++i) {
        W_arr[i] = (R)(i % 38) * 0.001 + 1.0;
    }
    for (INT i = 0; i < stride_size; ++i) {
        rs_arr[i] = (i + 1) * 1;
    }

    Rp = Rp_arr;
    Ip = Ip_arr;
    Rm = Rm_arr;
    Im = Im_arr;
    W = W_arr;
    rs = rs_arr;

    ms = N;
    mb = 1;
    me = complex_size - 1;
}
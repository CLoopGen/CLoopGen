#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Data size: aim for ~64M elements to ensure loop runs about 0.01s on modern CPU
static const INT N = (1 << 24) / sizeof(R); // ~16M doubles (~128MB)

// Allocate arrays with padding to prevent out-of-bounds access
static R *Rp_arr = NULL;
static R *Ip_arr = NULL;
static R *Rm_arr = NULL;
static R *Im_arr = NULL;
static R *W_arr = NULL;

// Stride array
static INT rs_arr[2];

// Global pointers used in loop
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
    // Initialize data arrays
    Rp_arr = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Ip_arr = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Rm_arr = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Im_arr = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W_arr = (R*)aligned_alloc(sizeof(R), (N * 6) * sizeof(R)); // W accessed up to (me-mb)*6

    // Initialize rs stride array
    rs_arr[0] = 0;
    rs_arr[1] = 1; // typical unit stride

    // Set global pointers
    Rp = Rp_arr;
    Ip = Ip_arr;
    Rm = Rm_arr;
    Im = Im_arr;
    W = W_arr;
    rs = rs_arr;

    // Initialize array contents to avoid NaN/inf complications
    for (INT i = 0; i < N; i++) {
        Rp_arr[i] = (R)(i + 1);
        Ip_arr[i] = (R)(-(i + 1));
        Rm_arr[i] = (R)(i % 1000) / 100.0;
        Im_arr[i] = (R)(-(i % 1000)) / 100.0;
    }
    for (INT i = 0; i < N * 6; i++) {
        W_arr[i] = (R)(i % 100) / 50.0;
    }

    // Set loop parameters
    ms = 1;                    // unit stride step
    mb = 1;                    // start index
    me = (N / 2) - 1;          // ensure we don't go out of bounds when accessing rs[1]
    if (me > 100000) me = 100000; // cap to reasonable number to keep runtime ~0.01s

    // Adjust me to ensure: m < me and W + ((me-1) * 6) < W_arr + (N*6)
    // Also need: Rp + ms*(me-mb) < Rp_arr + N, same for others
    INT max_iter = (N - 1) / ms;
    if (me - mb > max_iter) {
        me = mb + max_iter;
    }
}
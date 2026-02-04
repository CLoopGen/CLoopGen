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
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP382683432;
E KP923879532;
E KP707106781;
INT m;

#define N (1 << 18)  // ~196k elements, suitable for ~0.01s runtime with this kernel
#define ALIGN_BYTES 64

void init_vars() {
    const size_t align = ALIGN_BYTES;
    const INT stride_val = 8;
    const INT num_points = N / 8;  // since loop processes 8 points per iteration

    // Allocate aligned memory to prevent issues and mimic FFTW-style layout
    Rp = aligned_alloc(align, sizeof(R) * N);
    Ip = aligned_alloc(align, sizeof(R) * N);
    Rm = aligned_alloc(align, sizeof(R) * N);
    Im = aligned_alloc(align, sizeof(R) * N);
    W = aligned_alloc(align, sizeof(R) * (num_points * 8));  // 8 twiddle factors per iteration
    rs = malloc(sizeof(INT) * 8);

    // Initialize constants
    KP382683432 = sin(M_PI / 8);        // sin(22.5°)
    KP923879532 = sin(M_PI * 3 / 8);     // sin(67.5°)
    KP707106781 = sin(M_PI / 4);         // sin(45°)

    // Set up stride array: rs[i] = i * stride_val
    for (int i = 0; i < 8; i++) {
        rs[i] = i * stride_val;
    }

    // Initialize data arrays with non-zero values to allow meaningful computation
    for (INT i = 0; i < N; i++) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = sin(i * 0.02);
        Im[i] = cos(i * 0.02);
    }

    // Initialize twiddle factors W: each group of 8 values used per loop iteration
    for (INT k = 0; k < num_points; k++) {
        double angle = M_PI * k / (N / 8);
        W[k*8 + 0] = cos(angle);
        W[k*8 + 1] = sin(angle);
        W[k*8 + 2] = cos(angle * 2);
        W[k*8 + 3] = sin(angle * 2);
        W[k*8 + 4] = cos(angle * 3);
        W[k*8 + 5] = sin(angle * 3);
        W[k*8 + 6] = cos(angle * 4);
        W[k*8 + 7] = sin(angle * 4);
    }

    // Set loop bounds
    mb = 1;  // consistent with W initialization: W += (mb-1)*8
    me = num_points;
    ms = stride_val;  // step in Rp, Ip, etc.
}
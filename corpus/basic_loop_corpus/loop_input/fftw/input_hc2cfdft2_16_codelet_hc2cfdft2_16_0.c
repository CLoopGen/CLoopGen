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
E KP461939766;
E KP191341716;
E KP353553390;
E KP500000000;
INT m;

void init_vars() {
    // Initialize constants
    KP461939766 = sin(M_PI / 8.0);
    KP191341716 = sin(M_PI / 16.0);
    KP353553390 = sin(M_PI / 4.0) * sqrt(2.0) / 2.0; // Approximates 1/sqrt(2)
    KP500000000 = 0.5;

    // Set vector size and stride
    ms = 1;
    mb = 1;
    me = 9; // Ensure m goes from 1 to 8 (me > 8)

    // Allocate data arrays with sufficient size to cover all indexed elements
    // Maximum index used: rs[7] -> need at least 8 elements in each array accessed via rs
    size_t N = 16; // Safe upper bound for data arrays

    Rp = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Ip = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Rm = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Im = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), 8 * 8); // W is indexed up to 7, but updated per iteration

    // Allocate and initialize stride vector
    rs = (stride)malloc(8 * sizeof(INT));
    for (int i = 0; i < 8; i++) {
        rs[i] = i * ms; // Ensure valid offsets
    }

    // Initialize W array with cosine/sine pairs for angles: 0, pi/8, pi/4, 3pi/8
    double angle;
    for (int i = 0; i < 8; i += 2) {
        angle = i * M_PI / 8.0;
        W[i] = cos(angle);
        W[i+1] = sin(angle);
    }

    // Initialize data arrays to non-zero values to avoid degenerate math
    for (size_t i = 0; i < N; i++) {
        Rp[i] = 1.0 + i * 0.1;
        Ip[i] = 1.0 - i * 0.1;
        Rm[i] = 2.0 + i * 0.05;
        Im[i] = 2.0 - i * 0.05;
    }
}
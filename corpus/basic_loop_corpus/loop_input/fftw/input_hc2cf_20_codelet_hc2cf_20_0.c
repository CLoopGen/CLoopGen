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
E KP587785252;
E KP951056516;
E KP250000000;
E KP559016994;
INT m;

void init_vars() {
    // Initialize constants
    KP587785252 = 0.587785252;  // approx sin(2*pi/10)
    KP951056516 = 0.951056516;  // approx sin(4*pi/10)
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;  // approx sqrt(5)/4

    // Configuration parameters
    ms = 1;                    // stride step
    mb = 1;                    // loop starts at mb=1
    me = 100000;               // adjust to get ~0.01s runtime (tuned for typical CPU)

    // Allocate arrays with sufficient size to avoid out-of-bounds access
    // Maximum index used: rs[i] up to rs[9], and W accessed up to offset 37
    // We assume rs values are within safe bounds, allocate buffer accordingly

    INT vector_size = 20;      // allow indexing up to rs[9] safely
    INT w_size = (me - mb + 1) * 38 + 40;  // W accessed with (mb-1)*38 and up to +37 per iteration
    INT data_size = me * abs(ms) + vector_size + 10;  // extra padding for Rp, Ip, Rm, Im

    Rp = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    Ip = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    Rm = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    Im = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), w_size * sizeof(R));

    // Allocate and initialize stride array
    rs = (INT*)malloc(vector_size * sizeof(INT));
    for (INT i = 0; i < vector_size; i++) {
        rs[i] = i;  // simple unit strides for testing; avoids negative or wild offsets
    }

    // Initialize all data arrays to prevent NaNs or undefined behavior
    for (INT i = 0; i < data_size; i++) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = sin(i * 0.02);
        Im[i] = cos(i * 0.02);
    }
    for (INT i = 0; i < w_size; i++) {
        W[i] = sin(i * 0.1) * 0.5 + 0.5;
    }
}
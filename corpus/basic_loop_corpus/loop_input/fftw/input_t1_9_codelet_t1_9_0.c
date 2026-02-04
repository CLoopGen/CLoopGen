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
R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP939692620;
E KP342020143;
E KP984807753;
E KP173648177;
E KP642787609;
E KP766044443;
E KP500000000;
E KP866025403;
INT m;

void init_vars() {
    // Initialize constants
    KP939692620 = 0.9396926207859084; // cos(20°)
    KP342020143 = 0.3420201433256687; // sin(20°)
    KP984807753 = 0.984807753012208;  // cos(10°)
    KP173648177 = 0.17364817766693033;// sin(10°)
    KP642787609 = 0.6427876096865393; // cos(50°)
    KP766044443 = 0.766044443118978;  // cos(40°)
    KP500000000 = 0.5;
    KP866025403 = 0.8660254037844386; // sqrt(3)/2 ≈ cos(30°)

    // Define data size: aim for ~64K complex elements to ensure ~0.01s runtime
    const INT N = 1 << 16; // 65536 elements
    const INT W_size = N * 16; // W array has 16 entries per iteration, but reused

    // Allocate arrays
    ri = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    ii = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W  = (R*)aligned_alloc(sizeof(R), W_size * sizeof(R));

    // Allocate and initialize stride array
    rs = (stride)malloc(9 * sizeof(INT));
    for (INT i = 0; i < 9; ++i) {
        rs[i] = i * (N / 9); // Ensure access within bounds
    }

    // Initialize input data with non-zero values to avoid trivial computation
    for (INT i = 0; i < N; ++i) {
        ri[i] = sin(i * 0.01);
        ii[i] = cos(i * 0.01);
    }

    // Initialize twiddle factors in W: simulate 16 real numbers per m
    for (INT i = 0; i < W_size; ++i) {
        W[i] = sin((i % 16) * 0.1 + i / 16 * 0.001);
    }

    // Set loop bounds
    mb = 0;
    me = N / 9; // Ensure rs indices don't exceed array bounds
    ms = 1;     // stride increment for ri and ii
}
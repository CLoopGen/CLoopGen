#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *rio;
R *iio;
R *W;
stride rs;
stride vs;
INT mb;
INT me;
INT ms;
E KP866025403 = 0.8660254037844386; // Approximation of sqrt(3)/2
E KP500000000 = 0.5;
INT m;

// Allocate sufficient data to make loop run ~0.01s
// Based on typical performance, aim for ~16-32M iterations
// Each iteration accesses multiple vectors; set me-mb ~ 8M
#define DATA_SIZE (1 << 24)  // ~16M elements per array
#define STRIDE_SIZE 3

void init_vars() {
    // Allocate large arrays to ensure meaningful runtime
    rio = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    iio = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    W   = (R*)aligned_alloc(sizeof(R), 4 * sizeof(R));

    // Initialize W values: used as [0], [1], [2], [3]
    W[0] = 1.0;
    W[1] = 0.0;
    W[2] = -0.5;
    W[3] = 0.8660254037844386;

    // Allocate and initialize stride arrays
    rs = (stride)aligned_alloc(sizeof(INT), STRIDE_SIZE * sizeof(INT));
    vs = (stride)aligned_alloc(sizeof(INT), STRIDE_SIZE * sizeof(INT));

    // Set reasonable strides: assume unit strides for simplicity
    rs[0] = 0; rs[1] = 1; rs[2] = 2;
    vs[0] = 0; vs[1] = DATA_SIZE / 8; vs[2] = 2 * (DATA_SIZE / 8);

    // Ensure all memory accesses are within bounds
    // Maximum index used: 
    //   rio[(vs[2]) + (rs[2])] -> vs[2] + rs[2] = 2*(DATA_SIZE/8)+2
    // Choose me so that max index < DATA_SIZE
    mb = 0;
    ms = 1;
    me = (DATA_SIZE / (vs[2] + 3)) - 1;  // conservative bound
    if (me > 8000000) me = 8000000;       // cap iterations for ~0.01s runtime
    if (me <= mb) me = mb + 1;

    // Initialize input arrays to prevent NaN/inf issues
    for (INT i = 0; i < DATA_SIZE; ++i) {
        rio[i] = (R)(i % 100) / 100.0;
        iio[i] = (R)((i + 10) % 100) / 100.0;
    }
}
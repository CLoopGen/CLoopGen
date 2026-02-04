#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
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
E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386; // approx sqrt(3)/2
INT m;

void init_vars() {
    const INT N = 100000; // Adjust to control runtime (~0.01 sec on modern CPU)

    mb = 0;
    me = N;
    ms = 6; // stride for ri and ii arrays (max rs[i] used is rs[5])
    m = mb;

    // Allocate rs with size 6 to cover rs[0] to rs[5]
    rs = (stride)aligned_alloc(sizeof(INT), 6 * sizeof(INT));
    if (!rs) exit(1);
    for (INT i = 0; i < 6; ++i) {
        rs[i] = i; // rs[i] maps logical index to memory offset
    }

    // Allocate ri and ii with sufficient size: max access is rs[5] => index 5
    // Each loop iteration accesses ri[rs[i]], so we need at least max(rs[i])+1 per block
    // With ms=6, and loop running N times, total size = ms * N + max_offset
    const INT max_offset = 5;
    const INT total_size = ms * N + max_offset;

    ri = (R*)aligned_alloc(sizeof(R), total_size * sizeof(R));
    ii = (R*)aligned_alloc(sizeof(R), total_size * sizeof(R));
    if (!ri || !ii) exit(1);

    for (INT i = 0; i < total_size; ++i) {
        ri[i] = (R)(rand() % 100) / 100.0;
        ii[i] = (R)(rand() % 100) / 100.0;
    }

    // W is accessed as W[0..9], incremented by 10 per loop
    // So total size needed: (me - mb) * 10 + 10 = N * 10 + 10
    W = (R*)aligned_alloc(sizeof(R), (N * 10 + 10) * sizeof(R));
    if (!W) exit(1);

    // Precompute twiddle factors for each iteration
    for (INT i = 0; i < N; ++i) {
        R angle_base = 2.0 * M_PI * i / N;
        for (INT k = 0; k < 6; ++k) {
            R angle = k * angle_base;
            W[i * 10 + 2*k + 0] = cos(angle);
            W[i * 10 + 2*k + 1] = sin(angle);
        }
    }

    // Ensure initial W pointer offset: W starts at W + mb*10 = W + 0
    W = W + (mb * 10);
}
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
R *ri;
R *ii;
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

    // Problem size: aim for ~100ms runtime
    // The loop runs (me - mb) iterations, each accessing up to rs[9]
    // We need to ensure ri, ii have enough elements with stride access
    const INT total_size = 1 << 20; // ~1M elements per array
    const INT alignment = 64;

    // Allocate aligned memory for ri and ii
    ri = aligned_alloc(alignment, total_size * sizeof(R));
    ii = aligned_alloc(alignment, total_size * sizeof(R));
    W = aligned_alloc(alignment, (total_size * 6) * sizeof(R)); // W is accessed at offset m*6

    if (!ri || !ii || !W) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize rs as an array of strides
    rs = malloc(10 * sizeof(INT));
    if (!rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Set reasonable strides: unit stride for simplicity
    for (int i = 0; i < 10; i++) {
        rs[i] = i;  // so rs[i] = i, meaning we access ri[i], ri[1], ..., ri[9]
    }

    // Ensure that the maximum index used in the loop does not exceed bounds
    // In loop: ri[(rs[9])] -> ri[9] when rs[9]=9
    // We'll set data range so that all such accesses are valid

    // Initialize data arrays with random-like values
    for (INT i = 0; i < total_size; i++) {
        ri[i] = sin(i * 0.01);
        ii[i] = cos(i * 0.01);
    }
    for (INT i = 0; i < total_size * 6; i++) {
        W[i] = sin(i * 0.001);
    }

    // Set loop parameters
    mb = 0;
    me = total_size;  // number of iterations
    ms = 1;           // increment for ri and ii pointers per iteration

    // Validate that during last iteration:
    // m == me-1, then W = W + (mb*6) + (me-mb-1)*6 = W + (me-1)*6
    // So W must be at least (me)*6 in size -> satisfied

    // Also check ri[ii] accesses: max index via rs[9] is 9
    // But ri and ii are incremented by ms each iteration
    // After k iterations: ri points to original + k*ms
    // At iteration k, access ri[(rs[9])] = ri[k*ms + rs[9]]
    // Maximum k = me-1, so max index = (me-1)*ms + 9
    // Our ri has size total_size, so require: (me-1)*ms + 9 < total_size
    // With me = total_size, ms=1 -> needs total_size-1+9 < total_size -> fails!
    
    // Fix: reduce me so that max index stays in bounds
    // Let max_index = (me - 1) * ms + 9 < total_size
    // With ms=1: me <= total_size - 9
    me = total_size - 9;

    // Ensure W has enough space: final access is W + (me-1)*6 + 5 (for W[5])
    // Initial W offset: mb*6 = 0
    // Final: (me-1)*6 + 5 = (total_size - 10)*6 + 5 < total_size*6 -> OK
}
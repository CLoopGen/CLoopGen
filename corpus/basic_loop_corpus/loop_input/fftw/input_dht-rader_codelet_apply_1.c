#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT npad = 0;
INT k = 0;
R *buf = NULL;
R *omega = NULL;

void init_vars() {
    const INT target_time_ns = 10000000;  // ~10 ms in nanoseconds
    const double cpu_freq_giga = 3.0;     // Assume 3 GHz processor
    const double operations_per_cycle = 1; // Rough estimate for scaling
    const double estimated_ops_per_iter = 10;

    // Scale problem size based on estimated runtime
    INT estimated_iters = (target_time_ns / (cpu_freq_giga * estimated_ops_per_iter * operations_per_cycle));
    npad = (estimated_iters * 2) + 1;

    // Ensure npad is at least 4 and a valid size
    if (npad < 4) npad = 4;

    // Make npad even so that npad/2 is valid and indexing works
    npad = ((npad + 1) / 2) * 2;

    // Allocate buffers
    buf = (R*)aligned_alloc(sizeof(R), npad * sizeof(R));
    omega = (R*)aligned_alloc(sizeof(R), npad * sizeof(R));

    if (!buf || !omega) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buf and omega arrays
    for (INT i = 0; i < npad; ++i) {
        buf[i] = (R)(i % 100) / 100.0;
        omega[i] = (R)sin(i) * 0.5;
    }
}
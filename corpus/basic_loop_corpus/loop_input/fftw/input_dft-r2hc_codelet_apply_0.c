#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *ro;
R *io;
INT n;
INT i;
INT os;

void init_vars() {
    // Set parameters to achieve approximately 0.01 seconds runtime
    // Based on typical performance, aim for ~64M elements for double precision
    n = 1 << 25; // 33,554,432 elements -> total array size ~256MB (two arrays)
    os = 1;      // stride factor

    // Allocate memory
    ro = (R*)aligned_alloc(32, sizeof(R) * (n + 1));
    io = (R*)aligned_alloc(32, sizeof(R) * (n + 1));

    // Initialize arrays with non-zero values to avoid compiler dead code elimination
    for (INT idx = 0; idx <= n; ++idx) {
        ro[idx] = sin(idx * 0.001);
        io[idx] = cos(idx * 0.001);
    }
}

// Explicitly define extern symbols
R *ro;
R *io;
INT n;
INT i;
INT os;
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *ro;
R *io;
INT os;
INT k;
INT r;
R *omega;

void init_vars() {
    // Set parameters
    r = 1 << 20;  // ~1 million iterations to target ~0.01s runtime
    os = 1;       // stride factor for ro/io indexing

    // Allocate arrays with sufficient size: indices go up to (r-1)*os, so need at least (r-1)+1 = r elements
    ro = (R*)aligned_alloc(32, r * sizeof(R));
    io = (R*)aligned_alloc(32, r * sizeof(R));
    omega = (R*)aligned_alloc(32, 2 * r * sizeof(R));  // omega indexed up to 2*k where k < r-1 -> max index 2*(r-2)+1 ~ 2*r

    // Initialize ro and io with non-zero values to avoid trivial computations
    for (INT i = 0; i < r; ++i) {
        ro[i] = (R)(i + 1);
        io[i] = (R)(-(i + 1));
    }

    // Initialize omega as complex unit roots: omega[2*k] = cos(theta), omega[2*k+1] = sin(theta)
    // Use varying angles to prevent optimization via constant folding
    for (INT k_idx = 0; k_idx < r; ++k_idx) {
        double angle = 2.0 * M_PI * k_idx / r;
        omega[2 * k_idx]     = cos(angle);
        omega[2 * k_idx + 1] = sin(angle);
    }

    // Ensure k is initialized by loop, but define initial state per C rules
    k = 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <inttypes.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// External pointers and scalars
R *Rp = NULL;
R *Ip = NULL;
R *Rm = NULL;
R *Im = NULL;
R *W = NULL;
stride rs = NULL;
INT mb = 0;
INT me = 0;
INT ms = 0;
E KP277785116 = 0.277785116;
E KP415734806 = 0.415734806;
E KP097545161 = 0.097545161;
E KP490392640 = 0.490392640;
E KP707106781 = 0.707106781;
E KP191341716 = 0.191341716;
E KP461939766 = 0.461939766;
E KP353553390 = 0.353553390;
E KP500000000 = 0.500000000;
INT m = 0;

void init_vars() {
    const size_t N = 16;  // Fixed transform size implied by indexing pattern (e.g., rs[15])
    const size_t data_size = 256 * 1024 * 1024; // ~256MB total data to ensure runtime ~0.01s
    const size_t vector_count = data_size / (N * sizeof(R) * 4); // 4 arrays: Rp, Ip, Rm, Im
    const size_t actual_data_size = vector_count * N * sizeof(R);

    // Allocate memory for real and imaginary parts with padding
    Rp = aligned_alloc(64, actual_data_size + 64);
    Ip = aligned_alloc(64, actual_data_size + 64);
    Rm = aligned_alloc(64, actual_data_size + 64);
    Im = aligned_alloc(64, actual_data_size + 64);
    W = aligned_alloc(64, 8 * sizeof(R)); // W has at least 8 elements accessed as W[0]..W[7]

    // Allocate and initialize stride array
    rs = malloc(N * sizeof(INT));
    
    if (!Rp || !Ip || !Rm || !Im || !W || !rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize W values used in loop: W[0] to W[7]
    W[0] = 1.0;
    W[1] = 0.980785; // cos(π/8)
    W[2] = 0.923879; // cos(2π/8)
    W[3] = 0.831470; // cos(3π/8)
    W[4] = 0.707107; // cos(4π/8)
    W[5] = 0.555570; // cos(5π/8)
    W[6] = 0.382683; // cos(6π/8)
    W[7] = 0.195090; // cos(7π/8)

    // Initialize stride: unit stride of 1
    for (INT i = 0; i < N; ++i) {
        rs[i] = i;
    }

    // Set loop parameters
    mb = 1;         // loop starts at mb
    me = 1;         // initially no iterations
    ms = 1;         // step size

    // Only enable one iteration block that fits within bounds
    if (vector_count > 0) {
        me = mb + 1;  // Run exactly one iteration to stay safe
    }

    // Initialize data arrays to non-zero to avoid degenerate math
    for (size_t i = 0; i < actual_data_size / sizeof(R); ++i) {
        Rp[i] = (R)(i + 1) * 0.001;
        Ip[i] = (R)(i + 1) * 0.002;
        Rm[i] = (R)(i + 1) * 0.003;
        Im[i] = (R)(i + 1) * 0.004;
    }
}
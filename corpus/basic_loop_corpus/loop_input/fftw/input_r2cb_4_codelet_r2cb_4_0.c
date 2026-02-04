#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Determine data size for ~0.01 sec runtime: assume moderate CPU, aim for ~64M iterations
// Each iteration touches several arrays with small strides; use vector size around 64M elements
static const size_t N = (1 << 24) / sizeof(R); // ~16M elements (~128 MB total)

R *R0 = NULL;
R *R1 = NULL;
R *Cr = NULL;
R *Ci = NULL;
stride rs = NULL;
stride csr = NULL;
stride csi = NULL;

INT v = 0;
INT ivs = 1;
INT ovs = 1;
E KP2_000000000 = 2.0;
INT i = 0;

void init_vars() {
    // Allocate large arrays to ensure loop takes measurable time
    Cr = (R*)aligned_alloc(64, N * sizeof(R));
    Ci = (R*)aligned_alloc(64, N * sizeof(R));
    R0 = (R*)aligned_alloc(64, N * sizeof(R));
    R1 = (R*)aligned_alloc(64, N * sizeof(R));

    if (!Cr || !Ci || !R0 || !R1) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data to avoid NaNs and zeros everywhere
    for (size_t k = 0; k < N; ++k) {
        Cr[k] = sin(k);
        Ci[k] = cos(k);
        R0[k] = 0.0;
        R1[k] = 0.0;
    }

    // Allocate and initialize stride vectors
    rs = (stride)aligned_alloc(64, 4 * sizeof(INT));
    csr = (stride)aligned_alloc(64, 4 * sizeof(INT));
    csi = (stride)aligned_alloc(64, 4 * sizeof(INT));

    if (!rs || !csr || !csi) {
        fprintf(stderr, "Stride allocation failed\n");
        exit(1);
    }

    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3;
    csr[0] = 0; csr[1] = 1; csr[2] = 2; csr[3] = 3;
    csi[0] = 0; csi[1] = 1; csi[2] = 2; csi[3] = 3;

    // Set loop count so that we don't exceed array bounds
    // In loop: access Cr[0], Cr[csr[2]], Cr[csr[1]] -> max index is csr[2] = 2
    // So as long as N > 2, safe. We'll set v = N - 2 to be safe if used as length?
    // But loop decrements i from v to 1, and uses indexed access.
    // However, indexing via csr[1], csr[2] suggests indirect but fixed offsets.

    // Since rs, csr, csi are strided indirectly but values are constant,
    // and maximum index used is 2, we just need at least 3 elements in each data array.

    // To achieve desired runtime, let's set v to a large number: ~16M
    v = (INT)(N / 2);  // Large enough for measurable duration

    // Ensure ovs and ivs are reasonable
    ovs = 1;
    ivs = 1;

    // KP constant
    KP2_000000000 = 2.0 * M_PI / 100.0; // Arbitrary meaningful value
}
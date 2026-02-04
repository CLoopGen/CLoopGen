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

// Define data size to target ~0.01s runtime: use moderate problem size
// Based on loop structure, m goes from mb to me, with stride ms and W accessed at large offsets.
// We need sufficient memory in cr, ci, W to avoid out-of-bounds.

#define N 32            // Size of FFT-like transform (inferred from rs indexing up to 31)
#define M 1000          // Number of iterations (mb=1, me=M+1)

// Allocate larger arrays to cover all rs-indexed accesses safely
#define MAX_OFFSET 62   // W is indexed up to 62 per iteration

R *cr;
R *ci;
R *W;
stride rs;
INT mb = 1;
INT me = M + 1;
INT ms = 1;
E KP555570233 = 0.555570233f;
E KP831469612 = 0.831469612f;
E KP980785280 = 0.980785280f;
E KP195090322 = 0.195090322f;
E KP382683432 = 0.382683432f;
E KP923879532 = 0.923879532f;
E KP707106781 = 0.707106781f;
INT m;

void init_vars() {
    // Allocate cr and ci: each needs at least max(rs[i]) + 1 elements
    // rs indices go up to 31 -> need at least 32 elements per block
    // And we step by ms over M blocks -> total size: M * abs(ms) + max_offset_in_block
    INT cr_ci_size = M * abs(ms) + N;

    cr = (R*)calloc(cr_ci_size, sizeof(R));
    ci = (R*)calloc(cr_ci_size, sizeof(R));
    if (!cr || !ci) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // W has access up to index (mb-1)*62 + 62*(me-mb) = (me - 1)*62
    INT W_size = (me - 1) * MAX_OFFSET + 62;
    W = (R*)malloc(W_size * sizeof(R));
    if (!W) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (INT i = 0; i < W_size; ++i) {
        W[i] = sin(i * 0.1); // arbitrary initialization
    }

    // rs: stride array of length N (0..31 used in code)
    rs = (INT*)malloc(N * sizeof(INT));
    if (!rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    // Set rs[i] = i to match expected addressing pattern (e.g., rs[16], rs[8], etc.)
    for (INT i = 0; i < N; ++i) {
        rs[i] = i;
    }

    // Ensure that during loop:
    // m from mb=1 to me=M
    // W starts at (mb-1)*62 = 0 -> safe
    // cr starts at base, ci starts at base + (M-1)*ms (since decremented)
}
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

// Data size: aim for ~100ms runtime; original loop runs over 'm' from mb to me
// Each iteration processes a fixed amount of data via cr, ci, W with stride rs and large offsets.
// We need to ensure all array accesses are within bounds.

#define DATA_SIZE (1 << 20)  // 1M elements per array, sufficient for deep access with strides

static R *cr_data;
static R *ci_data;
static R *W_data;
static INT *rs_data;

// External symbols
R *cr;
R *ci;
R *W;
stride rs;
INT mb = 1;
INT me;
INT ms = 1;
E KP555570233 = 0.555570233f;
E KP831469612 = 0.831469612f;
E KP980785280 = 0.980785280f;
E KP195090322 = 0.195090322f;
E KP923879532 = 0.923879532f;
E KP382683432 = 0.382683432f;
E KP707106781 = 0.707106781f;
INT m;

void init_vars() {
    // Allocate large enough arrays to handle indexed access like rs[31], cr[rs[28]], etc.
    cr_data = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);
    ci_data = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);
    W_data  = (R*)aligned_alloc(64, sizeof(R) * (DATA_SIZE));  // W accessed up to index 61 + (me-mb)*62
    rs_data = (INT*)aligned_alloc(64, sizeof(INT) * 32);        // rs accessed at indices up to 31

    if (!cr_data || !ci_data || !W_data || !rs_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize rs: must be valid indices into cr and ci arrays
    // Choose positive strides that are within cr_data/ci_data size
    for (int i = 0; i < 32; ++i) {
        rs_data[i] = (i * 16384) % (DATA_SIZE / 4);  // moderate stride, avoid overflow
    }
    rs = rs_data;

    // Set cr and ci base pointers
    cr = cr_data;
    ci = ci_data;

    // me must satisfy: m < me in loop, and W is incremented by 62 per step
    // Initial W = W_data + ((mb - 1) * 62) => when mb=1, W starts at W_data
    // Max m: me-1, so max W offset: (me - mb) * 62 + 61 (since W[61] accessed)
    // So we require: (me - 1) * 62 + 61 < DATA_SIZE
    // Let’s set me such that total iterations ~ 100k → good for benchmarking
    INT num_iterations = 100000;
    me = mb + num_iterations;

    size_t required_W_size = ((me - mb) * 62) + 62;
    if (required_W_size > DATA_SIZE) {
        free(W_data);
        W_data = (R*)aligned_alloc(64, sizeof(R) * required_W_size);
        if (!W_data) {
            fprintf(stderr, "W allocation failed\n");
            exit(1);
        }
    }
    W = W_data;

    // Initialize W with cosine/sine twiddle factors to make computation meaningful
    // Simulate FFT twiddle: W[2*i] = cos(angle), W[2*i+1] = sin(angle)
    for (INT i = 0; i < (INT)required_W_size / 2; ++i) {
        double angle = 2.0 * M_PI * i / 64.0;
        W[2*i]   = cos(angle);
        W[2*i+1] = sin(angle);
    }

    // Initialize cr and ci with random-like data
    for (size_t i = 0; i < DATA_SIZE; ++i) {
        cr_data[i] = sin(i * 0.001);
        ci_data[i] = cos(i * 0.001);
    }

    // Ensure ms is consistent (used in pointer update: cr += ms, ci -= ms)
    ms = 1;

    // Final setup: adjust me to not exceed W bounds
    // W starts at W_data + ((mb-1)*62) = W_data (since mb=1)
    // Last access: W + 61 after (me - mb - 1) steps → index = (me - mb - 1)*62 + 61
    size_t max_W_index = (me - mb - 1) * 62 + 61;
    if (max_W_index >= required_W_size) {
        me = mb + (required_W_size - 61 + 61) / 62;  // conservative bound
    }
}
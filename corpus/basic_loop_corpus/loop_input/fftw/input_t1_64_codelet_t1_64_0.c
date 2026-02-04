#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef R E;
typedef ptrdiff_t INT;
typedef INT *stride;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

static R *ri_data;
static R *ii_data;
static R *W_data;
static INT *rs_data;

R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;

E KP471396736 = 0.471396736;
E KP881921264 = 0.881921264;
E KP290284677 = 0.290284677;
E KP956940335 = 0.956940335;
E KP634393284 = 0.634393284;
E KP773010453 = 0.773010453;
E KP098017140 = 0.098017140;
E KP995184726 = 0.995184726;
E KP555570233 = 0.555570233;
E KP831469612 = 0.831469612;
E KP980785280 = 0.980785280;
E KP195090322 = 0.195090322;
E KP923879532 = 0.923879532;
E KP382683432 = 0.382683432;
E KP707106781 = 0.707106781;

INT m;

void init_vars() {
    const size_t N = 64; // Based on stride access pattern and W indexing up to ~125
    const size_t total_size = 1 << 20; // ~1MB of complex data (adjustable)
    const size_t vec_len = total_size / (N * sizeof(R));
    
    if (vec_len == 0) {
        fprintf(stderr, "Data size too small\n");
        exit(1);
    }

    ri_data = (R*)aligned_alloc(64, total_size * 2 * sizeof(R));
    ii_data = (R*)aligned_alloc(64, total_size * 2 * sizeof(R));
    W_data = (R*)aligned_alloc(64, vec_len * 127 * sizeof(R));
    rs_data = (INT*)aligned_alloc(64, vec_len * N * sizeof(INT));

    if (!ri_data || !ii_data || !W_data || !rs_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size * 2; ++i) {
        ri_data[i] = (R)(rand()) / RAND_MAX;
        ii_data[i] = (R)(rand()) / RAND_MAX;
    }

    for (size_t i = 0; i < vec_len * 127; ++i) {
        W_data[i] = (R)(rand()) / RAND_MAX;
    }

    for (size_t i = 0; i < vec_len * N; ++i) {
        rs_data[i] = (rand() % (N/2)) * 2; // Ensure valid offsets within bounds
    }

    mb = 0;
    me = vec_len;
    ms = N;

    ri = ri_data;
    ii = ii_data;
    W = W_data;
    rs = rs_data;
}
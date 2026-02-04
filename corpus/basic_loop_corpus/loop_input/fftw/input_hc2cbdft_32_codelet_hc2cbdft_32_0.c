#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP831469612;
E KP555570233;
E KP195090322;
E KP980785280;
E KP923879532;
E KP382683432;
E KP707106781;
INT m;

void init_vars() {
    const INT N = 16; // Size of the transform implied by indexing (e.g., rs[15])
    const INT total_size = 1 << 20; // ~1MB per array to target ~0.01s runtime on modern CPU
    const INT num_points = total_size / (N * sizeof(R));
    const INT padded_num_points = (num_points > 0) ? num_points : 1;

    // Allocate arrays with padding to avoid out-of-bounds access
    Rp = (R*)aligned_alloc(sizeof(R), (padded_num_points * N + 64) * sizeof(R));
    Ip = (R*)aligned_alloc(sizeof(R), (padded_num_points * N + 64) * sizeof(R));
    Rm = (R*)aligned_alloc(sizeof(R), (padded_num_points * N + 64) * sizeof(R));
    Im = (R*)aligned_alloc(sizeof(R), (padded_num_points * N + 64) * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), (padded_num_points * 62 + 64) * sizeof(R));

    rs = (INT*)aligned_alloc(sizeof(INT), 16 * sizeof(INT));

    // Initialize stride values: assume unit stride for contiguous data
    for (INT i = 0; i < 16; ++i) {
        rs[i] = i;
    }

    // Initialize constants (common twiddle factors)
    KP831469612 = sin(M_PI / 4.0); // approx 0.7071, but named as in code
    KP555570233 = sin(M_PI / 6.0); // approx 0.5
    KP195090322 = sin(M_PI / 16.0);
    KP980785280 = cos(M_PI / 16.0);
    KP923879532 = cos(M_PI / 8.0);
    KP382683432 = sin(M_PI / 8.0);
    KP707106781 = sin(M_PI / 4.0);

    // Set loop bounds
    mb = 1;
    me = padded_num_points;
    ms = N; // Stride step for moving between blocks

    // Initialize data arrays with non-zero test values to ensure computation occurs
    for (INT i = 0; i < padded_num_points * N + 64; ++i) {
        if (i < padded_num_points * N) {
            Rp[i] = sin(i * 0.1);
            Ip[i] = cos(i * 0.1);
            Rm[i] = sin(i * 0.2);
            Im[i] = cos(i * 0.2);
        } else {
            Rp[i] = 0.0;
            Ip[i] = 0.0;
            Rm[i] = 0.0;
            Im[i] = 0.0;
        }
    }

    // Initialize W array with twiddle factors
    for (INT i = 0; i < padded_num_points * 62 + 64; ++i) {
        if (i < padded_num_points * 62) {
            W[i] = sin(i * 0.05);
        } else {
            W[i] = 0.0;
        }
    }
}
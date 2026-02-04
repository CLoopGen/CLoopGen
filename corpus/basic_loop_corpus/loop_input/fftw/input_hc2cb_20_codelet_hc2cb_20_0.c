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

R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP250000000;
E KP559016994;
E KP587785252;
E KP951056516;
INT m;

void init_vars() {
    // Initialize constants
    KP250000000 = 0.25;
    KP559016994 = sin(M_PI / 10.0);   // approx 0.587785252 for cos(54°), but matched to given name
    KP587785252 = sin(2.0 * M_PI / 5.0); // sin(72°) ~ 0.951056516, but assign based on naming pattern
    KP951056516 = sin(M_PI / 5.0);     // sin(36°) ~ 0.587785252 — adjust to match variable use

    // Correct assignment per actual trigonometric values used in FFT twiddle factors
    KP250000000 = 0.25;
    KP559016994 = 0.559016994; // actually close to sqrt(5)/4 ≈ 0.559016994
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;

    // Define meaningful problem size and strides
    const INT N = 10; // Based on rs[9] access -> at least 10 elements in stride array
    const INT total_size = 1 << 20; // ~1M complex elements → ~16 MB per buffer
    const INT vec_len = total_size / N;
    
    if (vec_len == 0) return;

    // Allocate buffers with proper alignment
    Rp = aligned_alloc(64, sizeof(R) * total_size);
    Ip = aligned_alloc(64, sizeof(R) * total_size);
    Rm = aligned_alloc(64, sizeof(R) * total_size);
    Im = aligned_alloc(64, sizeof(R) * total_size);
    W  = aligned_alloc(64, sizeof(R) * 38 * vec_len); // W is indexed up to +38 per iteration

    // Allocate and initialize stride vector
    rs = malloc(sizeof(INT) * N);
    for (INT i = 0; i < N; ++i) {
        rs[i] = i * vec_len;
    }

    // Set loop parameters
    mb = 0;
    me = vec_len;
    ms = 1; // ensures Rp += ms steps by one element per outer loop

    // Initialize all data arrays to zero to prevent NaN/inf issues
    for (INT i = 0; i < total_size; ++i) {
        Rp[i] = 0.0;
        Ip[i] = 0.0;
        Rm[i] = 0.0;
        Im[i] = 0.0;
    }
    for (INT i = 0; i < 38 * vec_len; ++i) {
        W[i] = sin(i * M_PI / 19.0); // non-uniform twiddle-like values
    }

    // Ensure initial offset in loop logic: W starts at (mb - 1)*38 → we must offset W initially
    // But since mb=0, then (mb-1)*38 = -38 → invalid! So adjust mb to avoid negative indexing.
    mb = 1;
    me = vec_len - 1; // ensure W + 38*(me-1) < W + 38*vec_len

    // Re-initialize affected pointers due to new mb
    Rp = Rp + (rs[0] * 1);
    Ip = Ip + (rs[0] * 1);
    Rm = Rm + (rs[0] * 1);
    Im = Im + (rs[0] * 1);
    W = W + ((mb - 1) * 38);
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef R E;
typedef ptrdiff_t INT;

typedef INT *stride;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *R0;
R *R1;
R *Cr;
R *Ci;

stride rs;
stride csr;
stride csi;

INT v;
INT ivs;
INT ovs;

E KP803207531 = 0.803207531;
E KP595699304 = 0.595699304;
E KP146730474 = 0.146730474;
E KP989176509 = 0.989176509;
E KP740951125 = 0.740951125;
E KP671558954 = 0.671558954;
E KP049067674 = 0.049067674;
E KP998795456 = 0.998795456;
E KP242980179 = 0.242980179;
E KP970031253 = 0.970031253;
E KP514102744 = 0.514102744;
E KP857728610 = 0.857728610;
E KP336889853 = 0.336889853;
E KP941544065 = 0.941544065;
E KP427555093 = 0.427555093;
E KP903989293 = 0.903989293;
E KP098017140 = 0.098017140;
E KP995184726 = 0.995184726;
E KP634393284 = 0.634393284;
E KP773010453 = 0.773010453;
E KP881921264 = 0.881921264;
E KP471396736 = 0.471396736;
E KP956940335 = 0.956940335;
E KP290284677 = 0.290284677;
E KP555570233 = 0.555570233;
E KP831469612 = 0.831469612;
E KP195090322 = 0.195090322;
E KP980785280 = 0.980785280;
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;

INT i;

void init_vars() {
    const size_t N = 64; 
    const size_t data_size = 1 << 20; 
    const size_t total_size = data_size / sizeof(R);
    const size_t alignment = 32;

    R0 = aligned_alloc(alignment, total_size * sizeof(R));
    R1 = aligned_alloc(alignment, total_size * sizeof(R));
    Cr = aligned_alloc(alignment, total_size * sizeof(R));
    Ci = aligned_alloc(alignment, total_size * sizeof(R));

    rs = aligned_alloc(alignment, N * sizeof(INT));
    csr = aligned_alloc(alignment, N * sizeof(INT));
    csi = aligned_alloc(alignment, N * sizeof(INT));

    for (size_t idx = 0; idx < N; ++idx) {
        rs[idx] = (ptrdiff_t)idx;
        csr[idx] = (ptrdiff_t)idx;
        csi[idx] = (ptrdiff_t)idx;
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        R0[idx] = (R)(rand() % 1000) / 100.0;
        R1[idx] = (R)(rand() % 1000) / 100.0;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    v = 1;
    ivs = 1;
    ovs = 1;
}
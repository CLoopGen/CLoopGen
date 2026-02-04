#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

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
E KP242980179 = 0.242980179;
E KP970031253 = 0.970031253;
E KP857728610 = 0.857728610;
E KP514102744 = 0.514102744;
E KP471396736 = 0.471396736;
E KP881921264 = 0.881921264;
E KP427555093 = 0.427555093;
E KP903989293 = 0.903989293;
E KP336889853 = 0.336889853;
E KP941544065 = 0.941544065;
E KP773010453 = 0.773010453;
E KP634393284 = 0.634393284;
E KP595699304 = 0.595699304;
E KP803207531 = 0.803207531;
E KP146730474 = 0.146730474;
E KP989176509 = 0.989176509;
E KP956940335 = 0.956940335;
E KP290284677 = 0.290284677;
E KP049067674 = 0.049067674;
E KP998795456 = 0.998795456;
E KP671558954 = 0.671558954;
E KP740951125 = 0.740951125;
E KP098017140 = 0.098017140;
E KP995184726 = 0.995184726;
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP555570233 = 0.555570233;
E KP831469612 = 0.831469612;
E KP195090322 = 0.195090322;
E KP980785280 = 0.980785280;
E KP707106781 = 0.707106781;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of doubles (about 8MB total)
    const INT N = 32; // Based on rs[31] indexing

    R0 = aligned_alloc(64, data_size * sizeof(R));
    R1 = aligned_alloc(64, data_size * sizeof(R));
    Cr = aligned_alloc(64, data_size * sizeof(R));
    Ci = aligned_alloc(64, data_size * sizeof(R));

    rs = malloc(N * sizeof(INT));
    csr = malloc(N * sizeof(INT));
    csi = malloc(N * sizeof(INT));

    for (INT j = 0; j < N; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    v = data_size / N;
    ivs = N;
    ovs = N;

    for (size_t j = 0; j < data_size; ++j) {
        R0[j] = (R)(rand() % 1000) / 100.0;
        R1[j] = (R)(rand() % 1000) / 100.0;
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }
}
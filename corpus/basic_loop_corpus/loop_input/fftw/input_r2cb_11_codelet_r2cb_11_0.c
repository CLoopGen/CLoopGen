#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

E KP2_000000000 = 2.0;
E KP1_918985947 = 1.918985947;
E KP1_309721467 = 1.309721467;
E KP284629676 = 0.284629676;
E KP830830026 = 0.830830026;
E KP1_682507065 = 1.682507065;
E KP563465113 = 0.563465113;
E KP1_511499148 = 1.511499148;
E KP1_979642883 = 1.979642883;
E KP1_819263990 = 1.819263990;
E KP1_081281634 = 1.081281634;

INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to target ~0.01s runtime
    const size_t alignment = 64;

    R0 = aligned_alloc(alignment, data_size);
    R1 = aligned_alloc(alignment, data_size);
    Cr = aligned_alloc(alignment, data_size);
    Ci = aligned_alloc(alignment, data_size);

    rs = aligned_alloc(alignment, 6 * sizeof(INT));
    csr = aligned_alloc(alignment, 6 * sizeof(INT));
    csi = aligned_alloc(alignment, 6 * sizeof(INT));

    for (int j = 0; j < 6; ++j) {
        rs[j] = j * 8;
        csr[j] = j * 8;
        csi[j] = j * 8;
    }

    v = 10000;
    ivs = 8;
    ovs = 8;

    for (size_t j = 0; j < data_size / sizeof(R); ++j) {
        Cr[j] = (R)(j % 1000) / 100.0;
        Ci[j] = (R)((j + 50) % 1000) / 100.0;
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}
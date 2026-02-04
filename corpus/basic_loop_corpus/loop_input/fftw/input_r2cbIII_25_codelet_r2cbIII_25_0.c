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

E KP968583161 = 0.968583161;
E KP248689887 = 0.248689887;
E KP684547105 = 0.684547105;
E KP728968627 = 0.728968627;
E KP062790519 = 0.062790519;
E KP998026728 = 0.998026728;
E KP876306680 = 0.876306680;
E KP481753674 = 0.481753674;
E KP535826794 = 0.535826794;
E KP844327925 = 0.844327925;
E KP904827052 = 0.904827052;
E KP425779291 = 0.425779291;
E KP250000000 = 0.250000000;
E KP951056516 = 0.951056516;
E KP587785252 = 0.587785252;
E KP559016994 = 0.559016994;
E KP500000000 = 0.500000000;
E KP2_000000000 = 2.000000000;
E KP1_118033988 = 1.118033988;
E KP1_175570504 = 1.175570504;
E KP1_902113032 = 1.902113032;

INT i;

void init_vars() {
    const size_t data_size = 131072; // ~1MB for double arrays (131072 * 8 bytes)
    const INT vector_length = 13; // maximum index used in csr/csi/rs: e.g., csr[12], rs[12]

    R0 = (R*)aligned_alloc(32, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(32, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(32, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(32, data_size * sizeof(R));

    rs = (stride)aligned_alloc(32, vector_length * sizeof(INT));
    csr = (stride)aligned_alloc(32, vector_length * sizeof(INT));
    csi = (stride)aligned_alloc(32, vector_length * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(idx % 1000) / 1000.0;
        R1[idx] = (R)((idx + 1) % 1000) / 1000.0;
        Cr[idx] = (R)((idx + 2) % 1000) / 1000.0;
        Ci[idx] = (R)((idx + 3) % 1000) / 1000.0;
    }

    for (INT idx = 0; idx < vector_length; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    v = (INT)(data_size / 16); // ensure sufficient iterations (~8192), adjust for safe memory access
    ivs = 1;
    ovs = 1;

    i = 0;
}
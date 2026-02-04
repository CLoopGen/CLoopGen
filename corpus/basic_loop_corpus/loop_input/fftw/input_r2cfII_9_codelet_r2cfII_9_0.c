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

R *R0 = NULL;
R *R1 = NULL;
R *Cr = NULL;
R *Ci = NULL;
stride rs = NULL;
stride csr = NULL;
stride csi = NULL;

INT v = 0;
INT ivs = 0;
INT ovs = 0;

E KP663413948 = 0.663413948;
E KP642787609 = 0.642787609;
E KP556670399 = 0.556670399;
E KP766044443 = 0.766044443;
E KP852868531 = 0.852868531;
E KP173648177 = 0.173648177;
E KP984807753 = 0.984807753;
E KP150383733 = 0.150383733;
E KP813797681 = 0.813797681;
E KP342020143 = 0.342020143;
E KP939692620 = 0.939692620;
E KP296198132 = 0.296198132;
E KP866025403 = 0.866025403;
E KP500000000 = 0.500000000;

INT i = 0;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB of total data (adjustable)
    
    R0 = aligned_alloc(64, data_size * sizeof(R));
    R1 = aligned_alloc(64, data_size * sizeof(R));
    Cr = aligned_alloc(64, data_size * sizeof(R));
    Ci = aligned_alloc(64, data_size * sizeof(R));
    
    rs = aligned_alloc(64, 6 * sizeof(INT));
    csr = aligned_alloc(64, 5 * sizeof(INT));
    csi = aligned_alloc(64, 5 * sizeof(INT));

    for (size_t i = 0; i < data_size; ++i) {
        R0[i] = sin(i * 0.01);
        R1[i] = cos(i * 0.01);
        Cr[i] = 0.0;
        Ci[i] = 0.0;
    }

    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3; rs[4] = 4; rs[5] = 5;
    csr[0] = 0; csr[1] = 1; csr[2] = 2; csr[3] = 3; csr[4] = 4;
    csi[0] = 0; csi[1] = 1; csi[2] = 2; csi[3] = 3; csi[4] = 4;

    ivs = 1;
    ovs = 1;
    v = 1000000; 

    for (i = 0; i < v; ++i) {
        R0[i * ivs + rs[4]] = R0[i * ivs + rs[4]];
        R1[i * ivs + rs[3]] = R1[i * ivs + rs[3]];
        Cr[i * ovs + csr[4]] = 0.0;
        Ci[i * ovs + csi[3]] = 0.0;
    }
}
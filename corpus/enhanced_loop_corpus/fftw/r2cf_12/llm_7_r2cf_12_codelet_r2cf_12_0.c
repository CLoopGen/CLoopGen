#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 4; i > 0; i = i - 1 , R0 = R0 + 4*ivs , R1 = R1 + 4*ivs , Cr = Cr + 4*ovs , Ci = Ci + 4*ovs , (rs) = (rs) + 4*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 4*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 4*fftw_an_INT_guaranteed_to_be_zero) {
    E T5, Tp, Tb, Tn, Ty, Tt, Ta, Tq, Tc, Ti, Tz, Tu, Td, To;
    E Tsum_real = 0.0, Tsum_imag = 0.0;
    INT j;

    // Reduced operation variant with loop over 4 elements and simplified computation
    for (j = 0; j < 4; j++) {
        E x0 = R0[j * ivs];
        E x1 = R1[j * ivs];
        E y0 = R0[(rs[2]) + j * ivs];
        E y1 = R1[(rs[3]) + j * ivs];

        E sum = x0 + y0;
        E diff = x0 - y0;
        E cross = x1 * y1;

        Tsum_real += sum + (KP500000000 * diff);
        Tsum_imag += cross - (diff * KP866025403);
    }

    // Final reduced outputs using aggregated values
    Cr[(csr[0])] = Tsum_real;
    Ci[(csi[0])] = Tsum_imag;

    Cr[(csr[1])] = Tsum_real * KP500000000;
    Ci[(csi[1])] = Tsum_imag * KP866025403;

    Cr[(csr[2])] = Tsum_real * 0.25;
    Ci[(csi[2])] = Tsum_imag * 0.25;

    Cr[(csr[3])] = Tsum_real * 0.125;
    Ci[(csi[3])] = Tsum_imag * 0.125;
}
}

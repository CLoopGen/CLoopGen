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
extern  E KP2_000000000;
extern  E KP1_118033988;
extern  E KP500000000;
extern  E KP1_902113032;
extern  E KP1_175570504;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + (2 * ovs) , R1 = R1 + (2 * ovs) , Cr = Cr + (2 * ivs) , Ci = Ci + (2 * ivs) , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ta1, Tc1, T11, T41, T51, T61, Tb1, T71;
    E Ta2, Tc2, T12, T42, T52, T62, Tb2, T72;
    {
        E T8, T9, T2, T3;
        T8 = Ci[(csi[1])];
        T9 = Ci[(csi[2])];
        Ta1 = ((KP1_175570504 * T8) - ((KP1_902113032) * (T9)));
        Tc1 = (((KP1_902113032) * (T8)) + (KP1_175570504 * T9));
        T11 = Cr[0];
        T2 = Cr[(csr[1])];
        T3 = Cr[(csr[2])];
        T41 = T2 + T3;
        T51 = ((T11) - ((KP500000000) * (T41)));
        T61 = KP1_118033988 * (T2 - T3);
    }
    R0[0] = (((KP2_000000000) * (T41)) + (T11));
    Tb1 = T61 + T51;
    R1[0] = Tb1 - Tc1;
    R0[(rs[2])] = Tb1 + Tc1;
    T71 = T51 - T61;
    R0[(rs[1])] = T71 - Ta1;
    R1[(rs[1])] = T71 + Ta1;

    {
        E T8, T9, T2, T3;
        T8 = Ci[(csi[1]) + ivs];
        T9 = Ci[(csi[2]) + ivs];
        Ta2 = ((KP1_175570504 * T8) - ((KP1_902113032) * (T9)));
        Tc2 = (((KP1_902113032) * (T8)) + (KP1_175570504 * T9));
        T12 = Cr[ivs];
        T2 = Cr[(csr[1]) + ivs];
        T3 = Cr[(csr[2]) + ivs];
        T42 = T2 + T3;
        T52 = ((T12) - ((KP500000000) * (T42)));
        T62 = KP1_118033988 * (T2 - T3);
    }
    R0[ovs] = (((KP2_000000000) * (T42)) + (T12));
    Tb2 = T62 + T52;
    R1[ovs] = Tb2 - Tc2;
    R0[(rs[2]) + ovs] = Tb2 + Tc2;
    T72 = T52 - T62;
    R0[(rs[1]) + ovs] = T72 - Ta2;
    R1[(rs[1]) + ovs] = T72 + Ta2;
}
}

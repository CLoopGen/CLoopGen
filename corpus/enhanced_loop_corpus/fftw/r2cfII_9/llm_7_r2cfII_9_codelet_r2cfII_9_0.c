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
extern  E KP663413948;
extern  E KP642787609;
extern  E KP556670399;
extern  E KP766044443;
extern  E KP852868531;
extern  E KP173648177;
extern  E KP984807753;
extern  E KP150383733;
extern  E KP813797681;
extern  E KP342020143;
extern  E KP939692620;
extern  E KP296198132;
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational complexity: unroll by factor of 2 and simplify operations
INT step = 2;
for (i = v; i >= step; i = i - step , R0 = R0 + ivs * step , R1 = R1 + ivs * step , Cr = Cr + ovs * step , Ci = Ci + ovs * step , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {

    // First iteration (i-1)
    {
        E T1 = R0[0];
        E T2 = R1[(rs[1])];
        E T3 = R0[(rs[3])];
        E T4 = T2 - T3;
        E T5 = T1 - T4;
        E Tr = (((KP500000000) * (T4)) + (T1));

        Cr[0] = Tr;
        Cr[(csr[1])] = T5 - (KP500000000 * (T2 + T3 + R0[(rs[1])] - (R1[(rs[2])] - R0[(rs[4])])));
        Ci[0] = KP866025403 * (T2 + T3);
    }

    // Second iteration (i-2), offset manually using pointer arithmetic
    R0 += ivs; R1 += ivs; Cr += ovs; Ci += ovs;

    {
        E T1 = R0[0];
        E T4 = R1[(rs[1])] - R0[(rs[3])];
        E T5 = T1 - T4;
        E Tr = (((KP500000000) * (T4)) + (T1));

        Cr[0] = Tr;
        Cr[(csr[1])] = T5;
        Ci[0] = KP866025403 * T4;
    }

    // Adjust back final pointer increment since loop already does it
    R0 -= ivs; R1 -= ivs; Cr -= ovs; Ci -= ovs;
}

// Handle odd leftover iteration
if (i == 1) {
    E T1 = R0[0];
    E T2 = R1[(rs[1])];
    E T3 = R0[(rs[3])];
    E T4 = T2 - T3;
    E T5 = T1 - T4;
    E Tr = (((KP500000000) * (T4)) + (T1));

    Cr[0] = Tr;
    Cr[(csr[1])] = T5;
    Ci[0] = KP866025403 * (T2 + T3);
}
}

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
extern  E KP1_801937735;
extern  E KP445041867;
extern  E KP1_246979603;
extern  E KP867767478;
extern  E KP1_949855824;
extern  E KP1_563662964;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    // Eliminate intermediate temporaries to reduce local data dependencies
    // Fuse computations directly into output assignments where possible
    // This reduces register pressure and creates more loop-carried independence

    E T1 = Cr[0];
    E T2 = Cr[(csr[7])];
    E T3 = T1 - T2;
    E Td = T1 + T2;

    E Te = Cr[(csr[2])] + Cr[(csr[5])];
    E T6 = Cr[(csr[2])] - Cr[(csr[5])];
    E Tf = Cr[(csr[4])] + Cr[(csr[3])];
    E T9 = Cr[(csr[4])] - Cr[(csr[3])];
    E Tg = Cr[(csr[6])] + Cr[(csr[1])];
    E Tc = Cr[(csr[6])] - Cr[(csr[1])];

    E Tz = Ci[(csi[2])] + Ci[(csi[5])];
    E Tq = Ci[(csi[2])] - Ci[(csi[5])];
    E Tx = Ci[(csi[4])] + Ci[(csi[3])];
    E Tk = Ci[(csi[4])] - Ci[(csi[3])];
    E Ty = Ci[(csi[6])] + Ci[(csi[1])];
    E Tn = Ci[(csi[6])] - Ci[(csi[1])];

    // Break loop-carried dependency on memory outputs by reordering stores
    // Now all loads happen first, then all arithmetic, then all stores
    R0[0] = (((KP2_000000000) * (Te + Tf + Tg)) + (Td));

    {
        E Th = (((KP1_246979603) * (Tf)) + (Td)) + (-(((KP445041867) * (Tg)) + (KP1_801937735 * Te)));
        E Tr = ((KP1_563662964 * Tk) - ((KP1_949855824) * (Tn))) - (KP867767478 * Tq);
        R0[(rs[2])] = Th - Tr;
        R0[(rs[5])] = Th + Tr;
    }
    {
        E Ts = (((KP1_246979603) * (Tg)) + (Td)) + (-(((KP1_801937735) * (Tf)) + (KP445041867 * Te)));
        E Tt = (((KP867767478) * (Tk)) + (KP1_563662964 * Tn)) - (KP1_949855824 * Tq);
        R0[(rs[6])] = Ts - Tt;
        R0[(rs[1])] = Ts + Tt;
    }
    {
        E Tu = (((KP1_246979603) * (Te)) + (Td)) + (-(((KP1_801937735) * (Tg)) + (KP445041867 * Tf)));
        E Tv = (((KP1_563662964) * (Tq)) + (KP1_949855824 * Tk)) + (KP867767478 * Tn);
        R0[(rs[4])] = Tu - Tv;
        R0[(rs[3])] = Tu + Tv;
    }

    R1[(rs[3])] = (((KP2_000000000) * (T6 + T9 + Tc)) + (T3));

    {
        E TD = (((KP1_246979603) * (Tc)) + (T3)) + (-(((KP1_801937735) * (T9)) + (KP445041867 * T6)));
        E TE = (((KP867767478) * (Tx)) + (KP1_563662964 * Ty)) - (KP1_949855824 * Tz);
        R1[(rs[2])] = TD - TE;
        R1[(rs[4])] = TD + TE;
    }
    {
        E Tw = (((KP1_246979603) * (T9)) + (T3)) + (-(((KP445041867) * (Tc)) + (KP1_801937735 * T6)));
        E TA = ((KP1_563662964 * Tx) - ((KP1_949855824) * (Ty))) - (KP867767478 * Tz);
        R1[(rs[5])] = Tw - TA;
        R1[(rs[1])] = Tw + TA;
    }
    {
        E TB = (((KP1_246979603) * (T6)) + (T3)) + (-(((KP1_801937735) * (Tc)) + (KP445041867 * T9)));
        E TC = (((KP1_563662964) * (Tz)) + (KP1_949855824 * Tx)) + (KP867767478 * Ty);
        R1[0] = TB - TC;
        R1[(rs[6])] = TB + TC;
    }
}
}

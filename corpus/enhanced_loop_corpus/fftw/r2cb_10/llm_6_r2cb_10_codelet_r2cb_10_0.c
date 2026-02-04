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
extern  E KP500000000;
extern  E KP1_902113032;
extern  E KP1_175570504;
extern  E KP2_000000000;
extern  E KP1_118033988;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tb, Tn, Tv, Tk, Tu, Ta, Ts, Te, Tg, Ti, Tj;
    E temp_Cr[6], temp_Ci[5];
    
    // Introduce local caching to remove immediate RAW dependencies on global arrays
    for (INT idx = 0; idx < 6; ++idx) temp_Cr[idx] = Cr[(csr[idx])];
    for (INT idy = 0; idy < 5; ++idy) temp_Ci[idy] = Ci[(csi[idy])];

    {
        E T1, T2, Tl, Tm;
        T1 = temp_Cr[0];
        T2 = temp_Cr[5];
        T3 = T1 - T2;
        Tb = T1 + T2;
        Tl = temp_Ci[4];
        Tm = temp_Ci[1];
        Tn = Tl - Tm;
        Tv = Tl + Tm;
    }
    Ti = temp_Ci[2];
    Tj = temp_Ci[3];
    Tk = Ti - Tj;
    Tu = Ti + Tj;
    {
        E T6, Tc, T9, Td;
        {
            E T4, T5, T7, T8;
            T4 = temp_Cr[2];
            T5 = temp_Cr[3];
            T6 = T4 - T5;
            Tc = T4 + T5;
            T7 = temp_Cr[4];
            T8 = temp_Cr[1];
            T9 = T7 - T8;
            Td = T7 + T8;
        }
        Ta = T6 + T9;
        Ts = KP1_118033988 * (T6 - T9);
        Te = Tc + Td;
        Tg = KP1_118033988 * (Tc - Td);
    }
    R1[(rs[2])] = (((KP2_000000000) * (Ta)) + (T3));
    R0[0] = (((KP2_000000000) * (Te)) + (Tb));
    {
        E To, Tq, Th, Tp, Tf;
        To = ((KP1_175570504 * Tk) - ((KP1_902113032) * (Tn)));
        Tq = (((KP1_902113032) * (Tk)) + (KP1_175570504 * Tn));
        Tf = ((Tb) - ((KP500000000) * (Te)));
        Th = Tf - Tg;
        Tp = Tg + Tf;
        R0[(rs[1])] = Th - To;
        R0[(rs[2])] = Tp + Tq;
        R0[(rs[4])] = Th + To;
        R0[(rs[3])] = Tp - Tq;
    }
    {
        E Tw, Ty, Tt, Tx, Tr;
        Tw = ((KP1_175570504 * Tu) - ((KP1_902113032) * (Tv)));
        Ty = (((KP1_902113032) * (Tu)) + (KP1_175570504 * Tv));
        Tr = ((T3) - ((KP500000000) * (Ta)));
        Tt = Tr - Ts;
        Tx = Ts + Tr;
        R1[(rs[3])] = Tt - Tw;
        R1[(rs[4])] = Tx + Ty;
        R1[(rs[1])] = Tt + Tw;
        R1[0] = Tx - Ty;
    }
}
}

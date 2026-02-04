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
    const INT * restrict cr_idx = (const INT *)csr;
    const INT * restrict ci_idx = (const INT *)csi;
    const INT * restrict r_idx = (const INT *)rs;
    E * restrict cr_ptr = Cr;
    E * restrict ci_ptr = Ci;
    E * restrict r0_ptr = R0;
    E * restrict r1_ptr = R1;

    {
        E T1, T2, Tl, Tm;
        T1 = cr_ptr[0];
        T2 = cr_ptr[cr_idx[5]];
        T3 = T1 - T2;
        Tb = T1 + T2;
        Tl = ci_ptr[ci_idx[4]];
        Tm = ci_ptr[ci_idx[1]];
        Tn = Tl - Tm;
        Tv = Tl + Tm;
    }
    Ti = ci_ptr[ci_idx[2]];
    Tj = ci_ptr[ci_idx[3]];
    Tk = Ti - Tj;
    Tu = Ti + Tj;
    {
        E T6, Tc, T9, Td;
        {
            E T4, T5, T7, T8;
            T4 = cr_ptr[cr_idx[2]];
            T5 = cr_ptr[cr_idx[3]];
            T6 = T4 - T5;
            Tc = T4 + T5;
            T7 = cr_ptr[cr_idx[4]];
            T8 = cr_ptr[cr_idx[1]];
            T9 = T7 - T8;
            Td = T7 + T8;
        }
        Ta = T6 + T9;
        Ts = KP1_118033988 * (T6 - T9);
        Te = Tc + Td;
        Tg = KP1_118033988 * (Tc - Td);
    }
    r1_ptr[r_idx[2]] = (((KP2_000000000) * (Ta)) + (T3));
    r0_ptr[0] = (((KP2_000000000) * (Te)) + (Tb));
    {
        E To, Tq, Th, Tp, Tf;
        To = ((KP1_175570504 * Tk) - ((KP1_902113032) * (Tn)));
        Tq = (((KP1_902113032) * (Tk)) + (KP1_175570504 * Tn));
        Tf = ((Tb) - ((KP500000000) * (Te)));
        Th = Tf - Tg;
        Tp = Tg + Tf;
        r0_ptr[r_idx[1]] = Th - To;
        r0_ptr[r_idx[2]] = Tp + Tq;
        r0_ptr[r_idx[4]] = Th + To;
        r0_ptr[r_idx[3]] = Tp - Tq;
    }
    {
        E Tw, Ty, Tt, Tx, Tr;
        Tw = ((KP1_175570504 * Tu) - ((KP1_902113032) * (Tv)));
        Ty = (((KP1_902113032) * (Tu)) + (KP1_175570504 * Tv));
        Tr = ((T3) - ((KP500000000) * (Ta)));
        Tt = Tr - Ts;
        Tx = Ts + Tr;
        r1_ptr[r_idx[3]] = Tt - Tw;
        r1_ptr[r_idx[4]] = Tx + Ty;
        r1_ptr[r_idx[1]] = Tt + Tw;
        r1_ptr[0] = Tx - Ty;
    }
}
}

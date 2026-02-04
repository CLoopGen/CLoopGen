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
extern  E KP1_414213562;
extern  E KP2_000000000;
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, Tw, Tb, Te, Tx, Ts, Ta, TA, Tg, Tj, Tz, Tp, Tt, Tu;
    INT idx_csr[6], idx_csi[6];
    
    // Precompute indirect indices for Cr and Ci to enable strided but locally consecutive access pattern
    for (INT j = 0; j < 6; ++j) {
        idx_csr[j] = csr[j];
        idx_csi[j] = csi[j];
    }

    {
        E T1, T2, T3, T4;
        T1 = Cr[idx_csr[1]];
        T2 = Cr[idx_csr[5]];
        T3 = Cr[idx_csr[2]];
        T4 = T2 + T3;
        T5 = T1 + T4;
        Tw = KP866025403 * (T2 - T3);
        Tb = ((T1) - ((KP500000000) * (T4)));
    }
    {
        E Tq, Tc, Td, Tr;
        Tq = Ci[idx_csi[1]];
        Tc = Ci[idx_csi[5]];
        Td = Ci[idx_csi[2]];
        Tr = Td - Tc;
        Te = KP866025403 * (Tc + Td);
        Tx = (((KP500000000) * (Tr)) + (Tq));
        Ts = Tq - Tr;
    }
    {
        E T6, T7, T8, T9;
        T6 = Cr[idx_csr[4]];
        T7 = Cr[0];
        T8 = Cr[idx_csr[3]];
        T9 = T7 + T8;
        Ta = T6 + T9;
        TA = KP866025403 * (T7 - T8);
        Tg = ((T6) - ((KP500000000) * (T9)));
    }
    {
        E To, Th, Ti, Tn;
        To = Ci[idx_csi[4]];
        Th = Ci[0];
        Ti = Ci[idx_csi[3]];
        Tn = Ti - Th;
        Tj = KP866025403 * (Th + Ti);
        Tz = (((KP500000000) * (Tn)) + (To));
        Tp = Tn - To;
    }
    R0[0] = KP2_000000000 * (T5 + Ta);
    R0[(rs[3])] = KP2_000000000 * (Ts + Tp);
    Tt = Tp - Ts;
    Tu = T5 - Ta;
    R1[(rs[1])] = KP1_414213562 * (Tt - Tu);
    R1[(rs[4])] = KP1_414213562 * (Tu + Tt);
    {
        E Tf, Tk, Tv, Ty, TB, TC;
        Tf = Tb - Te;
        Tk = Tg + Tj;
        Tv = Tf - Tk;
        Ty = Tw + Tx;
        TB = Tz - TA;
        TC = Ty + TB;
        R0[(rs[2])] = -(KP2_000000000 * (Tf + Tk));
        R0[(rs[5])] = KP2_000000000 * (TB - Ty);
        R1[0] = KP1_414213562 * (Tv - TC);
        R1[(rs[3])] = KP1_414213562 * (Tv + TC);
    }
    {
        E Tl, Tm, TF, TD, TE, TG;
        Tl = Tb + Te;
        Tm = Tg - Tj;
        TF = Tm - Tl;
        TD = TA + Tz;
        TE = Tx - Tw;
        TG = TE + TD;
        R0[(rs[4])] = KP2_000000000 * (Tl + Tm);
        R1[(rs[2])] = KP1_414213562 * (TF + TG);
        R0[(rs[1])] = KP2_000000000 * (TD - TE);
        R1[(rs[5])] = KP1_414213562 * (TF - TG);
    }
}
}

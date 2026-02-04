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
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, Tp, Tb, Tn, Ty, Tt, Ta, Tq, Tc, Ti, Tz, Tu, Td, To;

    // Change memory access pattern to consecutive layout via local arrays
    E R0_local[6], R1_local[6];
    
    // Load data with strided access into consecutive local buffers
    R0_local[0] = R0[0];
    R0_local[1] = R0[rs[1]];
    R0_local[2] = R0[rs[2]];
    R0_local[3] = R0[rs[3]];
    R0_local[4] = R0[rs[4]];
    R0_local[5] = R0[rs[5]];

    R1_local[0] = R1[0];
    R1_local[1] = R1[rs[1]];
    R1_local[2] = R1[rs[2]];
    R1_local[3] = R1[rs[3]];
    R1_local[4] = R1[rs[4]];
    R1_local[5] = R1[rs[5]];

    {
        E T1, T2, T3, T4;
        T1 = R0_local[0];
        T2 = R0_local[2];
        T3 = R0_local[4];
        T4 = T2 + T3;
        T5 = T1 + T4;
        Tp = T1 - KP500000000 * T4;
        Tb = T3 - T2;
    }
    {
        E Tj, Tk, Tl, Tm;
        Tj = R1_local[1];
        Tk = R1_local[3];
        Tl = R1_local[5];
        Tm = Tk + Tl;
        Tn = Tj - KP500000000 * Tm;
        Ty = Tl - Tk;
        Tt = Tj + Tm;
    }
    {
        E T6, T7, T8, T9;
        T6 = R0_local[3];
        T7 = R0_local[5];
        T8 = R0_local[1];
        T9 = T7 + T8;
        Ta = T6 + T9;
        Tq = T6 - KP500000000 * T9;
        Tc = T8 - T7;
    }
    {
        E Te, Tf, Tg, Th;
        Te = R1_local[4];
        Tf = R1_local[0];
        Tg = R1_local[2];
        Th = Tf + Tg;
        Ti = Te - KP500000000 * Th;
        Tz = Tg - Tf;
        Tu = Te + Th;
    }

    // Output stored in temporary variables for consecutive processing
    E Cr_out[7] = {0}, Ci_out[7] = {0};

    Cr_out[3] = T5 - Ta;
    Ci_out[3] = Tt - Tu;
    Td = KP866025403 * (Tb - Tc);
    To = Ti - Tn;
    Ci_out[1] = Td + To;
    Ci_out[5] = To - Td;

    {
        E Tx, TA, Tv, Tw;
        Tx = Tp - Tq;
        TA = KP866025403 * (Ty - Tz);
        Cr_out[5] = Tx - TA;
        Cr_out[1] = Tx + TA;
        Tv = T5 + Ta;
        Tw = Tt + Tu;
        Cr_out[6] = Tv - Tw;
        Cr_out[0] = Tv + Tw;
    }
    {
        E Tr, Ts, TB, TC;
        Tr = Tp + Tq;
        Ts = Tn + Ti;
        Cr_out[2] = Tr - Ts;
        Cr_out[4] = Tr + Ts;
        TB = Ty + Tz;
        TC = Tb + Tc;
        Ci_out[2] = KP866025403 * (TB - TC);
        Ci_out[4] = KP866025403 * (TC + TB);
    }

    // Scatter results back through stride tables
    for (INT j = 0; j < 7; ++j) {
        Cr[csr[j]] = Cr_out[j];
        Ci[csi[j]] = Ci_out[j];
    }
}
}

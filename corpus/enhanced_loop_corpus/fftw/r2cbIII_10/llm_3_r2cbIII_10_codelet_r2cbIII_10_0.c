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
// Variant with fully unrolled and reordered memory accesses using local arrays to promote cache locality
for (i = v; i > 0; i--, R0 += ovs, R1 += ovs, Cr += ivs, Ci += ivs) {
    E T1, To, T8, Tq, Ta, Tp, Te, Ts, Th, Tn;

    // Preload all Cr and Ci values into local temporaries using indirect stride indices
    E cr_vals[5], ci_vals[5];
    cr_vals[0] = Cr[0];
    cr_vals[1] = Cr[csr[1]];
    cr_vals[2] = Cr[csr[2]];
    cr_vals[3] = Cr[csr[3]];
    cr_vals[4] = Cr[csr[4]];

    ci_vals[0] = Ci[0];
    ci_vals[1] = Ci[csi[1]];
    ci_vals[2] = Ci[csi[2]];
    ci_vals[3] = Ci[csi[3]];
    ci_vals[4] = Ci[csi[4]];

    T1 = cr_vals[2];
    To = ci_vals[2];

    {
        E T2 = cr_vals[4], T3 = cr_vals[0];
        E T4 = T2 + T3;
        E T5 = cr_vals[3], T6 = cr_vals[1];
        E T7 = T5 + T6;
        T8 = T4 + T7;
        Tq = T5 - T6;
        Ta = KP1_118033988 * (T7 - T4);
        Tp = T2 - T3;
    }

    {
        E Tc = ci_vals[4], Td = ci_vals[0];
        E Tm = Tc + Td;
        E Tf = ci_vals[1], Tg = ci_vals[3];
        E Tl = Tg + Tf;
        Te = Tc - Td;
        Ts = KP1_118033988 * (Tl + Tm);
        Th = Tf - Tg;
        Tn = Tl - Tm;
    }

    // Direct assignment using rs offsets in output arrays
    R0[0]                    = KP2_000000000 * (T1 + T8);
    R1[rs[2]]                = KP2_000000000 * (Tn - To);

    {
        E Ti = (KP1_175570504 * Te) - (KP1_902113032 * Th);
        E Tj = (KP1_175570504 * Th) + (KP1_902113032 * Te);
        E T9 = (KP500000000 * T8) - (KP2_000000000 * T1);
        E Tb = T9 - Ta;
        E Tk = T9 + Ta;

        R0[rs[1]] = Tb + Ti;
        R0[rs[3]] = Tk + Tj;
        R0[rs[4]] = Ti - Tb;
        R0[rs[2]] = Tj - Tk;
    }

    {
        E Tr = (KP1_902113032 * Tp) + (KP1_175570504 * Tq);
        E Tv = (KP1_902113032 * Tq) - (KP1_175570504 * Tp);
        E Tt = (KP500000000 * Tn) + (KP2_000000000 * To);
        E Tu = Ts + Tt;
        E Tw = Tt - Ts;

        R1[0]     = -(Tr + Tu);
        R1[rs[3]] = Tw - Tv;
        R1[rs[4]] = Tr - Tu;
        R1[rs[1]] = Tv + Tw;
    }
}
}

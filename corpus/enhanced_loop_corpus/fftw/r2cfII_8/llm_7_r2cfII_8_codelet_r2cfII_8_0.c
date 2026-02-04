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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 4; i > 0; i = i - 1 , R0 = R0 + 4*ivs , R1 = R1 + 4*ivs , Cr = Cr + 4*ovs , Ci = Ci + 4*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT j = 0; j < 4; j++) {
        E T1, Tj, T4, Ti, T8, Te, Tb, Tf, T2, T3;
        INT idx_r0 = j * ivs;
        INT idx_r1 = j * ivs;
        INT idx_cr = j * ovs;
        INT idx_ci = j * ovs;

        T1 = R0[idx_r0];
        Tj = R0[idx_r0 + (rs[2])];
        T2 = R0[idx_r0 + (rs[1])];
        T3 = R0[idx_r0 + (rs[3])];
        T4 = KP707106781 * (T2 - T3);
        Ti = KP707106781 * (T2 + T3);

        {
            E T6, T7, T9, Ta;
            T6 = R1[idx_r1];
            T7 = R1[idx_r1 + (rs[2])];
            T8 = ((KP923879532 * T6) - ((KP382683432) * (T7)));
            Te = (((KP382683432) * (T6)) + (KP923879532 * T7));
            T9 = R1[idx_r1 + (rs[1])];
            Ta = R1[idx_r1 + (rs[3])];
            Tb = ((KP382683432 * T9) - ((KP923879532) * (Ta)));
            Tf = (((KP923879532) * (T9)) + (KP382683432 * Ta));
        }
        {
            E T5, Tc, Th, Tk;
            T5 = T1 + T4;
            Tc = T8 + Tb;
            Cr[(csr[3]) + idx_cr] = T5 - Tc;
            Cr[idx_cr] = T5 + Tc;
            Th = Te + Tf;
            Tk = Ti + Tj;
            Ci[idx_ci] = -(Th + Tk);
            Ci[(csi[3]) + idx_ci] = Tk - Th;
        }
        {
            E Td, Tg, Tl, Tm;
            Td = T1 - T4;
            Tg = Te - Tf;
            Cr[(csr[2]) + idx_cr] = Td - Tg;
            Cr[(csr[1]) + idx_cr] = Td + Tg;
            Tl = Tb - T8;
            Tm = Tj - Ti;
            Ci[(csi[2]) + idx_ci] = Tl - Tm;
            Ci[(csi[1]) + idx_ci] = Tl + Tm;
        }
    }
}
}

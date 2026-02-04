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
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 2; i > 0; i = i - 1 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T7, Tf, Tl, T6, Tc, Ta, Tk, Tb, Tg;
    E Tn, Tr, Tv, Tw, Tq, Tt, Tu, Tx, Ty, Tz;

    // Reduced arithmetic: combine common terms once per two iterations
    E T1a = Cr[0], T2a = Cr[(csr[3])];
    E T4a = Cr[(csr[2])], T5a = Cr[(csr[1])];
    E T8a = Ci[(csi[2])], T9a = Ci[(csi[1])];
    E Tda = Ci[0], Tea = Ci[(csi[3])];

    T3 = T1a + T2a;
    T7 = T1a - T2a;
    T6 = T4a + T5a;
    Tc = T4a - T5a;
    Ta = T8a + T9a;
    Tk = T8a - T9a;
    Tf = Tda + Tea;
    Tl = Tea - Tda;

    R0[0] = KP2_000000000 * (T3 + T6);
    R0[(rs[2])] = KP2_000000000 * (Tl - Tk);
    Tb = T7 - Ta;
    Tg = Tc + Tf;
    R1[0] = KP1_847759065 * Tb - KP765366864 * Tg;
    R1[(rs[2])] = -(KP765366864 * Tb + KP1_847759065 * Tg);

    // Second half using offset pointers
    E T1b = Cr[ivs], T2b = Cr[ivs + (csr[3])];
    E T4b = Cr[ivs + (csr[2])], T5b = Cr[ivs + (csr[1])];
    E T8b = Ci[ivs + (csi[2])], T9b = Ci[ivs + (csi[1])];
    E Tdb = Ci[ivs], Teb = Ci[ivs + (csi[3])];

    Tn = T1b + T2b;
    Tr = T1b - T2b;
    Tq = T4b + T5b;
    Tt = T4b - T5b;
    Tu = T8b + T9b;
    Tx = T8b - T9b;
    Tv = Tdb + Teb;
    Tw = Teb - Tdb;

    R0[ovs] = KP2_000000000 * (Tn + Tq);
    R0[ovs + (rs[2])] = KP2_000000000 * (Tw - Tx);
    Ty = Tr - Tu;
    Tz = Tt + Tv;
    R1[ovs] = KP1_847759065 * Ty - KP765366864 * Tz;
    R1[ovs + (rs[2])] = -(KP765366864 * Ty + KP1_847759065 * Tz);

    // Shared computation for both outputs to reduce redundancy
    E Th1 = T7 + Ta, Ti1 = Tc - Tf;
    E Th2 = Tr + Tu, Ti2 = Tt - Tv;
    E Tj1 = T3 - T6, Tm1 = Tk + Tl;
    E Tj2 = Tn - Tq, Tm2 = Tx + Tw;

    R1[(rs[1])] = KP765366864 * Th1 + KP1_847759065 * Ti1;
    R1[(rs[3])] = KP765366864 * Ti1 - KP1_847759065 * Th1;
    R0[(rs[1])] = KP1_414213562 * (Tj1 + Tm1);
    R0[(rs[3])] = KP1_414213562 * (Tm1 - Tj1);

    R1[ovs + (rs[1])] = KP765366864 * Th2 + KP1_847759065 * Ti2;
    R1[ovs + (rs[3])] = KP765366864 * Ti2 - KP1_847759065 * Th2;
    R0[ovs + (rs[1])] = KP1_414213562 * (Tj2 + Tm2);
    R0[ovs + (rs[3])] = KP1_414213562 * (Tm2 - Tj2);
}
}

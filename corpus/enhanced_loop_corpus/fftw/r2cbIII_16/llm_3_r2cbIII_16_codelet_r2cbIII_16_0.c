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
extern  E KP1_961570560;
extern  E KP390180644;
extern  E KP1_111140466;
extern  E KP1_662939224;
extern  E KP707106781;
extern  E KP1_414213562;
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, TW, T13, Tj, TD, TK, TP, TH, Te, TX, T12, To, Tt, Tx, TS;
    E Tw, TT, TY;
    // Modify access pattern: use strided access with fixed stride of 1 and reorder computation
    // Simulate vector-like sequential load by unrolling and accessing via increasing index
    // Assume that csr and csi define a permutation; we now apply it as a scatter/gather through array of pointers

    E *cr_ptrs[8] = { Cr + csr[0], Cr + csr[1], Cr + csr[2], Cr + csr[3],
                      Cr + csr[4], Cr + csr[5], Cr + csr[6], Cr + csr[7] };
    E *ci_ptrs[8] = { Ci + csi[0], Ci + csi[1], Ci + csi[2], Ci + csi[3],
                      Ci + csi[4], Ci + csi[5], Ci + csi[6], Ci + csi[7] };

    E T1 = *cr_ptrs[0], T2 = *cr_ptrs[7];
    E T3 = T1 + T2;
    E Tf = T1 - T2;
    E TA = *ci_ptrs[0], TB = *ci_ptrs[7];
    E TC = TA + TB;
    E TV = TB - TA;

    E T4 = *cr_ptrs[4], T5 = *cr_ptrs[3];
    E T6 = T4 + T5;
    E Tz = T4 - T5;
    E Tg = *ci_ptrs[4], Th = *ci_ptrs[3];
    E Ti = Tg + Th;
    E TU = Tg - Th;

    T7 = T3 + T6;
    TW = TU + TV;
    T13 = TV - TU;
    Tj = Tf - Ti;
    TD = Tz + TC;
    TK = Tz - TC;
    TP = T3 - T6;
    TH = Tf + Ti;

    E T8 = *cr_ptrs[2], T9 = *cr_ptrs[5];
    E Ta = T8 + T9;
    E Tk = T8 - T9;
    E Tl = *ci_ptrs[2], Tm = *ci_ptrs[5];
    E Tn = Tl + Tm;
    E TR = Tl - Tm;

    E Tb = *cr_ptrs[1], Tc = *cr_ptrs[6];
    E Td = Tb + Tc;
    E Tp = Tb - Tc;
    E Tq = *ci_ptrs[1], Tr = *ci_ptrs[6];
    E Ts = Tq + Tr;
    E TQ = Tr - Tq;

    Te = Ta + Td;
    TX = Ta - Td;
    T12 = TR + TQ;
    To = Tk - Tn;
    Tt = Tp - Ts;
    Tx = Tp + Ts;
    TS = TQ - TR;
    Tw = Tk + Tn;

    // Output using indirect addressing via rs, but simulate dense output layout
    E *r0_ptrs[8] = { R0 + rs[0], R0 + rs[1], R0 + rs[2], R0 + rs[3],
                      R0 + rs[4], R0 + rs[5], R0 + rs[6], R0 + rs[7] };
    E *r1_ptrs[8] = { R1 + rs[0], R1 + rs[1], R1 + rs[2], R1 + rs[3],
                      R1 + rs[4], R1 + rs[5], R1 + rs[6], R1 + rs[7] };

    *r0_ptrs[0] = KP2_000000000 * (T7 + Te);
    *r0_ptrs[4] = KP2_000000000 * (T13 - T12);
    TT = TP + TS;
    TY = TW - TX;
    *r0_ptrs[1] = (((KP1_847759065) * (TT)) + (KP765366864 * TY));
    *r0_ptrs[5] = ((KP1_847759065 * TY) - ((KP765366864) * (TT)));

    E T11 = T7 - Te;
    E T14 = T12 + T13;
    *r0_ptrs[2] = KP1_414213562 * (T11 + T14);
    *r0_ptrs[6] = KP1_414213562 * (T14 - T11);
    E TZ = TP - TS;
    E T10 = TX + TW;
    *r0_ptrs[3] = (((KP765366864) * (TZ)) + (KP1_847759065 * T10));
    *r0_ptrs[7] = ((KP765366864 * T10) - ((KP1_847759065) * (TZ)));

    E TI = KP707106781 * (Tw + Tx);
    E TJ = TH - TI;
    E TN = TH + TI;
    E TL = KP707106781 * (To - Tt);
    E TM = TK - TL;
    E TO = TL + TK;
    *r1_ptrs[1] = (((KP1_662939224) * (TJ)) + (KP1_111140466 * TM));
    *r1_ptrs[7] = ((KP390180644 * TO) - ((KP1_961570560) * (TN)));
    *r1_ptrs[5] = ((KP1_662939224 * TM) - ((KP1_111140466) * (TJ)));
    *r1_ptrs[3] = (((KP390180644) * (TN)) + (KP1_961570560 * TO));

    E Tu = KP707106781 * (To + Tt);
    E Tv = Tj + Tu;
    E TF = Tj - Tu;
    E Ty = KP707106781 * (Tw - Tx);
    E TE = Ty + TD;
    E TG = Ty - TD;
    *r1_ptrs[0] = ((KP1_961570560 * Tv) - ((KP390180644) * (TE)));
    *r1_ptrs[6] = ((KP1_111140466 * TG) - ((KP1_662939224) * (TF)));
    *r1_ptrs[4] = -((((KP390180644) * (Tv)) + (KP1_961570560 * TE)));
    *r1_ptrs[2] = (((KP1_111140466) * (TF)) + (KP1_662939224 * TG));
}
}

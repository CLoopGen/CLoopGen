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
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs) {
    E T3, Td, T6, Te, Tq, Tz, Tn, Ty, Tc, Tg, Tk, Tx, T9, Tf, T1;
    E T2;
    T1 = Cr[0];
    T2 = Cr[(csr[7])];
    T3 = T1 - T2;
    Td = T1 + T2;

    // Reduced arithmetic: combine common terms early and skip intermediate variables
    E sum_re_25 = Cr[(csr[2])] + Cr[(csr[5])]; // Te
    E dif_re_25 = Cr[(csr[2])] - Cr[(csr[5])]; // T6
    E sum_im_25 = Ci[(csi[2])] + Ci[(csi[5])]; // Tz
    E dif_im_25 = Ci[(csi[2])] - Ci[(csi[5])]; // Tq

    E sum_re_61 = Cr[(csr[6])] + Cr[(csr[1])]; // Tg
    E dif_re_61 = Cr[(csr[6])] - Cr[(csr[1])]; // Tc
    E sum_im_61 = Ci[(csi[6])] + Ci[(csi[1])]; // Ty
    E dif_im_61 = Ci[(csi[6])] - Ci[(csi[1])]; // Tn

    E sum_re_43 = Cr[(csr[4])] + Cr[(csr[3])]; // Tf
    E dif_re_43 = Cr[(csr[4])] - Cr[(csr[3])]; // T9
    E sum_im_43 = Ci[(csi[4])] + Ci[(csi[3])]; // Tx
    E dif_im_43 = Ci[(csi[4])] - Ci[(csi[3])]; // Tk

    // Final sums
    E total_sum_real = Te + Tf + Tg;
    E total_dif_real = T6 + T9 + Tc;

    R1[(rs[3])] = (KP2_000000000 * total_dif_real) + T3;
    R0[0] = (KP2_000000000 * total_sum_real) + Td;

    // Simplified butterfly stages using precomputed coefficients
    E partA = KP1_246979603 * sum_re_43 + Td - (KP1_801937735 * sum_re_61 + KP445041867 * sum_re_25);
    E partB = KP1_563662964 * dif_im_43 - KP1_949855824 * dif_im_61 - KP867767478 * dif_im_25;
    R0[(rs[2])] = partA - partB;
    R0[(rs[5])] = partA + partB;

    E partC = KP1_246979603 * dif_re_61 + T3 - (KP1_801937735 * dif_re_43 + KP445041867 * dif_re_25);
    E partD = KP867767478 * sum_im_43 + KP1_563662964 * sum_im_61 - KP1_949855824 * sum_im_25;
    R1[(rs[2])] = partC - partD;
    R1[(rs[4])] = partC + partD;

    E partE = KP1_246979603 * sum_re_25 + Td - (KP1_801937735 * sum_re_61 + KP445041867 * sum_re_43);
    E partF = KP867767478 * dif_im_43 + KP1_563662964 * dif_im_61 - KP1_949855824 * dif_im_25;
    R0[(rs[6])] = partE - partF;
    R0[(rs[1])] = partE + partF;

    E partG = KP1_246979603 * dif_re_43 + T3 - (KP1_801937735 * dif_re_61 + KP445041867 * dif_re_25);
    E partH = KP1_563662964 * sum_im_43 - KP1_949855824 * sum_im_61 - KP867767478 * sum_im_25;
    R1[(rs[5])] = partG - partH;
    R1[(rs[1])] = partG + partH;

    E partI = KP1_246979603 * dif_re_25 + T3 - (KP1_801937735 * dif_re_61 + KP445041867 * dif_re_43);
    E partJ = KP1_563662964 * sum_im_25 + KP1_949855824 * sum_im_43 + KP867767478 * sum_im_61;
    R1[0] = partI - partJ;
    R1[(rs[6])] = partI + partJ;

    E partK = KP1_246979603 * sum_re_25 + Td - (KP1_801937735 * sum_re_61 + KP445041867 * sum_re_43);
    E partL = KP1_563662964 * dif_im_25 + KP1_949855824 * dif_im_43 + KP867767478 * dif_im_61;
    R0[(rs[4])] = partK - partL;
    R0[(rs[3])] = partK + partL;
}
}

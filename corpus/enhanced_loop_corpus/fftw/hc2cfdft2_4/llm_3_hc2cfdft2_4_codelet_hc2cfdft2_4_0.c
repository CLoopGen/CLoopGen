#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) << 2); m < me; m += 1 , Rp += ms , Ip += ms , Rm -= ms , Im -= ms , W += 4 , rs += fftw_an_INT_guaranteed_to_be_zero) {
    E T1 = W[0], T3 = W[1], T2 = W[2], T4 = W[3];
    E T5 = T1 * T2 + T3 * T4;
    E T9 = T1 * T4 - T3 * T2;

    INT idx_im1 = (INT)rs[1]; // Precompute strided index for clarity and access pattern change

    E Te = Ip[0], Tf = Im[0];
    E T6 = Ip[idx_im1], T7 = Im[idx_im1];
    E Ta = Rp[idx_im1], Tb = Rm[idx_im1];
    E Ti = Rm[0], Tj = Rp[0];

    E Tl = Te + Tf;
    E Tk = Ti - Tj;
    E Tg = Te - Tf;
    E Tr = Tj + Ti;
    E T8 = T6 - T7;
    E To = T6 + T7;
    E Tc = Ta + Tb;
    E Tn = Ta - Tb;

    E Tm = T1 * Tk - T3 * Tl;
    E Tx = T3 * Tk + T1 * Tl;
    E Td = T5 * T8 - T9 * Tc;
    E Tw = T2 * To - T4 * Tn;
    E Tp = T2 * Tn + T4 * To;
    E Ts = T5 * Tc + T9 * T8;

    // Reorder computations to group memory stores and use consecutive temporaries
    E Th = Td + Tg;
    E Tq = Tm - Tp;
    E Tz = Tr + Ts;
    E TA = Tw + Tx;
    E Tt = Tr - Ts;
    E Tu = Tp + Tm;
    E Tv = Tg - Td;
    E Ty = Tw - Tx;

    // Sequential write pattern using precomputed values
    Ip[0]             = KP500000000 * (Th + Tq);
    Im[idx_im1]       = KP500000000 * (Tq - Th);
    Rm[idx_im1]       = KP500000000 * (Tz - TA);
    Rp[0]             = KP500000000 * (Tz + TA);
    Rm[0]             = KP500000000 * (Tt - Tu);
    Rp[idx_im1]       = KP500000000 * (Tt + Tu);
    Ip[idx_im1]       = KP500000000 * (Tv + Ty);
    Im[0]             = KP500000000 * (Ty - Tv);
}
}

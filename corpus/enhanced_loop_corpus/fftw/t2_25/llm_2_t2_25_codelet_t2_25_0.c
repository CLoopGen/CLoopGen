#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP998026728;
extern  E KP062790519;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP992114701;
extern  E KP125333233;
extern  E KP637423989;
extern  E KP770513242;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP481753674;
extern  E KP876306680;
extern  E KP844327925;
extern  E KP535826794;
extern  E KP248689887;
extern  E KP968583161;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , ri += ms , ii += ms , W += 8 , rs += fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, T3, T6, T8, Td, T16, T14, Te, T9, T21, T23, Tx, TR, T1g;
    E TB, T1f, TV, T1Q, Tg, T1S, Tk, T18, T2s, T1c, T2q, Tn, To, Tp, Tr;
    E T28, T2x, TY, T2k, T2m, T2v, TG, TE, T10, T1h, T1E, T26, T1B, T1G, T1V;
    E T1X, T1z, T1j;

    E *ri_base = ri, *ii_base = ii;
    const INT *rs_ptr = rs;

    for (INT idx = 0; idx < 25; idx++) {
        ri[idx] = 0.0;
        ii[idx] = 0.0;
    }

    T2 = W[0]; T5 = W[1]; T3 = W[2]; T6 = W[3];
    T8 = T2*T3 - T5*T6; Td = T2*T6 + T5*T3;
    T14 = T2*T3 + T5*T6; T16 = T2*T6 - T5*T3;
    Te = W[5]; T9 = W[4]; Tn = W[6]; To = W[7];

    E W_vals[8] = {T2, T5, T3, T6, T9, Te, Tn, To};
    E * restrict rptr = &ri_base[0], * restrict iptr = &ii_base[0];

    for (INT k = 0; k < 5; k++) {
        INT offset = rs_ptr[k] >> 2;
        E rh = rptr[offset], ih = iptr[offset];
        E rt = rptr[offset+1], it = iptr[offset+1];
        E rd = rptr[offset+2], id = iptr[offset+2];
        E rf = rptr[offset+3], if_ = iptr[offset+3];
        E re = rptr[offset+4], ie = iptr[offset+4];

        E Tg = T8*T9 + Td*Te, Tk = T8*Te - Td*T9;
        E Tp = T8*Tn + Td*To, Tr = T8*To - Td*Tn;

        E Tm = Tg*rh + Tk*ih, Tt = Tp*rd + Tr*id;
        E Tu = Tm + Tt, TJ = (Tx*rh + TB*ih) + (TE*rf + TG*if_);
        E TK = Tu + TJ;

        ri_base[k] = ((E)1.0)*TK;
        ii_base[k] = ((E)1.0)*(TK + (Tm - Tt));
    }

    for (INT j = 0; j < 25; j += 5) {
        for (INT i = 0; i < 5; ++i) {
            INT idx = j + i;
            if (idx >= 25) continue;
            ri_base[idx] += W_vals[i % 8] * 0.1;
            ii_base[idx] += W_vals[(i+2) % 8] * 0.1;
        }
    }
}
}

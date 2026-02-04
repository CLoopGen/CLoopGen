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
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , Rp += ms , Ip += ms , Rm -= ms , Im -= ms , W += 10) {
    E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;
    INT idxs[3];
    idxs[0] = 0;
    idxs[1] = rs[1];
    idxs[2] = rs[2];

    E *rp_vec = (E*)aligned_alloc(sizeof(E), 3 * sizeof(E));
    E *ip_vec = (E*)aligned_alloc(sizeof(E), 3 * sizeof(E));
    E *rm_vec = (E*)aligned_alloc(sizeof(E), 3 * sizeof(E));
    E *im_vec = (E*)aligned_alloc(sizeof(E), 3 * sizeof(E));

    for (INT i = 0; i < 3; ++i) {
        rp_vec[i] = Rp[idxs[i]];
        ip_vec[i] = Ip[idxs[i]];
        rm_vec[i] = Rm[idxs[i]];
        im_vec[i] = Im[idxs[i]];
    }

    {
        E T1 = rp_vec[0];
        E TN = rm_vec[0];
        E T3 = ip_vec[1];
        E T5 = im_vec[1];
        E T6 = W[4] * T3 + W[5] * T5;
        E TM = W[4] * T5 - W[5] * T3;
        T7 = T1 - T6;
        TS = TN - TM;
        Tv = T1 + T6;
        TO = TN + TM;
    }
    {
        E Tk = rp_vec[2];
        E Tm = rm_vec[2];
        E Tn = W[6] * Tk + W[7] * Tm;
        E TD = W[6] * Tm - W[7] * Tk;
        E Tp = ip_vec[0];
        E Tr = im_vec[0];
        E Ts = W[0] * Tp + W[1] * Tr;
        E TE = W[0] * Tr - W[1] * Tp;
        Tt = Tn - Ts;
        TJ = TE - TD;
        Tx = Tn + Ts;
        TF = TD + TE;
    }
    {
        E T9 = rp_vec[1];
        E Tb = rm_vec[1];
        E Tc = W[2] * T9 + W[3] * Tb;
        E TA = W[2] * Tb - W[3] * T9;
        E Te = ip_vec[2];
        E Tg = im_vec[2];
        E Th = W[8] * Te + W[9] * Tg;
        E TB = W[8] * Tg - W[9] * Te;
        Ti = Tc - Th;
        TI = TA - TB;
        Tw = Tc + Th;
        TC = TA + TB;
    }
    {
        E TK = KP866025403 * (TI + TJ);
        E Tu = Ti + Tt;
        E TH = T7 - KP500000000 * Tu;
        rm_vec[2] = T7 + Tu;
        rp_vec[1] = TH + TK;
        rm_vec[0] = TH - TK;
        E TT = KP866025403 * (Tt - Ti);
        E TR = TJ - TI;
        E TU = KP500000000 * TR + TS;
        im_vec[2] = TR - TS;
        ip_vec[1] = TT + TU;
        im_vec[0] = TT - TU;
    }
    {
        E TG = KP866025403 * (TC - TF);
        E Ty = Tw + Tx;
        E Tz = Tv - KP500000000 * Ty;
        rp_vec[0] = Tv + Ty;
        rm_vec[1] = Tz + TG;
        rp_vec[2] = Tz - TG;
        E TP = KP866025403 * (Tw - Tx);
        E TL = TC + TF;
        E TQ = TO - KP500000000 * TL;
        ip_vec[0] = TL + TO;
        ip_vec[2] = TP + TQ;
        im_vec[1] = TP - TQ;
    }

    for (INT i = 0; i < 3; ++i) {
        Rp[idxs[i]] = rp_vec[i];
        Ip[idxs[i]] = ip_vec[i];
        Rm[idxs[i]] = rm_vec[i];
        Im[idxs[i]] = im_vec[i];
    }

    free(rp_vec);
    free(ip_vec);
    free(rm_vec);
    free(im_vec);
}
}

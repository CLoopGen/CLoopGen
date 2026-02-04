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
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP781831482;
extern  E KP974927912;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 12); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TR, Tc, TS, TC, TO, Tn, TT, TI, TP, Ty, TU, TF, TQ;
    E temp_re[7], temp_im[7];
    INT idxs[7] = {0, rs[1], rs[2], rs[3], rs[4], rs[5], rs[6]};
    
    for (INT i = 0; i < 7; i++) {
        temp_re[i] = ri[idxs[i]];
        temp_im[i] = ii[idxs[i]];
    }

    T1 = temp_re[0];
    TR = temp_im[0];

    {
        E T6, TA, Tb, TB;
        T6 = W[0] * temp_re[1] + W[1] * temp_im[1];
        TA = W[0] * temp_im[1] - W[1] * temp_re[1];
        Tb = W[10] * temp_re[6] + W[11] * temp_im[6];
        TB = W[10] * temp_im[6] - W[11] * temp_re[6];
        Tc = T6 + Tb;
        TS = Tb - T6;
        TC = TA - TB;
        TO = TA + TB;
    }

    {
        E Th, TG, Tm, TH;
        Th = W[2] * temp_re[2] + W[3] * temp_im[2];
        TG = W[2] * temp_im[2] - W[3] * temp_re[2];
        Tm = W[8] * temp_re[5] + W[9] * temp_im[5];
        TH = W[8] * temp_im[5] - W[9] * temp_re[5];
        Tn = Th + Tm;
        TT = Tm - Th;
        TI = TG - TH;
        TP = TG + TH;
    }

    {
        E Ts, TD, Tx, TE;
        Ts = W[4] * temp_re[3] + W[5] * temp_im[3];
        TD = W[4] * temp_im[3] - W[5] * temp_re[3];
        Tx = W[6] * temp_re[4] + W[7] * temp_im[4];
        TE = W[6] * temp_im[4] - W[7] * temp_re[4];
        Ty = Ts + Tx;
        TU = Tx - Ts;
        TF = TD - TE;
        TQ = TD + TE;
    }

    ri[0] = T1 + Tc + Tn + Ty;
    ii[0] = TO + TP + TQ + TR;

    {
        E TJ, Tz, TX, TY;
        TJ = KP974927912 * TC - KP781831482 * TF - KP433883739 * TI;
        Tz = KP623489801 * Ty + T1 - (KP900968867 * Tn + KP222520933 * Tc);
        ri[idxs[5]] = Tz - TJ;
        ri[idxs[2]] = Tz + TJ;
        TX = KP974927912 * TS - KP781831482 * TU - KP433883739 * TT;
        TY = KP623489801 * TQ + TR - (KP900968867 * TP + KP222520933 * TO);
        ii[idxs[2]] = TX + TY;
        ii[idxs[5]] = TY - TX;
    }

    {
        E TL, TK, TV, TW;
        TL = KP781831482 * TC + KP974927912 * TI + KP433883739 * TF;
        TK = KP623489801 * Tc + T1 - (KP900968867 * Ty + KP222520933 * Tn);
        ri[idxs[6]] = TK - TL;
        ri[idxs[1]] = TK + TL;
        TV = KP781831482 * TS + KP974927912 * TT + KP433883739 * TU;
        TW = KP623489801 * TO + TR - (KP900968867 * TQ + KP222520933 * TP);
        ii[idxs[1]] = TV + TW;
        ii[idxs[6]] = TW - TV;
    }

    {
        E TN, TM, TZ, T10;
        TN = KP433883739 * TC + KP974927912 * TF - KP781831482 * TI;
        TM = KP623489801 * Tn + T1 - (KP222520933 * Ty + KP900968867 * Tc);
        ri[idxs[4]] = TM - TN;
        ri[idxs[3]] = TM + TN;
        TZ = KP433883739 * TS + KP974927912 * TU - KP781831482 * TT;
        T10 = KP623489801 * TP + TR - (KP222520933 * TQ + KP900968867 * TO);
        ii[idxs[3]] = TZ + T10;
        ii[idxs[4]] = T10 - TZ;
    }
}
}

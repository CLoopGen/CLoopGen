#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP974927912;
extern  E KP781831482;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 12); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TT, Tc, TV, TC, TO, Tn, TS, TI, TP, Ty, TU, TF, TQ;
    E cr_vals[7], ci_vals[7];
    INT idxs[7];
    
    idxs[0] = 0;
    idxs[1] = rs[1];
    idxs[2] = rs[2];
    idxs[3] = rs[3];
    idxs[4] = rs[4];
    idxs[5] = rs[5];
    idxs[6] = rs[6];

    for (INT i = 0; i < 7; i++) {
        cr_vals[i] = cr[idxs[i]];
        ci_vals[i] = ci[-idxs[i]];
    }

    T1 = cr_vals[0];
    TT = ci_vals[0];

    {
        E T6, TA, Tb, TB;
        T6 = (W[0] * cr_vals[1]) + (W[1] * ci_vals[1]);
        TA = (W[0] * ci_vals[1]) - (W[1] * cr_vals[1]);
        Tb = (W[10] * cr_vals[6]) + (W[11] * ci_vals[6]);
        TB = (W[10] * ci_vals[6]) - (W[11] * cr_vals[6]);
        Tc = T6 + Tb;
        TV = TA + TB;
        TC = TA - TB;
        TO = Tb - T6;
    }

    {
        E Th, TG, Tm, TH;
        Th = (W[2] * cr_vals[2]) + (W[3] * ci_vals[2]);
        TG = (W[2] * ci_vals[2]) - (W[3] * cr_vals[2]);
        Tm = (W[8] * cr_vals[5]) + (W[9] * ci_vals[5]);
        TH = (W[8] * ci_vals[5]) - (W[9] * cr_vals[5]);
        Tn = Th + Tm;
        TS = TG + TH;
        TI = TG - TH;
        TP = Th - Tm;
    }

    {
        E Ts, TD, Tx, TE;
        Ts = (W[4] * cr_vals[3]) + (W[5] * ci_vals[3]);
        TD = (W[4] * ci_vals[3]) - (W[5] * cr_vals[3]);
        Tx = (W[6] * cr_vals[4]) + (W[7] * ci_vals[4]);
        TE = (W[6] * ci_vals[4]) - (W[7] * cr_vals[4]);
        Ty = Ts + Tx;
        TU = TD + TE;
        TF = TD - TE;
        TQ = Tx - Ts;
    }

    {
        E TL, TK, TZ, T10;
        cr[0] = T1 + Tc + Tn + Ty;
        TL = (KP781831482 * TC) + (KP974927912 * TI) + (KP433883739 * TF);
        TK = (KP623489801 * Tc) + T1 - (KP900968867 * Ty + KP222520933 * Tn);
        ci[0] = TK - TL;
        cr[idxs[1]] = TK + TL;
        ci[-idxs[6]] = TV + TS + TU + TT;
        TZ = (KP781831482 * TO) + (KP433883739 * TQ) - (KP974927912 * TP);
        T10 = (KP623489801 * TV) + TT - (KP900968867 * TU + KP222520933 * TS);
        cr[idxs[6]] = TZ - T10;
        ci[-idxs[5]] = TZ + T10;
    }

    {
        E TX, TY, TR, TW;
        TX = (KP974927912 * TO) + (KP433883739 * TP) - (KP781831482 * TQ);
        TY = (KP623489801 * TU) + TT - (KP900968867 * TS + KP222520933 * TV);
        cr[idxs[5]] = TX - TY;
        ci[-idxs[4]] = TX + TY;
        TR = (KP433883739 * TO) + (KP781831482 * TP) + (KP974927912 * TQ);
        TW = (KP623489801 * TS) + TT - (KP222520933 * TU + KP900968867 * TV);
        cr[idxs[4]] = TR - TW;
        ci[-idxs[3]] = TR + TW;
    }

    {
        E TN, TM, TJ, Tz;
        TN = (KP433883739 * TC) + (KP974927912 * TF) - (KP781831482 * TI);
        TM = (KP623489801 * Tn) + T1 - (KP222520933 * Ty + KP900968867 * Tc);
        ci[-idxs[2]] = TM - TN;
        cr[idxs[3]] = TM + TN;
        TJ = (KP974927912 * TC) - (KP781831482 * TF) - (KP433883739 * TI);
        Tz = (KP623489801 * Ty) + T1 - (KP900968867 * Tn + KP222520933 * Tc);
        ci[-idxs[1]] = Tz - TJ;
        cr[idxs[2]] = Tz + TJ;
    }
}
}

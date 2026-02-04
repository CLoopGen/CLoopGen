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
for (m = mb; m < me; m += 2 , cr = cr + (ms * 2) , ci = ci - (ms * 2) , W = W + 24 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;

    for (INT step = 0; step < 2; ++step) {
        E T1, TT, Tc, TV, TC, TO, Tn, TS, TI, TP, Ty, TU, TF, TQ;
        INT idx_offset = step * ms;
        INT w_offset = step * 12;
        stride rs_local = rs + step * fftw_an_INT_guaranteed_to_be_zero;

        T1 = cr[idx_offset + 0];
        TT = ci[-idx_offset + 0];

        {
            E T6, TA, Tb, TB;
            T6 = (W[w_offset + 0] * cr[rs_local[1]]) + (W[w_offset + 1] * ci[rs_local[1]]);
            TA = (W[w_offset + 0] * ci[rs_local[1]]) - (W[w_offset + 1] * cr[rs_local[1]]);
            Tb = (W[w_offset + 10] * cr[rs_local[6]]) + (W[w_offset + 11] * ci[rs_local[6]]);
            TB = (W[w_offset + 10] * ci[rs_local[6]]) - (W[w_offset + 11] * cr[rs_local[6]]);
            Tc = T6 + Tb;
            TV = TA + TB;
            TC = TA - TB;
            TO = Tb - T6;
        }
        {
            E Th, TG, Tm, TH;
            Th = (W[w_offset + 2] * cr[rs_local[2]]) + (W[w_offset + 3] * ci[rs_local[2]]);
            TG = (W[w_offset + 2] * ci[rs_local[2]]) - (W[w_offset + 3] * cr[rs_local[2]]);
            Tm = (W[w_offset + 8] * cr[rs_local[5]]) + (W[w_offset + 9] * ci[rs_local[5]]);
            TH = (W[w_offset + 8] * ci[rs_local[5]]) - (W[w_offset + 9] * cr[rs_local[5]]);
            Tn = Th + Tm;
            TS = TG + TH;
            TI = TG - TH;
            TP = Th - Tm;
        }
        {
            E Ts, TD, Tx, TE;
            Ts = (W[w_offset + 4] * cr[rs_local[3]]) + (W[w_offset + 5] * ci[rs_local[3]]);
            TD = (W[w_offset + 4] * ci[rs_local[3]]) - (W[w_offset + 5] * cr[rs_local[3]]);
            Tx = (W[w_offset + 6] * cr[rs_local[4]]) + (W[w_offset + 7] * ci[rs_local[4]]);
            TE = (W[w_offset + 6] * ci[rs_local[4]]) - (W[w_offset + 7] * cr[rs_local[4]]);
            Ty = Ts + Tx;
            TU = TD + TE;
            TF = TD - TE;
            TQ = Tx - Ts;
        }

        E TL, TK, TZ, T10;
        cr[idx_offset + 0] = T1 + Tc + Tn + Ty;
        TL = (KP781831482 * TC + KP974927912 * TI) + KP433883739 * TF;
        TK = (KP623489801 * Tc + T1) - (KP900968867 * Ty + KP222520933 * Tn);
        ci[-idx_offset + 0] = TK - TL;
        cr[rs_local[1]] = TK + TL;
        ci[-rs_local[6]] = TV + TS + TU + TT;
        TZ = (KP781831482 * TO + KP433883739 * TQ) - KP974927912 * TP;
        T10 = (KP623489801 * TV + TT) - (KP900968867 * TU + KP222520933 * TS);
        cr[rs_local[6]] = TZ - T10;
        ci[-rs_local[5]] = TZ + T10;

        E TX, TY, TR, TW;
        TX = (KP974927912 * TO + KP433883739 * TP) - KP781831482 * TQ;
        TY = (KP623489801 * TU + TT) - (KP900968867 * TS + KP222520933 * TV);
        cr[rs_local[5]] = TX - TY;
        ci[-rs_local[4]] = TX + TY;
        TR = (KP433883739 * TO + KP781831482 * TP) + KP974927912 * TQ;
        TW = (KP623489801 * TS + TT) - (KP222520933 * TU + KP900968867 * TV);
        cr[rs_local[4]] = TR - TW;
        ci[-rs_local[3]] = TR + TW;

        E TN, TM, TJ, Tz;
        TN = (KP433883739 * TC + KP974927912 * TF) - KP781831482 * TI;
        TM = (KP623489801 * Tn + T1) - (KP222520933 * Ty + KP900968867 * Tc);
        ci[-rs_local[2]] = TM - TN;
        cr[rs_local[3]] = TM + TN;
        TJ = (KP974927912 * TC - KP781831482 * TF) - KP433883739 * TI;
        Tz = (KP623489801 * Ty + T1) - (KP900968867 * Tn + KP222520933 * Tc);
        ci[-rs_local[1]] = Tz - TJ;
        cr[rs_local[2]] = Tz + TJ;
    }
}

}

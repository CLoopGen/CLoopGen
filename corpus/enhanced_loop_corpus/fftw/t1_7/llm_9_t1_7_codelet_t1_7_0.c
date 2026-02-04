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
    E T1 = ri[0], TR = ii[0];
    E T3 = ri[(rs[1])], T5 = ii[(rs[1])];
    E T8 = ri[(rs[6])], Ta = ii[(rs[6])];
    E Te = ri[(rs[2])], Tg = ii[(rs[2])];
    E Tj = ri[(rs[5])], Tl = ii[(rs[5])];
    E Tp = ri[(rs[3])], Tr = ii[(rs[3])];
    E Tu = ri[(rs[4])], Tw = ii[(rs[4])];

    E T2 = W[0], T4 = W[1], T7 = W[10], T9 = W[11];
    E Td = W[2], Tf = W[3], Ti = W[8], Tk = W[9];
    E To = W[4], Tq = W[5], Tt = W[6], Tv = W[7];

    E T6 = T2 * T3 + T4 * T5;
    E TA = T2 * T5 - T4 * T3;
    E Tb = T7 * T8 + T9 * Ta;
    E TB = T7 * Ta - T9 * T8;
    E Tc = T6 + Tb;
    E TS = Tb - T6;
    E TC = TA - TB;
    E TO = TA + TB;

    E Th = Td * Te + Tf * Tg;
    E TG = Td * Tg - Tf * Te;
    E Tm = Ti * Tj + Tk * Tl;
    E TH = Ti * Tl - Tk * Tj;
    E Tn = Th + Tm;
    E TT = Tm - Th;
    E TI = TG - TH;
    E TP = TG + TH;

    E Ts = To * Tp + Tq * Tr;
    E TD = To * Tr - Tq * Tp;
    E Tx = Tt * Tu + Tv * Tw;
    E TE = Tt * Tw - Tv * Tu;
    E Ty = Ts + Tx;
    E TU = Tx - Ts;
    E TF = TD - TE;
    E TQ = TD + TE;

    ri[0] = T1 + Tc + Tn + Ty;
    ii[0] = TO + TP + TQ + TR;

    E TJ = KP974927912 * TC - KP781831482 * TF - KP433883739 * TI;
    E Tz = KP623489801 * Ty + T1 - (KP900968867 * Tn + KP222520933 * Tc);
    ri[(rs[5])] = Tz - TJ;
    ri[(rs[2])] = Tz + TJ;

    E TX = KP974927912 * TS - KP781831482 * TU - KP433883739 * TT;
    E TY = KP623489801 * TQ + TR - (KP900968867 * TP + KP222520933 * TO);
    ii[(rs[2])] = TX + TY;
    ii[(rs[5])] = TY - TX;

    E TL = KP781831482 * TC + KP974927912 * TI + KP433883739 * TF;
    E TK = KP623489801 * Tc + T1 - (KP900968867 * Ty + KP222520933 * Tn);
    ri[(rs[6])] = TK - TL;
    ri[(rs[1])] = TK + TL;

    E TV = KP781831482 * TS + KP974927912 * TT + KP433883739 * TU;
    E TW = KP623489801 * TO + TR - (KP900968867 * TQ + KP222520933 * TP);
    ii[(rs[1])] = TV + TW;
    ii[(rs[6])] = TW - TV;

    E TN = KP433883739 * TC + KP974927912 * TF - KP781831482 * TI;
    E TM = KP623489801 * Tn + T1 - (KP222520933 * Ty + KP900968867 * Tc);
    ri[(rs[4])] = TM - TN;
    ri[(rs[3])] = TM + TN;

    E TZ = KP433883739 * TS + KP974927912 * TU - KP781831482 * TT;
    E T10 = KP623489801 * TP + TR - (KP222520933 * TQ + KP900968867 * TO);
    ii[(rs[3])] = TZ + T10;
    ii[(rs[4])] = T10 - TZ;
}
}

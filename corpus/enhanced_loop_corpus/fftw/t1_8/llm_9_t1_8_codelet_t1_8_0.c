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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 14); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 14 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1e, TH, T19, TF, T13, TR, TU, Ti, T1f, TK, T16, Tu, T12, TM;
    E TP, Tj, TG, T1b, T1c, T15, T1a, T11, T14, TX, T1g, T10, T1d, TY, TZ, TL, T1i, TW, T1h, TQ, TV;

    // Reduced precision approximation: merge some operations using fused expressions
    // Also remove redundant temporaries through algebraic simplification

    E T1 = ri[0];
    E T18 = ii[0];
    E T3 = ri[(rs[4])], T5 = ii[(rs[4])];
    E T2 = W[6], T4 = W[7];
    E T6 = T2*T3 + T4*T5;
    E T17 = T2*T5 - T4*T3;
    T7 = T1 + T6;
    T1e = T18 - T17;
    TH = T1 - T6;
    T19 = T17 + T18;

    E Tw = ri[(rs[7])], Ty = ii[(rs[7])];
    E Tv = W[12], Tx = W[13];
    E Tz = Tv*Tw + Tx*Ty;
    E TS = Tv*Ty - Tx*Tw;
    E TB = ri[(rs[3])], TD = ii[(rs[3])];
    E TA = W[4], TC = W[5];
    E TE = TA*TB + TC*TD;
    E TT = TA*TD - TC*TB;
    TF = Tz + TE;
    T13 = TS + TT;
    TR = Tz - TE;
    TU = TS - TT;

    E T9 = ri[(rs[2])], Tb = ii[(rs[2])];
    E T8 = W[2], Ta = W[3];
    E Tc = T8*T9 + Ta*Tb;
    E TI = T8*Tb - Ta*T9;
    E Te = ri[(rs[6])], Tg = ii[(rs[6])];
    E Td = W[10], Tf = W[11];
    E Th = Td*Te + Tf*Tg;
    E TJ = Td*Tg - Tf*Te;
    Ti = Tc + Th;
    T1f = Tc - Th;
    TK = TI - TJ;
    T16 = TI + TJ;

    E Tl = ri[(rs[1])], Tn = ii[(rs[1])];
    E Tk = W[0], Tm = W[1];
    E To = Tk*Tl + Tm*Tn;
    E TN = Tk*Tn - Tm*Tl;
    E Tq = ri[(rs[5])], Ts = ii[(rs[5])];
    E Tp = W[8], Tr = W[9];
    E Tt = Tp*Tq + Tr*Ts;
    E TO = Tp*Ts - Tr*Tq;
    Tu = To + Tt;
    T12 = TN + TO;
    TM = To - Tt;
    TP = TN - TO;

    // Fused butterfly updates with minimized temporary storage
    Tj = T7 + Ti;
    TG = Tu + TF;
    ri[(rs[4])] = Tj - TG;
    ri[0] = Tj + TG;

    T15 = T12 + T13;
    T1a = T16 + T19;
    ii[0] = T15 + T1a;
    ii[(rs[4])] = T1a - T15;

    T11 = T7 - Ti;
    T14 = T12 - T13;
    ri[(rs[6])] = T11 - T14;
    ri[(rs[2])] = T11 + T14;

    T1b = TF - Tu;
    T1c = T19 - T16;
    ii[(rs[2])] = T1b + T1c;
    ii[(rs[6])] = T1c - T1b;

    TY = TP - TM;
    TZ = TR + TU;
    E diff_YZ = TY - TZ;
    E sum_YZ = TY + TZ;
    TX = TH - TK;
    T1g = T1e - T1f;
    T10 = KP707106781 * diff_YZ;
    T1d = KP707106781 * sum_YZ;
    ri[(rs[7])] = TX - T10;
    ii[(rs[5])] = T1g - T1d;
    ri[(rs[3])] = TX + T10;
    ii[(rs[1])] = T1d + T1g;

    TQ = TM + TP;
    TV = TR - TU;
    E sum_QV = TQ + TV;
    E diff_VQ = TV - TQ;
    TL = TH + TK;
    T1i = T1f + T1e;
    TW = KP707106781 * sum_QV;
    T1h = KP707106781 * diff_VQ;
    ri[(rs[5])] = TL - TW;
    ii[(rs[7])] = T1i - T1h;
    ri[(rs[1])] = TL + TW;
    ii[(rs[3])] = T1h + T1i;
}
}

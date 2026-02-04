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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, T3, T6, T8, Tc, Tg, Ti, Tl, Tm, Tn, Tz, Tp, Tx;
    E Tf, T1i, TL, T1d, TJ, T17, TV, TY, Ts, T1j, TO, T1a, TC, T16, TQ;
    E TT;

    T2 = W[0];
    T5 = W[1];
    T3 = W[2];
    T6 = W[3];
    Tl = W[4];
    Tm = W[5];

    Tg = T2 * T3 + T5 * T6;
    Ti = T2 * T6 - T5 * T3;
    Tn = T2 * Tl + T5 * Tm;
    Tz = Tg * Tm - Ti * Tl;
    Tp = T2 * Tm - T5 * Tl;
    Tx = Tg * Tl + Ti * Tm;

    E T1 = Rp[0];
    E T1c = Rm[0];
    E T9 = Rp[(rs[2])];
    E Td = Rm[(rs[2])];
    E Te = Tg * T9 + Ti * Td;
    E T1b = Tg * Td - Ti * T9;
    Tf = T1 + Te;
    T1i = T1c - T1b;
    TL = T1 - Te;
    T1d = T1b + T1c;

    E TD = Ip[(rs[3])];
    E TE = Im[(rs[3])];
    E TF = Tl * TD + Tm * TE;
    E TW = Tl * TE - Tm * TD;
    E TG = Ip[(rs[1])];
    E TH = Im[(rs[1])];
    E TI = T3 * TG + T6 * TH;
    E TX = T3 * TH - T6 * TG;
    TJ = TF + TI;
    T17 = TW + TX;
    TV = TF - TI;
    TY = TW - TX;

    E Th = Rp[(rs[1])];
    E Tj = Rm[(rs[1])];
    E Tk = Tg * Th + Ti * Tj;
    E TM = Tg * Tj - Ti * Th;
    E To = Rp[(rs[3])];
    E Tq = Rm[(rs[3])];
    E Tr = Tn * To + Tp * Tq;
    E TN = Tn * Tq - Tp * To;
    Ts = Tk + Tr;
    T1j = Tk - Tr;
    TO = TM - TN;
    T1a = TM + TN;

    E Tu = Ip[0];
    E Tv = Im[0];
    E Tw = T2 * Tu + T5 * Tv;
    E TR = T2 * Tv - T5 * Tu;
    E Ty = Ip[(rs[2])];
    E TA = Im[(rs[2])];
    E TB = Tx * Ty + Tz * TA;
    E TS = Tx * TA - Tz * Ty;
    TC = Tw + TB;
    T16 = TR + TS;
    TQ = Tw - TB;
    TT = TR - TS;

    E Tt = Tf + Ts;
    E TK = TC + TJ;
    Rm[(rs[3])] = Tt - TK;
    Rp[0] = Tt + TK;

    E T19 = T16 + T17;
    E T1e = T1a + T1d;
    Im[(rs[3])] = T19 - T1e;
    Ip[0] = T19 + T1e;

    E T15 = Tf - Ts;
    E T18 = T16 - T17;
    Rm[(rs[1])] = T15 - T18;
    Rp[(rs[2])] = T15 + T18;

    E T1f = TJ - TC;
    E T1g = T1d - T1a;
    Im[(rs[1])] = T1f - T1g;
    Ip[(rs[2])] = T1f + T1g;

    E T11 = TL - TO;
    E T1k = T1i - T1j;
    E T12 = TT - TQ;
    E T13 = TV + TY;
    E T14 = KP707106781 * (T12 - T13);
    E T1h = KP707106781 * (T12 + T13);
    Rm[0] = T11 - T14;
    Ip[(rs[1])] = T1h + T1k;
    Rp[(rs[3])] = T11 + T14;
    Im[(rs[2])] = T1h - T1k;

    E TP = TL + TO;
    E T1m = T1j + T1i;
    E TU = TQ + TT;
    E TZ = TV - TY;
    E T10 = KP707106781 * (TU + TZ);
    E T1l = KP707106781 * (TZ - TU);
    Rm[(rs[2])] = TP - T10;
    Ip[(rs[3])] = T1l + T1m;
    Rp[(rs[1])] = TP + T10;
    Im[0] = T1l - T1m;
}
}

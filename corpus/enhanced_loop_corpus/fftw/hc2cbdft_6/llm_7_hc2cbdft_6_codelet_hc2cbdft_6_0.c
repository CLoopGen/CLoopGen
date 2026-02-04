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
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T4, Tv, Tr, TL, Tb, Tc, Ty, TP, To, TB, Tj, TQ, Tp, Tq, TE;
    E TM;
    // Reorder computations to eliminate loop-carried dependencies and enable parallelism
    // All loads are done upfront with no interweaving of computation and store
    E T2 = Rp[0];
    E T3 = Rm[(rs[2])];
    E T8 = Rm[(rs[1])];
    E T9 = Rp[(rs[1])];
    E T5 = Rp[(rs[2])];
    E T6 = Rm[0];
    E Td = Ip[(rs[1])];
    E Te = Im[(rs[1])];
    E Tm = Ip[0];
    E Tn = Im[(rs[2])];
    E Tg = Ip[(rs[2])];
    E Th = Im[0];

    // Independent arithmetic grouped to reduce temporary lifetime and expose ILP
    T4 = T2 + T3;
    Tv = T2 - T3;
    E Ta = T8 + T9;
    E Tx = T8 - T9;
    E T7 = T5 + T6;
    E Tw = T5 - T6;

    Tr = KP866025403 * (T7 - Ta);
    TL = KP866025403 * (Tw - Tx);
    Tb = T7 + Ta;
    Tc = T4 - KP500000000 * Tb;
    Ty = Tw + Tx;
    TP = Tv - KP500000000 * Ty;

    E Tf = Td - Te;
    E TC = Te + Td;
    To = Tm - Tn;
    TB = Tm + Tn;
    E Ti = Tg - Th;
    E TD = Tg + Th;

    Tj = KP866025403 * (Tf - Ti);
    TQ = KP866025403 * (TC + TD);
    Tp = Tf + Ti;
    Tq = To - KP500000000 * Tp;
    TE = TC - TD;
    TM = KP500000000 * TE + TB;

    // Delayed stores: all writes happen at the end after full computation
    E TJ = T4 + Tb;
    E TT = To + Tp;
    E TN = TL + TM;
    E TR = TP - TQ;
    E TS = W[0]*TN + W[1]*TR;
    E TU = W[0]*TR - W[1]*TN;

    Rp[0] = TJ - TS;
    Ip[0] = TT + TU;
    Rm[0] = TJ + TS;
    Im[0] = TU - TT;

    E TW = Tc + Tj;
    E TY = Tr + Tq;
    E TZ = W[6]*TW - W[7]*TY;
    E T15 = W[7]*TW + W[6]*TY;

    E T11 = TM - TL;
    E T13 = TP + TQ;
    E T14 = W[8]*T11 + W[9]*T13;
    E T16 = W[8]*T13 - W[9]*T11;

    Rp[(rs[2])] = TZ - T14;
    Ip[(rs[2])] = T15 + T16;
    Rm[(rs[2])] = TZ + T14;
    Im[(rs[2])] = T16 - T15;

    E Tk = Tc - Tj;
    E Ts = Tq - Tr;
    E Tt = W[3]*Tk + W[2]*Ts;
    E TH = W[2]*Tk - W[3]*Ts;

    E Tz = Tv + Ty;
    E TF = TB - TE;
    E TG = W[4]*Tz - W[5]*TF;
    E TI = W[5]*Tz + W[4]*TF;

    Ip[(rs[1])] = Tt + TG;
    Rp[(rs[1])] = TH - TI;
    Im[(rs[1])] = TG - Tt;
    Rm[(rs[1])] = TH + TI;
}

}

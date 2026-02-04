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
    E T3, Ty, Td, TE, Ta, TO, Tr, TB, Tk, TL, Tn, TH;
    E temp_Rp0, temp_Rm2, temp_Ip0, temp_Im2;

    // Introduce local temporaries to break and restructure RAW/WAW dependencies
    temp_Rp0 = Rp[0];
    temp_Rm2 = Rm[(rs[2])];
    temp_Ip0 = Ip[0];
    temp_Im2 = Im[(rs[2])];

    T3 = temp_Rp0 + temp_Rm2;
    Ty = temp_Rp0 - temp_Rm2;
    Td = temp_Ip0 - temp_Im2;
    TE = temp_Ip0 + temp_Im2;

    {
        E T6, Tz, T9, TA;
        E temp_Rp2, temp_Rm0, temp_Rm1, temp_Rp1;
        temp_Rp2 = Rp[(rs[2])];
        temp_Rm0 = Rm[0];
        temp_Rm1 = Rm[(rs[1])];
        temp_Rp1 = Rp[(rs[1])];

        T6 = temp_Rp2 + temp_Rm0;
        Tz = temp_Rp2 - temp_Rm0;
        T9 = temp_Rm1 + temp_Rp1;
        TA = temp_Rm1 - temp_Rp1;

        Ta = T6 + T9;
        TO = KP866025403 * (Tz - TA);
        Tr = KP866025403 * (T6 - T9);
        TB = Tz + TA;
    }
    {
        E Tg, TG, Tj, TF;
        E temp_Ip2, temp_Im0, temp_Ip1, temp_Im1;
        temp_Ip2 = Ip[(rs[2])];
        temp_Im0 = Im[0];
        temp_Ip1 = Ip[(rs[1])];
        temp_Im1 = Im[(rs[1])];

        Tg = temp_Ip2 - temp_Im0;
        TG = temp_Ip2 + temp_Im0;
        Tj = temp_Ip1 - temp_Im1;
        TF = temp_Ip1 + temp_Im1;

        Tk = Tg + Tj;
        TL = KP866025403 * (TG + TF);
        Tn = KP866025403 * (Tj - Tg);
        TH = TF - TG;
    }

    // Reorder independent computations to modify dependency chains
    E TC, TI, Tx, TD;
    TC = Ty + TB;
    TI = TE - TH;
    Tx = W[4];
    TD = W[5];

    E TM, TS, TQ, TU, TK, TP;
    TK = Ty - KP500000000 * TB;
    TM = TK - TL;
    TS = TK + TL;
    TP = KP500000000 * TH + TE;
    TQ = TO + TP;
    TU = TP - TO;

    E To, Tu, Ts, Tw, Tm, Tq;
    Tm = T3 - KP500000000 * Ta;
    To = Tm - Tn;
    Tu = Tm + Tn;
    Tq = Td - KP500000000 * Tk;
    Ts = Tq - Tr;
    Tw = Tr + Tq;

    // Final stores with reordered writes to reduce WAW hazards
    Rp[0] = T3 + Ta;
    Rm[0] = Td + Tk;

    Ip[(rs[1])] = Tx * TC - TD * TI;
    Im[(rs[1])] = TD * TC + Tx * TI;

    {
        E Tl, Tp, Tt, Tv;
        Tl = W[2]; Tp = W[3];
        Rp[(rs[1])] = Tl * To - Tp * Ts;
        Rm[(rs[1])] = Tl * Ts + Tp * To;

        Tt = W[6]; Tv = W[7];
        Rp[(rs[2])] = Tt * Tu - Tv * Tw;
        Rm[(rs[2])] = Tt * Tw + Tv * Tu;
    }

    {
        E TJ, TN, TR, TT;
        TJ = W[0]; TN = W[1];
        Ip[0] = TJ * TM - TN * TQ;
        Im[0] = TN * TM + TJ * TQ;

        TR = W[8]; TT = W[9];
        Ip[(rs[2])] = TR * TS - TT * TU;
        Im[(rs[2])] = TT * TS + TR * TU;
    }
}
}

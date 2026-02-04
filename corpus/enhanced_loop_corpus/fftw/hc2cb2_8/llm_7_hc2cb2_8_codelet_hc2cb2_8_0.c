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
    E Tf, Ti, Tg, Tj, Tl, Tp, TP, TR, TF, TG, TH, T15, TL, TT;
    E T7, T1f, T1i, Tw, TI, TW, T18, TM, Te, T19, T1a, TD, TJ, TZ, T12;
    E TN, Tm, TE;

    // Pull independent computations forward to eliminate loop-carried dependency on memory loads
    // Fuse initial loads into early expressions where possible

    Tf = W[0];
    Ti = W[1];
    Tg = W[2];
    Tj = W[3];
    TF = W[4];
    TG = W[5];

    // Precompute common products used later
    E Th = Tf * Tg;
    E To = Ti * Tg;
    E Tk = Ti * Tj;
    E Tn = Tf * Tj;
    Tl = Th - Tk;
    Tp = Tn + To;
    TP = Th + Tk;
    TR = Tn - To;
    TH = (Tf * TF) + (Ti * TG);
    T15 = (TP * TG) - (TR * TF);
    TL = (Tf * TG) - (Ti * TF);
    TT = (TP * TF) + (TR * TG);

    // Overlap data from multiple array accesses earlier to hide latency
    E T1 = Rp[0], T2 = Rm[(rs[3])];
    E Tq = Ip[0], Tr = Im[(rs[3])];
    E T4 = Rp[(rs[2])], T5 = Rm[(rs[1])];
    E Tt = Ip[(rs[2])], Tu = Im[(rs[1])];
    E T8 = Rp[(rs[1])], T9 = Rm[(rs[2])];
    E Tx = Ip[(rs[1])], Ty = Im[(rs[2])];
    E Tb = Rm[0], Tc = Rp[(rs[3])];
    E TA = Ip[(rs[3])], TB = Im[0];

    // Perform arithmetic in parallel across different data paths
    E T3 = T1 + T2;
    E TU = T1 - T2;
    E Ts = Tq - Tr;
    E T17 = Tq + Tr;
    E T6 = T4 + T5;
    E T16 = T4 - T5;
    E Tv = Tt - Tu;
    E TV = Tt + Tu;
    E Ta = T8 + T9;
    E TX = T8 - T9;
    E Tz = Tx - Ty;
    E TY = Tx + Ty;
    E Td = Tb + Tc;
    E T10 = Tb - Tc;
    E TC = TA - TB;
    E T11 = TA + TB;

    T7 = T3 + T6;
    T1f = TU + TV;
    T1i = T17 - T16;
    Tw = Ts + Tv;
    TI = T3 - T6;
    TW = TU - TV;
    T18 = T16 + T17;
    TM = Ts - Tv;
    Te = Ta + Td;
    T19 = TX + TY;
    T1a = T10 + T11;
    TD = Tz + TC;
    TJ = TC - Tz;
    TZ = TX - TY;
    T12 = T10 - T11;
    TN = Ta - Td;

    // Break loop-carried dependency by reordering stores and using local accumulators
    // All writes happen at the end after all reads are completed

    Tm = T7 - Te;
    TE = Tw - TD;

    // Compute final values without intermediate memory updates
    E result_Rp0 = T7 + Te;
    E result_Rm0 = Tw + TD;
    E result_Rp2 = (Tl * Tm) - (Tp * TE);
    E result_Rm2 = (Tp * Tm) + (Tl * TE);

    E TQ = TI + TJ;
    E TS = TN + TM;
    E result_Rp1 = (TP * TQ) - (TR * TS);
    E result_Rm1 = (TP * TS) + (TR * TQ);

    E TK = TI - TJ;
    E TO = TM - TN;
    E result_Rp3 = (TH * TK) - (TL * TO);
    E result_Rm3 = (TH * TO) + (TL * TK);

    E T1g = KP707106781 * (T19 + T1a);
    E T1h = T1f - T1g;
    E T1l = T1f + T1g;
    E T1j = KP707106781 * (TZ - T12);
    E T1k = T1i + T1j;
    E T1m = T1i - T1j;
    E result_Ip1 = (Tg * T1h) - (Tj * T1k);
    E result_Im1 = (Tg * T1k) + (Tj * T1h);
    E result_Ip3 = (TF * T1l) - (TG * T1m);
    E result_Im3 = (TF * T1m) + (TG * T1l);

    E T13 = KP707106781 * (TZ + T12);
    E T14 = TW - T13;
    E T1d = TW + T13;
    E T1b = KP707106781 * (T19 - T1a);
    E T1c = T18 - T1b;
    E T1e = T18 + T1b;
    E result_Ip2 = (TT * T14) - (T15 * T1c);
    E result_Im2 = (T15 * T14) + (TT * T1c);
    E result_Ip0 = (Tf * T1d) - (Ti * T1e);
    E result_Im0 = (Ti * T1d) + (Tf * T1e);

    // Single batch of stores to minimize memory traffic and avoid partial updates
    Rp[0] = result_Rp0;
    Rm[0] = result_Rm0;
    Rp[(rs[1])] = result_Rp1;
    Rm[(rs[1])] = result_Rm1;
    Rp[(rs[2])] = result_Rp2;
    Rm[(rs[2])] = result_Rm2;
    Rp[(rs[3])] = result_Rp3;
    Rm[(rs[3])] = result_Rm3;

    Ip[0] = result_Ip0;
    Im[0] = result_Im0;
    Ip[(rs[1])] = result_Ip1;
    Im[(rs[1])] = result_Im1;
    Ip[(rs[2])] = result_Ip2;
    Im[(rs[2])] = result_Im2;
    Ip[(rs[3])] = result_Ip3;
    Im[(rs[3])] = result_Im3;
}
}

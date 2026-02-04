#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP572061402;
extern  E KP218508012;
extern  E KP309016994;
extern  E KP809016994;
extern  E KP559016994;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP250000000;
extern  E KP176776695;
extern  E KP395284707;
extern  E KP672498511;
extern  E KP415626937;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T8, TD, Tm, TN, T9, TC, TY, TE, Te, TF, Tl, TK, T12, TL, Tk;
    E TM, T1, T6, Tq, T1l, T1c, Tp, T1f, T1e, T1d, Ty, TW, T1g, T1m, Tx;
    E Tu;
    T8 = R1[(rs[2])];
    TD = KP707106781 * T8;
    Tm = R1[(rs[7])];
    TN = KP707106781 * Tm;
    {
        E Ta, TA, Td, TB, Tb, Tc;
        T9 = R1[(rs[6])];
        Ta = R1[(rs[8])];
        TA = T9 + Ta;
        Tb = R1[0];
        Tc = R1[(rs[4])];
        Td = Tb + Tc;
        TB = Tb - Tc;
        TC = (((KP415626937) * (TA)) + (KP672498511 * TB));
        TY = ((KP672498511 * TA) - ((KP415626937) * (TB)));
        TE = KP395284707 * (Ta - Td);
        Te = Ta + Td;
        TF = KP176776695 * Te;
    }
    {
        E Tg, TJ, Tj, TI, Th, Ti;
        Tg = R1[(rs[1])];
        Tl = R1[(rs[3])];
        TJ = Tg + Tl;
        Th = R1[(rs[5])];
        Ti = R1[(rs[9])];
        Tj = Th + Ti;
        TI = Th - Ti;
        TK = ((KP672498511 * TI) - ((KP415626937) * (TJ)));
        T12 = (((KP415626937) * (TI)) + (KP672498511 * TJ));
        TL = KP395284707 * (Tg - Tj);
        Tk = Tg + Tj;
        TM = KP176776695 * Tk;
    }
    {
        E T2, T5, T3, T4, T1a, T1b;
        T1 = R0[0];
        T2 = R0[(rs[6])];
        T5 = R0[(rs[8])];
        T3 = R0[(rs[2])];
        T4 = R0[(rs[4])];
        T1a = T4 + T2;
        T1b = T5 + T3;
        T6 = T2 + T3 - (T4 + T5);
        Tq = (((KP250000000) * (T6)) + (T1));
        T1l = ((KP587785252 * T1a) - ((KP951056516) * (T1b)));
        T1c = (((KP951056516) * (T1a)) + (KP587785252 * T1b));
        Tp = KP559016994 * (T5 + T2 - (T4 + T3));
    }
    T1f = R0[(rs[5])];
    {
        E Tv, Tw, Ts, Tt;
        Tv = R0[(rs[9])];
        Tw = R0[(rs[1])];
        Tx = Tv - Tw;
        T1e = Tv + Tw;
        Ts = R0[(rs[3])];
        Tt = R0[(rs[7])];
        Tu = Ts - Tt;
        T1d = Ts + Tt;
    }
    Ty = (((KP951056516) * (Tu)) + (KP587785252 * Tx));
    TW = ((KP587785252 * Tu) - ((KP951056516) * (Tx)));
    T1g = (((KP809016994) * (T1d)) + (KP309016994 * T1e)) + T1f;
    T1m = ((T1f) - ((KP809016994) * (T1e))) - (KP309016994 * T1d);
    {
        E T7, T1r, To, T1q, Tf, Tn;
        T7 = T1 - T6;
        T1r = T1e + T1f - T1d;
        Tf = T8 + (T9 - Te);
        Tn = (Tk - Tl) - Tm;
        To = KP707106781 * (Tf + Tn);
        T1q = KP707106781 * (Tf - Tn);
        Cr[(csr[2])] = T7 - To;
        Ci[(csi[2])] = T1q - T1r;
        Cr[(csr[7])] = T7 + To;
        Ci[(csi[7])] = T1q + T1r;
    }
    {
        E T1h, T1j, TX, T15, T10, T16, T13, T17, TV, TZ, T11;
        T1h = T1c - T1g;
        T1j = T1c + T1g;
        TV = Tq - Tp;
        TX = TV - TW;
        T15 = TV + TW;
        TZ = (((KP218508012) * (T9)) + (TD)) + TF - TE;
        T10 = TY + TZ;
        T16 = TZ - TY;
        T11 = ((TL) - ((KP218508012) * (Tl))) - (TM + TN);
        T13 = T11 - T12;
        T17 = T11 + T12;
        {
            E T14, T19, T18, T1i;
            T14 = T10 + T13;
            Cr[(csr[5])] = TX - T14;
            Cr[(csr[4])] = TX + T14;
            T19 = T17 - T16;
            Ci[(csi[5])] = T19 - T1h;
            Ci[(csi[4])] = T19 + T1h;
            T18 = T16 + T17;
            Cr[(csr[9])] = T15 - T18;
            Cr[0] = T15 + T18;
            T1i = T13 - T10;
            Ci[0] = T1i - T1j;
            Ci[(csi[9])] = T1i + T1j;
        }
    }
    {
        E T1n, T1p, Tz, TR, TH, TS, TP, TT, Tr, TG, TO;
        T1n = T1l + T1m;
        T1p = T1m - T1l;
        Tr = Tp + Tq;
        Tz = Tr + Ty;
        TR = Tr - Ty;
        TG = TD + TE + ((TF) - ((KP572061402) * (T9)));
        TH = TC + TG;
        TS = TC - TG;
        TO = TL + TM + ((TN) - ((KP572061402) * (Tl)));
        TP = TK - TO;
        TT = TK + TO;
        {
            E TQ, T1o, TU, T1k;
            TQ = TH + TP;
            Cr[(csr[6])] = Tz - TQ;
            Cr[(csr[3])] = Tz + TQ;
            T1o = TT - TS;
            Ci[(csi[6])] = T1o - T1p;
            Ci[(csi[3])] = T1o + T1p;
            TU = TS + TT;
            Cr[(csr[8])] = TR - TU;
            Cr[(csr[1])] = TR + TU;
            T1k = TP - TH;
            Ci[(csi[8])] = T1k - T1n;
            Ci[(csi[1])] = T1k + T1n;
        }
    }
}

// Additional outer loop that processes the same operation twice per original iteration
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E dummy = R0[0] + R1[0]; // Minimal placeholder to avoid empty loop
    (void)dummy;
}
}

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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T1m, TF, T17, Ts, TM, TN, Tz, Ta, Th, Ti, T1g, T1h, T1k, T10;
    E T13, T19, TG, TH, TI, T1d, T1e, T1j, TT, TW, T18;
    E temp_R0[10], temp_R1[10];
    const INT *idx = rs;

    temp_R0[0] = R0[0];
    temp_R0[2] = R0[idx[2]];
    temp_R0[4] = R0[idx[4]];
    temp_R0[6] = R0[idx[6]];
    temp_R0[8] = R0[idx[8]];
    temp_R0[1] = R0[idx[1]];
    temp_R0[3] = R0[idx[3]];
    temp_R0[5] = R0[idx[5]];
    temp_R0[7] = R0[idx[7]];
    temp_R0[9] = R0[idx[9]];

    temp_R1[0] = R1[0];
    temp_R1[2] = R1[idx[2]];
    temp_R1[4] = R1[idx[4]];
    temp_R1[6] = R1[idx[6]];
    temp_R1[8] = R1[idx[8]];
    temp_R1[1] = R1[idx[1]];
    temp_R1[3] = R1[idx[3]];
    temp_R1[5] = R1[idx[5]];
    temp_R1[7] = R1[idx[7]];
    temp_R1[9] = R1[idx[9]];

    {
        E T1, T2, T15, TD, TE, T16;
        T1 = temp_R0[0];
        T2 = temp_R0[5];
        T15 = T1 + T2;
        TD = temp_R1[7];
        TE = temp_R1[2];
        T16 = TE + TD;
        T3 = T1 - T2;
        T1m = T15 + T16;
        TF = TD - TE;
        T17 = T15 - T16;
    }
    {
        E T6, TU, Tv, T12, Ty, TZ, T9, TR, Td, TY, To, TS, Tr, TV, Tg;
        E T11;
        {
            E T4, T5, Tt, Tu;
            T4 = temp_R0[2];
            T5 = temp_R0[7];
            T6 = T4 - T5;
            TU = T4 + T5;
            Tt = temp_R1[8];
            Tu = temp_R1[3];
            Tv = Tt - Tu;
            T12 = Tt + Tu;
        }
        {
            E Tw, Tx, T7, T8;
            Tw = temp_R1[6];
            Tx = temp_R1[1];
            Ty = Tw - Tx;
            TZ = Tw + Tx;
            T7 = temp_R0[8];
            T8 = temp_R0[3];
            T9 = T7 - T8;
            TR = T7 + T8;
        }
        {
            E Tb, Tc, Tm, Tn;
            Tb = temp_R0[4];
            Tc = temp_R0[9];
            Td = Tb - Tc;
            TY = Tb + Tc;
            Tm = temp_R1[0];
            Tn = temp_R1[5];
            To = Tm - Tn;
            TS = Tm + Tn;
        }
        {
            E Tp, Tq, Te, Tf;
            Tp = temp_R1[4];
            Tq = temp_R1[9];
            Tr = Tp - Tq;
            TV = Tp + Tq;
            Te = temp_R0[6];
            Tf = temp_R0[1];
            Tg = Te - Tf;
            T11 = Te + Tf;
        }
        Ts = To - Tr;
        TM = T6 - T9;
        TN = Td - Tg;
        Tz = Tv - Ty;
        Ta = T6 + T9;
        Th = Td + Tg;
        Ti = Ta + Th;
        T1g = TY + TZ;
        T1h = T11 + T12;
        T1k = T1g + T1h;
        T10 = TY - TZ;
        T13 = T11 - T12;
        T19 = T10 + T13;
        TG = Tr + To;
        TH = Ty + Tv;
        TI = TG + TH;
        T1d = TU + TV;
        T1e = TR + TS;
        T1j = T1d + T1e;
        TT = TR - TS;
        TW = TU - TV;
        T18 = TW + TT;
    }
    Cr[(csr[5])] = T3 + Ti;
    Ci[(csi[5])] = TF - TI;
    {
        E TX, T14, T1f, T1i;
        TX = TT - TW;
        T14 = T10 - T13;
        Ci[(csi[6])] = ((KP951056516 * TX) - ((KP587785252) * (T14)));
        Ci[(csi[2])] = (((KP587785252) * (TX)) + (KP951056516 * T14));
        T1f = T1d - T1e;
        T1i = T1g - T1h;
        Ci[(csi[8])] = ((KP587785252 * T1f) - ((KP951056516) * (T1i)));
        Ci[(csi[4])] = (((KP587785252) * (T1f)) + (KP951056516 * T1i));
    }
    {
        E T1l, T1n, T1o, T1c, T1a, T1b;
        T1l = KP559016994 * (T1j - T1k);
        T1n = T1j + T1k;
        T1o = ((T1m) - ((KP250000000) * (T1n)));
        Cr[(csr[4])] = T1l + T1o;
        Cr[0] = T1m + T1n;
        Cr[(csr[8])] = T1o - T1l;
        T1c = KP559016994 * (T18 - T19);
        T1a = T18 + T19;
        T1b = ((T17) - ((KP250000000) * (T1a)));
        Cr[(csr[2])] = T1b - T1c;
        Cr[(csr[10])] = T17 + T1a;
        Cr[(csr[6])] = T1c + T1b;
    }
    {
        E TA, TC, Tl, TB, Tj, Tk;
        TA = (((KP951056516) * (Ts)) + (KP587785252 * Tz));
        TC = ((KP951056516 * Tz) - ((KP587785252) * (Ts)));
        Tj = KP559016994 * (Ta - Th);
        Tk = ((T3) - ((KP250000000) * (Ti)));
        Tl = Tj + Tk;
        TB = Tk - Tj;
        Cr[(csr[9])] = Tl - TA;
        Cr[(csr[7])] = TB + TC;
        Cr[(csr[1])] = Tl + TA;
        Cr[(csr[3])] = TB - TC;
    }
    {
        E TO, TQ, TL, TP, TJ, TK;
        TO = (((KP951056516) * (TM)) + (KP587785252 * TN));
        TQ = ((KP951056516 * TN) - ((KP587785252) * (TM)));
        TJ = (((KP250000000) * (TI)) + (TF));
        TK = KP559016994 * (TH - TG);
        TL = TJ + TK;
        TP = TK - TJ;
        Ci[(csi[1])] = TL - TO;
        Ci[(csi[7])] = TQ + TP;
        Ci[(csi[9])] = TO + TL;
        Ci[(csi[3])] = TP - TQ;
    }
}
}

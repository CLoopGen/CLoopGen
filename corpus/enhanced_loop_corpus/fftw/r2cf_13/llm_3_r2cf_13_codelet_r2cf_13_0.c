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
extern  E KP083333333;
extern  E KP075902986;
extern  E KP251768516;
extern  E KP503537032;
extern  E KP113854479;
extern  E KP265966249;
extern  E KP387390585;
extern  E KP300462606;
extern  E KP132983124;
extern  E KP258260390;
extern  E KP2_000000000;
extern  E KP1_732050807;
extern  E KP300238635;
extern  E KP011599105;
extern  E KP156891391;
extern  E KP256247671;
extern  E KP174138601;
extern  E KP575140729;
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access to indirect via index arrays to simulate irregular striding
static const INT idx_r0[] = {0, 6, 5, 3, 4, 2, 1};
static const INT idx_r1[] = {0, 1, 2, 3, 4, 5};
static const INT idx_out_csr[] = {0, 1, 2, 3, 4, 5, 6};
static const INT idx_out_csi[] = {0, 1, 2, 3, 4, 5, 6};

for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T13, Tb, Tm, TW, TX, T14, TU, T10, Tz, TB, Tu, TC, TR, T11;

    // Indirect access using index remapping
    E R0_fetched[7], R1_fetched[6];
    for (INT j = 0; j < 7; ++j) {
        R0_fetched[j] = R0[(rs[idx_r0[j]])];
    }
    for (INT k = 0; k < 6; ++k) {
        R1_fetched[k] = R1[(rs[idx_r1[k]])];
    }

    T13 = R0_fetched[0];
    {
        E Te, TO, Ta, Tv, To, T5, Tw, Tp, Th, Tr, Tk, Ts, Tl, TP, Tc;
        E Td;
        Tc = R0_fetched[4];  // rs[4]
        Td = R1_fetched[2]; // rs[2]
        Te = Tc - Td;
        TO = Tc + Td;
        {
            E T6 = R1_fetched[0], T7 = R1_fetched[1], T8 = R1_fetched[4];
            E T9 = T7 + T8;
            Ta = T6 + T9;
            Tv = T7 - T8;
            To = T6 - KP500000000 * T9;
        }
        {
            E T1 = R0_fetched[1], T2 = R0_fetched[2], T3 = R0_fetched[5]; // rs[6], rs[5], rs[2]
            E T4 = T2 + T3;
            T5 = T1 + T4;
            Tw = T2 - T3;
            Tp = T1 - KP500000000 * T4;
        }
        {
            E Tf = R1_fetched[5], Tg = R0_fetched[3];
            Th = Tf - Tg;
            Tr = Tf + Tg;
            E Ti = R1_fetched[3], Tj = R0_fetched[6];
            Tk = Ti - Tj;
            Ts = Ti + Tj;
        }
        Tl = Th + Tk;
        TP = Tr + Ts;
        Tb = T5 - Ta;
        Tm = Te + Tl;
        TW = Ta + T5;
        TX = TO + TP;
        T14 = TW + TX;
        {
            E TS, TT, Tx, Ty;
            TS = Tv + Tw;
            TT = Th - Tk;
            TU = TS - TT;
            T10 = TS + TT;
            Tx = KP866025403 * (Tv - Tw);
            Ty = Te - KP500000000 * Tl;
            Tz = Tx + Ty;
            TB = Ty - Tx;
        }
        {
            E Tq, Tt, TN, TQ;
            Tq = To - Tp;
            Tt = KP866025403 * (Tr - Ts);
            Tu = Tq - Tt;
            TC = Tq + Tt;
            TN = To + Tp;
            TQ = TO - KP500000000 * TP;
            TR = TN - TQ;
            T11 = TN + TQ;
        }
    }
    Cr[idx_out_csr[0]] = T13 + T14;
    {
        E Tn, TG, TE, TF, TJ, TM, TK, TL;
        Tn = KP575140729 * Tb - KP174138601 * Tm;
        TG = KP174138601 * Tb + KP575140729 * Tm;
        {
            E TA = KP256247671 * Tu - KP156891391 * Tz;
            E TD = KP011599105 * TB - KP300238635 * TC;
            TE = TA + TD;
            TF = KP1_732050807 * (TD - TA);
            E TH = KP300238635 * TB + KP011599105 * TC;
            E TI = KP256247671 * Tz + KP156891391 * Tu;
            TJ = TH - TI;
            TM = KP1_732050807 * (TI + TH);
        }
        Ci[csi[idx_out_csi[5]]] = KP2_000000000 * TE + Tn;
        Ci[csi[idx_out_csi[1]]] = KP2_000000000 * TJ + TG;
        TK = TG - TJ;
        Ci[csi[idx_out_csi[4]]] = TF - TK;
        Ci[csi[idx_out_csi[3]]] = TF + TK;
        TL = Tn - TE;
        Ci[csi[idx_out_csi[2]]] = TL - TM;
        Ci[csi[idx_out_csi[6]]] = TL + TM;
    }
    {
        E TZ, T1b, T19, T1e, T16, T1a, TV, TY, T1c, T1d;
        TV = KP258260390 * TR - KP132983124 * TU;
        TY = KP300462606 * (TW - TX);
        TZ = KP2_000000000 * TV + TY;
        T1b = TY - TV;
        {
            E T17 = KP387390585 * TU + KP265966249 * TR;
            E T18 = KP113854479 * T10 - KP503537032 * T11;
            T19 = T17 - T18;
            T1e = T17 + T18;
            E T12 = KP251768516 * T10 + KP075902986 * T11;
            E T15 = T13 - KP083333333 * T14;
            T16 = KP2_000000000 * T12 + T15;
            T1a = T15 - T12;
        }
        Cr[csr[idx_out_csr[1]]] = TZ + T16;
        Cr[csr[idx_out_csr[5]]] = T16 - TZ;
        T1c = T1a - T1b;
        Cr[csr[idx_out_csr[2]]] = T19 + T1c;
        Cr[csr[idx_out_csr[6]]] = T1c - T19;
        T1d = T1b + T1a;
        Cr[csr[idx_out_csr[3]]] = T1d - T1e;
        Cr[csr[idx_out_csr[4]]] = T1e + T1d;
    }
}
}

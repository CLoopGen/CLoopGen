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
extern  E KP1_414213562;
extern  E KP2_000000000;
extern  E KP250000000;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Tj, T1k, T13, T8, Tk, T17, Ts, T16, TI, T18, T19, Ta, Tu, T1i;
    E TS, Th, Tv, TX, TD, TV, TL, TW, TY;
    E temp_Cr[10], temp_Ci[10];
    
    // Introduce local caching to remove immediate RAW dependencies on global arrays
    for (INT idx = 0; idx < 10; ++idx) {
        temp_Cr[idx] = Cr[csr[idx]];
        temp_Ci[idx] = Ci[csi[idx]];
    }

    {
        E T7, T12, T4, T11;
        T1 = temp_Cr[2];
        {
            E T5, T6, T2, T3;
            T5 = temp_Cr[9];
            T6 = temp_Cr[5];
            T7 = T5 + T6;
            T12 = T5 - T6;
            T2 = temp_Cr[6];
            T3 = temp_Cr[1];
            T4 = T2 + T3;
            T11 = T2 - T3;
        }
        Tj = KP559016994 * (T4 - T7);
        T1k = ((KP587785252 * T11) - ((KP951056516) * (T12)));
        T13 = (((KP951056516) * (T11)) + (KP587785252 * T12));
        T8 = T4 + T7;
        Tk = ((T1) - ((KP250000000) * (T8)));
    }
    {
        E Tr, T15, To, T14;
        T17 = temp_Ci[2];
        {
            E Tp, Tq, Tm, Tn;
            Tp = temp_Ci[5];
            Tq = temp_Ci[9];
            Tr = Tp - Tq;
            T15 = Tp + Tq;
            Tm = temp_Ci[6];
            Tn = temp_Ci[1];
            To = Tm + Tn;
            T14 = Tm - Tn;
        }
        Ts = (((KP951056516) * (To)) + (KP587785252 * Tr));
        T16 = KP559016994 * (T14 + T15);
        TI = ((KP587785252 * To) - ((KP951056516) * (Tr)));
        T18 = T14 - T15;
        T19 = ((T17) - ((KP250000000) * (T18)));
    }
    {
        E Tg, TR, Td, TQ;
        Ta = temp_Cr[7];
        {
            E Te, Tf, Tb, Tc;
            Te = temp_Cr[0];
            Tf = temp_Cr[4];
            Tg = Te + Tf;
            TR = Te - Tf;
            Tb = temp_Cr[3];
            Tc = temp_Cr[8];
            Td = Tb + Tc;
            TQ = Tb - Tc;
        }
        Tu = KP559016994 * (Td - Tg);
        T1i = ((KP587785252 * TQ) - ((KP951056516) * (TR)));
        TS = (((KP951056516) * (TQ)) + (KP587785252 * TR));
        Th = Td + Tg;
        Tv = ((Ta) - ((KP250000000) * (Th)));
    }
    {
        E TC, TU, Tz, TT;
        TX = temp_Ci[7];
        {
            E TA, TB, Tx, Ty;
            TA = temp_Ci[4];
            TB = temp_Ci[0];
            TC = TA - TB;
            TU = TB + TA;
            Tx = temp_Ci[3];
            Ty = temp_Ci[8];
            Tz = Tx + Ty;
            TT = Ty - Tx;
        }
        TD = (((KP951056516) * (Tz)) + (KP587785252 * TC));
        TV = KP559016994 * (TT - TU);
        TL = ((KP951056516 * TC) - ((KP587785252) * (Tz)));
        TW = TT + TU;
        TY = (((KP250000000) * (TW)) + (TX));
    }
    {
        E T9, Ti, T1w, T1t, T1u, T1v;
        T9 = T1 + T8;
        Ti = Ta + Th;
        T1w = T9 - Ti;
        T1t = T18 + T17;
        T1u = TX - TW;
        T1v = T1t + T1u;
        R0[0] = KP2_000000000 * (T9 + Ti);
        R0[(rs[5])] = KP2_000000000 * (T1u - T1t);
        R1[(rs[2])] = KP1_414213562 * (T1v - T1w);
        R1[(rs[7])] = KP1_414213562 * (T1w + T1v);
    }
    {
        E TJ, TO, T1m, T1q, TM, TN, T1j, T1r;
        {
            E TH, T1l, TK, T1h;
            TH = Tk - Tj;
            TJ = TH + TI;
            TO = TH - TI;
            T1l = T19 - T16;
            T1m = T1k + T1l;
            T1q = T1l - T1k;
            TK = Tv - Tu;
            TM = TK + TL;
            TN = TL - TK;
            T1h = TV + TY;
            T1j = T1h - T1i;
            T1r = T1i + T1h;
        }
        R0[(rs[4])] = KP2_000000000 * (TJ + TM);
        R0[(rs[6])] = KP2_000000000 * (TN - TO);
        R0[(rs[9])] = KP2_000000000 * (T1r - T1q);
        R0[(rs[1])] = KP2_000000000 * (T1j - T1m);
        {
            E T1p, T1s, T1n, T1o;
            T1p = TM - TJ;
            T1s = T1q + T1r;
            R1[(rs[1])] = KP1_414213562 * (T1p - T1s);
            R1[(rs[6])] = KP1_414213562 * (T1p + T1s);
            T1n = TO + TN;
            T1o = T1m + T1j;
            R1[(rs[8])] = KP1_414213562 * (T1n - T1o);
            R1[(rs[3])] = KP1_414213562 * (T1n + T1o);
        }
    }
    {
        E Tt, TG, T1b, T1f, TE, TF, T10, T1e;
        {
            E Tl, T1a, Tw, TZ;
            Tl = Tj + Tk;
            Tt = Tl - Ts;
            TG = Tl + Ts;
            T1a = T16 + T19;
            T1b = T13 + T1a;
            T1f = T1a - T13;
            Tw = Tu + Tv;
            TE = Tw + TD;
            TF = TD - Tw;
            TZ = TV - TY;
            T10 = TS + TZ;
            T1e = TZ - TS;
        }
        R0[(rs[8])] = KP2_000000000 * (Tt + TE);
        R0[(rs[2])] = KP2_000000000 * (TF - TG);
        R0[(rs[7])] = KP2_000000000 * (T1f + T1e);
        R0[(rs[3])] = KP2_000000000 * (T1b + T10);
        {
            E T1d, T1g, TP, T1c;
            T1d = TG + TF;
            T1g = T1e - T1f;
            R1[(rs[4])] = KP1_414213562 * (T1d + T1g);
            R1[(rs[9])] = KP1_414213562 * (T1g - T1d);
            TP = Tt - TE;
            T1c = T10 - T1b;
            R1[0] = KP1_414213562 * (TP + T1c);
            R1[(rs[5])] = KP1_414213562 * (T1c - TP);
        }
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP984807753;
extern  E KP173648177;
extern  E KP342020143;
extern  E KP939692620;
extern  E KP642787609;
extern  E KP766044443;
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 16); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 16 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, Tl, TM, T1o, T16, T1y, Ta, Tf, Tg, Tq, Tv, Tw, TT, T17, T1u;
    E T1A, T1r, T1z, T10, T18;
    
    // Control dependency: Skip first iteration using conditional guard
    if (m == mb) continue;

    {
        E T1, Th, T4, T14, Tk, TL, TK, T15;
        T1 = cr[0];
        Th = ci[(rs[8])];
        {
            E T2, T3, Ti, Tj;
            T2 = cr[(rs[3])];
            T3 = ci[(rs[2])];
            T4 = T2 + T3;
            T14 = KP866025403 * (T2 - T3);
            Ti = ci[(rs[5])];
            Tj = cr[(rs[6])];
            Tk = Ti - Tj;
            TL = KP866025403 * (Ti + Tj);
        }
        T5 = T1 + T4;
        Tl = Th + Tk;
        TK = ((T1) - ((KP500000000) * (T4)));
        TM = TK - TL;
        T1o = TK + TL;
        T15 = ((Th) - ((KP500000000) * (Tk)));
        T16 = T14 + T15;
        T1y = T15 - T14;
    }
    {
        E T6, T9, TN, TQ, Tm, Tp, TO, TR, Tb, Te, TU, TX, Tr, Tu, TV;
        E TY;
        {
            E T7, T8, Tn, To;
            T6 = cr[(rs[1])];
            T7 = cr[(rs[4])];
            T8 = ci[(rs[1])];
            T9 = T7 + T8;
            TN = ((T6) - ((KP500000000) * (T9)));
            TQ = KP866025403 * (T7 - T8);
            Tm = ci[(rs[7])];
            Tn = ci[(rs[4])];
            To = cr[(rs[7])];
            Tp = Tn - To;
            TO = KP866025403 * (Tn + To);
            TR = ((Tm) - ((KP500000000) * (Tp)));
        }
        {
            E Tc, Td, Ts, Tt;
            Tb = cr[(rs[2])];
            Tc = ci[(rs[3])];
            Td = ci[0];
            Te = Tc + Td;
            TU = ((Tb) - ((KP500000000) * (Te)));
            TX = KP866025403 * (Tc - Td);
            Tr = ci[(rs[6])];
            Ts = cr[(rs[5])];
            Tt = cr[(rs[8])];
            Tu = Ts + Tt;
            TV = KP866025403 * (Ts - Tt);
            TY = (((KP500000000) * (Tu)) + (Tr));
        }
        {
            E TP, TS, T1s, T1t;
            Ta = T6 + T9;
            Tf = Tb + Te;
            Tg = Ta + Tf;
            Tq = Tm + Tp;
            Tv = Tr - Tu;
            Tw = Tq + Tv;
            TP = TN - TO;
            TS = TQ + TR;
            TT = ((KP766044443 * TP) - ((KP642787609) * (TS)));
            T17 = (((KP766044443) * (TS)) + (KP642787609 * TP));
            T1s = TU - TV;
            T1t = TY - TX;
            T1u = (((KP939692620) * (T1s)) + (KP342020143 * T1t));
            T1A = ((KP342020143 * T1s) - ((KP939692620) * (T1t)));
            {
                E T1p, T1q, TW, TZ;
                T1p = TN + TO;
                T1q = TR - TQ;
                T1r = ((KP173648177 * T1p) - ((KP984807753) * (T1q)));
                T1z = (((KP173648177) * (T1q)) + (KP984807753 * T1p));
                TW = TU + TV;
                TZ = TX + TY;
                T10 = ((KP173648177 * TW) - ((KP984807753) * (TZ)));
                T18 = (((KP984807753) * (TW)) + (KP173648177 * TZ));
            }
        }
    }
    cr[0] = T5 + Tg;
    ci[0] = Tl + Tw;
    {
        E TA, TG, TE, TI;
        {
            E Ty, Tz, TC, TD;
            Ty = ((T5) - ((KP500000000) * (Tg)));
            Tz = KP866025403 * (Tv - Tq);
            TA = Ty - Tz;
            TG = Ty + Tz;
            TC = ((Tl) - ((KP500000000) * (Tw)));
            TD = KP866025403 * (Ta - Tf);
            TE = TC - TD;
            TI = TD + TC;
        }
        {
            E Tx, TB, TF, TH;
            Tx = W[10];
            TB = W[11];
            cr[(rs[6])] = ((Tx * TA) - ((TB) * (TE)));
            ci[(rs[6])] = (((Tx) * (TE)) + (TB * TA));
            TF = W[4];
            TH = W[5];
            cr[(rs[3])] = ((TF * TG) - ((TH) * (TI)));
            ci[(rs[3])] = (((TF) * (TI)) + (TH * TG));
        }
    }
    {
        E T1d, T1h, T12, T1c, T1a, T1g, T11, T19, TJ, T13;
        T1d = KP866025403 * (T18 - T17);
        T1h = KP866025403 * (TT - T10);
        T11 = TT + T10;
        T12 = TM + T11;
        T1c = ((TM) - ((KP500000000) * (T11)));
        T19 = T17 + T18;
        T1a = T16 + T19;
        T1g = ((T16) - ((KP500000000) * (T19)));
        TJ = W[0];
        T13 = W[1];
        cr[(rs[1])] = ((TJ * T12) - ((T13) * (T1a)));
        ci[(rs[1])] = (((T13) * (T12)) + (TJ * T1a));
        {
            E T1k, T1m, T1j, T1l;
            T1k = T1c + T1d;
            T1m = T1h + T1g;
            T1j = W[6];
            T1l = W[7];
            cr[(rs[4])] = ((T1j * T1k) - ((T1l) * (T1m)));
            ci[(rs[4])] = (((T1j) * (T1m)) + (T1l * T1k));
        }
        {
            E T1e, T1i, T1b, T1f;
            T1e = T1c - T1d;
            T1i = T1g - T1h;
            T1b = W[12];
            T1f = W[13];
            cr[(rs[7])] = ((T1b * T1e) - ((T1f) * (T1i)));
            ci[(rs[7])] = (((T1b) * (T1i)) + (T1f * T1e));
        }
    }
    {
        E T1F, T1J, T1w, T1E, T1C, T1I, T1v, T1B, T1n, T1x;
        T1F = KP866025403 * (T1A - T1z);
        T1J = KP866025403 * (T1r + T1u);
        T1v = T1r - T1u;
        T1w = T1o + T1v;
        T1E = ((T1o) - ((KP500000000) * (T1v)));
        T1B = T1z + T1A;
        T1C = T1y + T1B;
        T1I = ((T1y) - ((KP500000000) * (T1B)));
        T1n = W[2];
        T1x = W[3];
        cr[(rs[2])] = ((T1n * T1w) - ((T1x) * (T1C)));
        ci[(rs[2])] = (((T1n) * (T1C)) + (T1x * T1w));
        {
            E T1M, T1O, T1L, T1N;
            T1M = T1F + T1E;
            T1O = T1I + T1J;
            T1L = W[8];
            T1N = W[9];
            cr[(rs[5])] = ((T1L * T1M) - ((T1N) * (T1O)));
            ci[(rs[5])] = (((T1N) * (T1M)) + (T1L * T1O));
        }
        {
            E T1G, T1K, T1D, T1H;
            T1G = T1E - T1F;
            T1K = T1I - T1J;
            T1D = W[14];
            T1H = W[15];
            cr[(rs[8])] = ((T1D * T1G) - ((T1H) * (T1K)));
            ci[(rs[8])] = (((T1H) * (T1G)) + (T1D * T1K));
        }
    }
}
}

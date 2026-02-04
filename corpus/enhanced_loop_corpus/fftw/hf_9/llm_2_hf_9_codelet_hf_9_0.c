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
extern  E KP642787609;
extern  E KP766044443;
extern  E KP939692620;
extern  E KP342020143;
extern  E KP984807753;
extern  E KP173648177;
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 16); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 16 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T1B, TQ, T1A, Tc, TN, T1C, T1D, TL, T1x, T19, T1o, T1c, T1n, Tu;
    E T1w, TW, T1k, T11, T1l;
    const stride * restrict s = &rs; // Indirect stride access via pointer
    R * restrict cr_local = cr;       // Local restrict pointers for better aliasing
    R * restrict ci_local = ci;
    R * restrict W_local = W;

    {
        E T6, TO, Tb, TP;
        T1 = cr_local[0];
        T1B = ci_local[0];
        {
            E T3, T5, T2, T4;
            T3 = cr_local[s[0][3]];
            T5 = ci_local[s[0][3]];
            T2 = W_local[4];
            T4 = W_local[5];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TO = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = cr_local[s[0][6]];
            Ta = ci_local[s[0][6]];
            T7 = W_local[10];
            T9 = W_local[11];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            TP = ((T7 * Ta) - ((T9) * (T8)));
        }
        TQ = KP866025403 * (TO - TP);
        T1A = KP866025403 * (Tb - T6);
        Tc = T6 + Tb;
        TN = ((T1) - ((KP500000000) * (Tc)));
        T1C = TO + TP;
        T1D = ((T1B) - ((KP500000000) * (T1C)));
    }
    {
        E Tz, T13, TE, T14, TJ, T15, TK, T16;
        {
            E Tw, Ty, Tv, Tx;
            Tw = cr_local[s[0][2]];
            Ty = ci_local[s[0][2]];
            Tv = W_local[2];
            Tx = W_local[3];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            T13 = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = cr_local[s[0][5]];
            TD = ci_local[s[0][5]];
            TA = W_local[8];
            TC = W_local[9];
            TE = (((TA) * (TB)) + (TC * TD));
            T14 = ((TA * TD) - ((TC) * (TB)));
        }
        {
            E TG, TI, TF, TH;
            TG = cr_local[s[0][8]];
            TI = ci_local[s[0][8]];
            TF = W_local[14];
            TH = W_local[15];
            TJ = (((TF) * (TG)) + (TH * TI));
            T15 = ((TF * TI) - ((TH) * (TG)));
        }
        TK = TE + TJ;
        T16 = T14 + T15;
        TL = Tz + TK;
        T1x = T13 + T16;
        {
            E T17, T18, T1a, T1b;
            T17 = ((T13) - ((KP500000000) * (T16)));
            T18 = KP866025403 * (TJ - TE);
            T19 = T17 - T18;
            T1o = T18 + T17;
            T1a = ((Tz) - ((KP500000000) * (TK)));
            T1b = KP866025403 * (T14 - T15);
            T1c = T1a - T1b;
            T1n = T1a + T1b;
        }
    }
    {
        E Ti, TX, Tn, TT, Ts, TU, Tt, TY;
        {
            E Tf, Th, Te, Tg;
            Tf = cr_local[s[0][1]];
            Th = ci_local[s[0][1]];
            Te = W_local[0];
            Tg = W_local[1];
            Ti = (((Te) * (Tf)) + (Tg * Th));
            TX = ((Te * Th) - ((Tg) * (Tf)));
        }
        {
            E Tk, Tm, Tj, Tl;
            Tk = cr_local[s[0][4]];
            Tm = ci_local[s[0][4]];
            Tj = W_local[6];
            Tl = W_local[7];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            TT = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        {
            E Tp, Tr, To, Tq;
            Tp = cr_local[s[0][7]];
            Tr = ci_local[s[0][7]];
            To = W_local[12];
            Tq = W_local[13];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            TU = ((To * Tr) - ((Tq) * (Tp)));
        }
        Tt = Tn + Ts;
        TY = TT + TU;
        Tu = Ti + Tt;
        T1w = TX + TY;
        {
            E TS, TV, TZ, T10;
            TS = ((Ti) - ((KP500000000) * (Tt)));
            TV = KP866025403 * (TT - TU);
            TW = TS - TV;
            T1k = TS + TV;
            TZ = ((TX) - ((KP500000000) * (TY)));
            T10 = KP866025403 * (Ts - Tn);
            T11 = TZ - T10;
            T1l = T10 + TZ;
        }
    }
    {
        E T1y, Td, TM, T1v;
        T1y = KP866025403 * (T1w - T1x);
        Td = T1 + Tc;
        TM = Tu + TL;
        T1v = ((Td) - ((KP500000000) * (TM)));
        cr_local[0] = Td + TM;
        cr_local[s[0][3]] = T1v + T1y;
        ci_local[s[0][2]] = T1v - T1y;
    }
    {
        E TR, T1I, T1e, T1K, T1i, T1H, T1f, T1J;
        TR = TN - TQ;
        T1I = T1D - T1A;
        {
            E T12, T1d, T1g, T1h;
            T12 = (((KP173648177) * (TW)) + (KP984807753 * T11));
            T1d = ((KP342020143 * T19) - ((KP939692620) * (T1c)));
            T1e = T12 + T1d;
            T1K = KP866025403 * (T1d - T12);
            T1g = ((KP173648177 * T11) - ((KP984807753) * (TW)));
            T1h = (((KP342020143) * (T1c)) + (KP939692620 * T19));
            T1i = KP866025403 * (T1g + T1h);
            T1H = T1g - T1h;
        }
        cr_local[s[0][2]] = TR + T1e;
        ci_local[s[0][6]] = T1H + T1I;
        T1f = ((TR) - ((KP500000000) * (T1e)));
        ci_local[0] = T1f - T1i;
        ci_local[s[0][3]] = T1f + T1i;
        T1J = (((KP500000000) * (T1H)) - (T1I));
        cr_local[s[0][5]] = T1J - T1K;
        cr_local[s[0][8]] = T1K + T1J;
    }
    {
        E T1L, T1M, T1N, T1O;
        T1L = KP866025403 * (TL - Tu);
        T1M = T1C + T1B;
        T1N = T1w + T1x;
        T1O = ((T1M) - ((KP500000000) * (T1N)));
        cr_local[s[0][6]] = T1L - T1O;
        ci_local[s[0][8]] = T1N + T1M;
        ci_local[s[0][5]] = T1L + T1O;
    }
    {
        E T1j, T1E, T1q, T1z, T1u, T1F, T1r, T1G;
        T1j = TN + TQ;
        T1E = T1A + T1D;
        {
            E T1m, T1p, T1s, T1t;
            T1m = (((KP766044443) * (T1k)) + (KP642787609 * T1l));
            T1p = (((KP173648177) * (T1n)) + (KP984807753 * T1o));
            T1q = T1m + T1p;
            T1z = KP866025403 * (T1p - T1m);
            T1s = ((KP766044443 * T1l) - ((KP642787609) * (T1k)));
            T1t = ((KP173648177 * T1o) - ((KP984807753) * (T1n)));
            T1u = KP866025403 * (T1s - T1t);
            T1F = T1s + T1t;
        }
        cr_local[s[0][1]] = T1j + T1q;
        T1r = ((T1j) - ((KP500000000) * (T1q)));
        ci_local[s[0][1]] = T1r - T1u;
        cr_local[s[0][4]] = T1r + T1u;
        ci_local[s[0][7]] = T1F + T1E;
        T1G = ((T1E) - ((KP500000000) * (T1F)));
        cr_local[s[0][7]] = T1z - T1G;
        ci_local[s[0][4]] = T1z + T1G;
    }
}
}

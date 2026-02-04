#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP939692620;
extern  E KP342020143;
extern  E KP984807753;
extern  E KP173648177;
extern  E KP642787609;
extern  E KP766044443;
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 16); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 16 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T1B, TQ, T1G, Tc, TN, T1A, T1H, TL, T1x, T17, T1o, T1c, T1n, Tu;
    E T1w, TW, T1k, T11, T1l;
    E temp_real[9], temp_imag[9];
    for (INT i = 0; i < 9; ++i) {
        temp_real[i] = 0.0;
        temp_imag[i] = 0.0;
    }
    {
        E T6, TO, Tb, TP;
        T1 = ri[0];
        T1B = ii[0];
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[3])];
            T5 = ii[(rs[3])];
            T2 = W[4];
            T4 = W[5];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TO = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = ri[(rs[6])];
            Ta = ii[(rs[6])];
            T7 = W[10];
            T9 = W[11];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            TP = ((T7 * Ta) - ((T9) * (T8)));
        }
        TQ = KP866025403 * (TO - TP);
        T1G = KP866025403 * (Tb - T6);
        Tc = T6 + Tb;
        TN = ((T1) - ((KP500000000) * (Tc)));
        T1A = TO + TP;
        T1H = ((T1B) - ((KP500000000) * (T1A)));
    }
    {
        E Tz, T19, TE, T14, TJ, T15, TK, T1a;
        {
            E Tw, Ty, Tv, Tx;
            Tw = ri[(rs[2])];
            Ty = ii[(rs[2])];
            Tv = W[2];
            Tx = W[3];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            T19 = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = ri[(rs[5])];
            TD = ii[(rs[5])];
            TA = W[8];
            TC = W[9];
            TE = (((TA) * (TB)) + (TC * TD));
            T14 = ((TA * TD) - ((TC) * (TB)));
        }
        {
            E TG, TI, TF, TH;
            TG = ri[(rs[8])];
            TI = ii[(rs[8])];
            TF = W[14];
            TH = W[15];
            TJ = (((TF) * (TG)) + (TH * TI));
            T15 = ((TF * TI) - ((TH) * (TG)));
        }
        TK = TE + TJ;
        T1a = T14 + T15;
        TL = Tz + TK;
        T1x = T19 + T1a;
        {
            E T13, T16, T18, T1b;
            T13 = ((Tz) - ((KP500000000) * (TK)));
            T16 = KP866025403 * (T14 - T15);
            T17 = T13 + T16;
            T1o = T13 - T16;
            T18 = KP866025403 * (TJ - TE);
            T1b = ((T19) - ((KP500000000) * (T1a)));
            T1c = T18 + T1b;
            T1n = T1b - T18;
        }
    }
    {
        E Ti, TY, Tn, TT, Ts, TU, Tt, TZ;
        {
            E Tf, Th, Te, Tg;
            Tf = ri[(rs[1])];
            Th = ii[(rs[1])];
            Te = W[0];
            Tg = W[1];
            Ti = (((Te) * (Tf)) + (Tg * Th));
            TY = ((Te * Th) - ((Tg) * (Tf)));
        }
        {
            E Tk, Tm, Tj, Tl;
            Tk = ri[(rs[4])];
            Tm = ii[(rs[4])];
            Tj = W[6];
            Tl = W[7];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            TT = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        {
            E Tp, Tr, To, Tq;
            Tp = ri[(rs[7])];
            Tr = ii[(rs[7])];
            To = W[12];
            Tq = W[13];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            TU = ((To * Tr) - ((Tq) * (Tp)));
        }
        Tt = Tn + Ts;
        TZ = TT + TU;
        Tu = Ti + Tt;
        T1w = TY + TZ;
        {
            E TS, TV, TX, T10;
            TS = ((Ti) - ((KP500000000) * (Tt)));
            TV = KP866025403 * (TT - TU);
            TW = TS + TV;
            T1k = TS - TV;
            TX = KP866025403 * (Ts - Tn);
            T10 = ((TY) - ((KP500000000) * (TZ)));
            T11 = TX + T10;
            T1l = T10 - TX;
        }
    }
    {
        E T1y, Td, TM, T1v;
        T1y = KP866025403 * (T1w - T1x);
        Td = T1 + Tc;
        TM = Tu + TL;
        T1v = ((Td) - ((KP500000000) * (TM)));
        temp_real[0] = Td + TM;
        temp_real[3] = T1v + T1y;
        temp_real[6] = T1v - T1y;
    }
    {
        E T1D, T1z, T1C, T1E;
        T1D = KP866025403 * (TL - Tu);
        T1z = T1w + T1x;
        T1C = T1A + T1B;
        T1E = ((T1C) - ((KP500000000) * (T1z)));
        temp_imag[0] = T1z + T1C;
        temp_imag[6] = T1E - T1D;
        temp_imag[3] = T1D + T1E;
    }
    {
        E TR, T1I, T1e, T1J, T1i, T1F, T1f, T1K;
        TR = TN + TQ;
        T1I = T1G + T1H;
        {
            E T12, T1d, T1g, T1h;
            T12 = (((KP766044443) * (TW)) + (KP642787609 * T11));
            T1d = (((KP173648177) * (T17)) + (KP984807753 * T1c));
            T1e = T12 + T1d;
            T1J = KP866025403 * (T1d - T12);
            T1g = ((KP766044443 * T11) - ((KP642787609) * (TW)));
            T1h = ((KP173648177 * T1c) - ((KP984807753) * (T17)));
            T1i = KP866025403 * (T1g - T1h);
            T1F = T1g + T1h;
        }
        temp_real[1] = TR + T1e;
        temp_imag[1] = T1F + T1I;
        T1f = ((TR) - ((KP500000000) * (T1e)));
        temp_real[7] = T1f - T1i;
        temp_real[4] = T1f + T1i;
        T1K = ((T1I) - ((KP500000000) * (T1F)));
        temp_imag[4] = T1J + T1K;
        temp_imag[7] = T1K - T1J;
    }
    {
        E T1j, T1M, T1q, T1N, T1u, T1L, T1r, T1O;
        T1j = TN - TQ;
        T1M = T1H - T1G;
        {
            E T1m, T1p, T1s, T1t;
            T1m = (((KP173648177) * (T1k)) + (KP984807753 * T1l));
            T1p = ((KP342020143 * T1n) - ((KP939692620) * (T1o)));
            T1q = T1m + T1p;
            T1N = KP866025403 * (T1p - T1m);
            T1s = ((KP173648177 * T1l) - ((KP984807753) * (T1k)));
            T1t = (((KP342020143) * (T1o)) + (KP939692620 * T1n));
            T1u = KP866025403 * (T1s + T1t);
            T1L = T1s - T1t;
        }
        temp_real[2] = T1j + T1q;
        temp_imag[2] = T1L + T1M;
        T1r = ((T1j) - ((KP500000000) * (T1q)));
        temp_real[8] = T1r - T1u;
        temp_real[5] = T1r + T1u;
        T1O = ((T1M) - ((KP500000000) * (T1L)));
        temp_imag[5] = T1N + T1O;
        temp_imag[8] = T1O - T1N;
    }
    for (INT i = 0; i < 9; ++i) {
        if (i == 0 || i == 1 || i == 2) {
            ri[i * rs[1]] = temp_real[i];
            ii[i * rs[1]] = temp_imag[i];
        } else if (i == 3 || i == 4 || i == 5) {
            ri[i * rs[1]] = temp_real[i];
            ii[i * rs[1]] = temp_imag[i];
        } else if (i == 6 || i == 7 || i == 8) {
            ri[i * rs[1]] = temp_real[i];
            ii[i * rs[1]] = temp_imag[i];
        }
    }
}
}

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

    // Variant 2: Unroll-like behavior using switch on loop index mod 3
    switch ((m - mb) % 3) {
        case 0:
        {
            E T6, TO, Tb, TP;
            T1 = cr[0];
            T1B = ci[0];
            E T3 = cr[(rs[3])], T5 = ci[(rs[3])];
            E T2 = W[4], T4 = W[5];
            T6 = T2 * T3 + T4 * T5;
            TO = T2 * T5 - T4 * T3;
            E T8 = cr[(rs[6])], Ta = ci[(rs[6])];
            E T7 = W[10], T9 = W[11];
            Tb = T7 * T8 + T9 * Ta;
            TP = T7 * Ta - T9 * T8;
            TQ = KP866025403 * (TO - TP);
            T1A = KP866025403 * (Tb - T6);
            Tc = T6 + Tb;
            TN = T1 - KP500000000 * Tc;
            T1C = TO + TP;
            T1D = T1B - KP500000000 * T1C;
            break;
        }
        case 1:
        {
            T1 = cr[0]; T1B = ci[0];
            Tc = 0.0; TN = T1; T1C = 0.0; T1D = T1B;
            TQ = T1A = 0.0;
            break;
        }
        default:
        {
            T1 = cr[0]; T1B = ci[0];
            Tc = T1; TN = -KP500000000 * Tc; T1C = T1B; T1D = -KP500000000 * T1C;
            TQ = T1A = 0.0;
            break;
        }
    }

    // Conditional execution based on phase
    if ((m - mb) % 3 == 0 || (m - mb) % 3 == 1) {
        E Tz, T13, TE, T14, TJ, T15, TK, T16;
        E Tw = cr[(rs[2])], Ty = ci[(rs[2])];
        E Tv = W[2], Tx = W[3];
        Tz = Tv * Tw + Tx * Ty;
        T13 = Tv * Ty - Tx * Tw;

        E TB = cr[(rs[5])], TD = ci[(rs[5])];
        E TA = W[8], TC = W[9];
        TE = TA * TB + TC * TD;
        T14 = TA * TD - TC * TB;

        E TG = cr[(rs[8])], TI = ci[(rs[8])];
        E TF = W[14], TH = W[15];
        TJ = TF * TG + TH * TI;
        T15 = TF * TI - TH * TG;

        TK = TE + TJ;
        T16 = T14 + T15;
        TL = Tz + TK;
        T1x = T13 + T16;

        E T17 = T13 - KP500000000 * T16;
        E T18 = KP866025403 * (TJ - TE);
        T19 = T17 - T18;
        T1o = T18 + T17;
        E T1a = Tz - KP500000000 * TK;
        E T1b = KP866025403 * (T14 - T15);
        T1c = T1a - T1b;
        T1n = T1a + T1b;
    } else {
        TL = T1x = T19 = T1o = T1c = T1n = 0.0;
    }

    // Always execute partial third block
    {
        E Ti, TX, Tn, TT, Ts, TU, Tt, TY;
        if ((m - mb) % 3 != 1) {
            E Tf = cr[(rs[1])], Th = ci[(rs[1])];
            E Te = W[0], Tg = W[1];
            Ti = Te * Tf + Tg * Th;
            TX = Te * Th - Tg * Tf;

            E Tk = cr[(rs[4])], Tm = ci[(rs[4])];
            E Tj = W[6], Tl = W[7];
            Tn = Tj * Tk + Tl * Tm;
            TT = Tj * Tm - Tl * Tk;

            E Tp = cr[(rs[7])], Tr = ci[(rs[7])];
            E To = W[12], Tq = W[13];
            Ts = To * Tp + Tq * Tr;
            TU = To * Tr - Tq * Tp;
        } else {
            Ti = Tn = Ts = 1.0;
            TX = TT = TU = 0.0;
        }

        Tt = Tn + Ts;
        TY = TT + TU;
        Tu = Ti + Tt;
        T1w = TX + TY;

        E TS = Ti - KP500000000 * Tt;
        E TV = KP866025403 * (TT - TU);
        TW = TS - TV;
        T1k = TS + TV;
        E TZ = TX - KP500000000 * TY;
        E T10 = KP866025403 * (Ts - Tn);
        T11 = TZ - T10;
        T1l = T10 + TZ;
    }

    // Merge results with conditional final stages
    {
        E T1y, Td, TM, T1v;
        T1y = KP866025403 * (T1w - T1x);
        Td = T1 + Tc;
        TM = Tu + TL;
        T1v = Td - KP500000000 * TM;
        cr[0] = Td + TM;
        if ((m - mb) % 3 == 0) {
            cr[(rs[3])] = T1v + T1y;
            ci[(rs[2])] = T1v - T1y;
        } else if ((m - mb) % 3 == 1) {
            cr[(rs[3])] = T1v;
            ci[(rs[2])] = T1v;
        }
    }

    // Selective butterfly updates
    if ((m - mb) % 3 == 0) {
        E TR = TN - TQ, T1I = T1D - T1A;
        E T12 = KP173648177 * TW + KP984807753 * T11;
        E T1d = KP342020143 * T19 - KP939692620 * T1c;
        E T1e = T12 + T1d;
        E T1K = KP866025403 * (T1d - T12);
        E T1g = KP173648177 * T11 - KP984807753 * TW;
        E T1h = KP342020143 * T1c + KP939692620 * T19;
        E T1i = KP866025403 * (T1g + T1h);
        E T1H = T1g - T1h;
        E T1f = TR - KP500000000 * T1e;
        E T1J = KP500000000 * T1H - T1I;

        cr[(rs[2])] = TR + T1e;
        ci[(rs[6])] = T1H + T1I;
        ci[0] = T1f - T1i;
        ci[(rs[3])] = T1f + T1i;
        cr[(rs[5])] = T1J - T1K;
        cr[(rs[8])] = T1K + T1J;
    }

    // Symmetric update only in phase 0 and 2
    if ((m - mb) % 3 != 1) {
        E T1L = KP866025403 * (TL - Tu);
        E T1M = T1C + T1B;
        E T1N = T1w + T1x;
        E T1O = T1M - KP500000000 * T1N;
        cr[(rs[6])] = T1L - T1O;
        ci[(rs[8])] = T1N + T1M;
        ci[(rs[5])] = T1L + T1O;
    }

    // Last stage with dynamic path
    {
        E T1j = TN + TQ, T1E = T1A + T1D;
        E T1q, T1z, T1u, T1F, T1r, T1G;
        if ((m - mb) % 3 == 0) {
            E T1m = KP766044443 * T1k + KP642787609 * T1l;
            E T1p = KP173648177 * T1n + KP984807753 * T1o;
            T1q = T1m + T1p;
            T1z = KP866025403 * (T1p - T1m);
            E T1s = KP766044443 * T1l - KP642787609 * T1k;
            E T1t = KP173648177 * T1o - KP984807753 * T1n;
            T1u = KP866025403 * (T1s - T1t);
            T1F = T1s + T1t;
        } else {
            T1q = T1j; T1z = 0.0; T1u = T1E; T1F = T1E;
        }
        cr[(rs[1])] = T1j + T1q;
        T1r = T1j - KP500000000 * T1q;
        ci[(rs[1])] = T1r - T1u;
        cr[(rs[4])] = T1r + T1u;
        ci[(rs[7])] = T1F + T1E;
        T1G = T1E - KP500000000 * T1F;
        cr[(rs[7])] = T1z - T1G;
        ci[(rs[4])] = T1z + T1G;
    }
}
}

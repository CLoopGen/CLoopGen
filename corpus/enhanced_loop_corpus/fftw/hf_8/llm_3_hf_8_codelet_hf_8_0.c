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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to indirect indexing using precomputed indices
// Improve predictability by removing strided pointer arithmetic in favor of index tables

// Precomputed offset arrays (simulated as static for consistent behavior)
static const INT offsets[8] = {0, 1, 2, 3, 4, 5, 6, 7};
E * restrict cr_base = cr;
E * restrict ci_base = ci;
stride rs_base = rs;

for (m = mb , W = W + ((mb - 1) * 14); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 14 , rs_base = rs_base + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1f, TH, T19, TF, T12, TR, TU, Ti, T1e, TK, T16, Tu, T13, TM;
    E TP;

    // Precompute actual addresses using indirect addressing via rs_base[offsets[i]]
    INT idx0 = rs_base[offsets[0]], idx1 = rs_base[offsets[1]], idx2 = rs_base[offsets[2]], idx3 = rs_base[offsets[3]];
    INT idx4 = rs_base[offsets[4]], idx5 = rs_base[offsets[5]], idx6 = rs_base[offsets[6]], idx7 = rs_base[offsets[7]];

    {
        E T1, T18, T6, T17;
        T1 = cr_base[idx0];
        T18 = ci_base[idx0];
        {
            E T3, T5, T2, T4;
            T3 = cr_base[idx4];
            T5 = ci_base[idx4];
            T2 = W[6];
            T4 = W[7];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T17 = ((T2 * T5) - ((T4) * (T3)));
        }
        T7 = T1 + T6;
        T1f = T18 - T17;
        TH = T1 - T6;
        T19 = T17 + T18;
    }
    {
        E Tz, TS, TE, TT;
        {
            E Tw, Ty, Tv, Tx;
            Tw = cr_base[idx7];
            Ty = ci_base[idx7];
            Tv = W[12];
            Tx = W[13];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            TS = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = cr_base[idx3];
            TD = ci_base[idx3];
            TA = W[4];
            TC = W[5];
            TE = (((TA) * (TB)) + (TC * TD));
            TT = ((TA * TD) - ((TC) * (TB)));
        }
        TF = Tz + TE;
        T12 = TS + TT;
        TR = Tz - TE;
        TU = TS - TT;
    }
    {
        E Tc, TI, Th, TJ;
        {
            E T9, Tb, T8, Ta;
            T9 = cr_base[idx2];
            Tb = ci_base[idx2];
            T8 = W[2];
            Ta = W[3];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            TI = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = cr_base[idx6];
            Tg = ci_base[idx6];
            Td = W[10];
            Tf = W[11];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TJ = ((Td * Tg) - ((Tf) * (Te)));
        }
        Ti = Tc + Th;
        T1e = Tc - Th;
        TK = TI - TJ;
        T16 = TI + TJ;
    }
    {
        E To, TN, Tt, TO;
        {
            E Tl, Tn, Tk, Tm;
            Tl = cr_base[idx1];
            Tn = ci_base[idx1];
            Tk = W[0];
            Tm = W[1];
            To = (((Tk) * (Tl)) + (Tm * Tn));
            TN = ((Tk * Tn) - ((Tm) * (Tl)));
        }
        {
            E Tq, Ts, Tp, Tr;
            Tq = cr_base[idx5];
            Ts = ci_base[idx5];
            Tp = W[8];
            Tr = W[9];
            Tt = (((Tp) * (Tq)) + (Tr * Ts));
            TO = ((Tp * Ts) - ((Tr) * (Tq)));
        }
        Tu = To + Tt;
        T13 = TN + TO;
        TM = To - Tt;
        TP = TN - TO;
    }
    {
        E Tj, TG, T1b, T1c;
        Tj = T7 + Ti;
        TG = Tu + TF;
        ci_base[idx3] = Tj - TG;
        cr_base[idx0] = Tj + TG;
        T1b = TF - Tu;
        T1c = T19 - T16;
        cr_base[idx6] = T1b - T1c;
        ci_base[idx5] = T1b + T1c;
        {
            E TX, T1i, T10, T1h, TY, TZ;
            TX = TH - TK;
            T1i = T1f - T1e;
            TY = TM - TP;
            TZ = TR + TU;
            T10 = KP707106781 * (TY + TZ);
            T1h = KP707106781 * (TZ - TY);
            cr_base[idx3] = TX - T10;
            ci_base[idx6] = T1h + T1i;
            ci_base[idx0] = TX + T10;
            cr_base[idx5] = T1h - T1i;
        }
    }
    {
        E T15, T1a, T11, T14;
        T15 = T13 + T12;
        T1a = T16 + T19;
        cr_base[idx4] = T15 - T1a;
        ci_base[idx7] = T15 + T1a;
        T11 = T7 - Ti;
        T14 = T12 - T13;
        cr_base[idx2] = T11 - T14;
        ci_base[idx1] = T11 + T14;
        {
            E TL, T1g, TW, T1d, TQ, TV;
            TL = TH + TK;
            T1g = T1e + T1f;
            TQ = TM + TP;
            TV = TR - TU;
            TW = KP707106781 * (TQ + TV);
            T1d = KP707106781 * (TV - TQ);
            ci_base[idx2] = TL - TW;
            ci_base[idx4] = T1d + T1g;
            cr_base[idx1] = TL + TW;
            cr_base[idx7] = T1d - T1g;
        }
    }
}
}

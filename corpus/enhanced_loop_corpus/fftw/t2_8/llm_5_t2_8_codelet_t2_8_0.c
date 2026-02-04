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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 6); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, T3, T6, T8, Tc, Tg, Ti, Tl, Tm, Tn, Tz, Tp, Tx;
    
    // Introduce control dependencies via conditional skip logic based on loop index parity
    if ((m & 1) == 0) {
        // Even iteration: full computation path
        {
            E T4, Tb, T7, Ta;
            T2 = W[0];
            T5 = W[1];
            T3 = W[2];
            T6 = W[3];
            T4 = T2 * T3;
            Tb = T5 * T3;
            T7 = T5 * T6;
            Ta = T2 * T6;
            T8 = T4 - T7;
            Tc = Ta + Tb;
            Tg = T4 + T7;
            Ti = Ta - Tb;
            Tl = W[4];
            Tm = W[5];
            Tn = T2 * Tl + T5 * Tm;
            Tz = Tg * Tm - Ti * Tl;
            Tp = T2 * Tm - T5 * Tl;
            Tx = Tg * Tl + Ti * Tm;
        }

        E Tf, T1i, TL, T1d, TJ, T17, TV, TY, Ts, T1j, TO, T1a, TC, T16, TQ, TT;

        {
            E T1, T1c, T9, Td;
            T1 = ri[0];
            T1c = ii[0];
            T9 = ri[(rs[4])];
            Td = ii[(rs[4])];
            E Te = T8 * T9 + Tc * Td;
            E T1b = T8 * Td - Tc * T9;
            Tf = T1 + Te;
            T1i = T1c - T1b;
            TL = T1 - Te;
            T1d = T1b + T1c;
        }

        {
            E TF, TW, TI, TX;
            TF = Tl * ri[(rs[7])] + Tm * ii[(rs[7])];
            TW = Tl * ii[(rs[7])] - Tm * ri[(rs[7])];
            TI = T3 * ri[(rs[3])] + T6 * ii[(rs[3])];
            TX = T3 * ii[(rs[3])] - T6 * ri[(rs[3])];
            TJ = TF + TI;
            T17 = TW + TX;
            TV = TF - TI;
            TY = TW - TX;
        }

        {
            E Tk, TM, Tr, TN;
            Tk = Tg * ri[(rs[2])] + Ti * ii[(rs[2])];
            TM = Tg * ii[(rs[2])] - Ti * ri[(rs[2])];
            Tr = Tn * ri[(rs[6])] + Tp * ii[(rs[6])];
            TN = Tn * ii[(rs[6])] - Tp * ri[(rs[6])];
            Ts = Tk + Tr;
            T1j = Tk - Tr;
            TO = TM - TN;
            T1a = TM + TN;
        }

        {
            E Tw, TR, TB, TS;
            Tw = T2 * ri[(rs[1])] + T5 * ii[(rs[1])];
            TR = T2 * ii[(rs[1])] - T5 * ri[(rs[1])];
            TB = Tx * ri[(rs[5])] + Tz * ii[(rs[5])];
            TS = Tx * ii[(rs[5])] - Tz * ri[(rs[5])];
            TC = Tw + TB;
            T16 = TR + TS;
            TQ = Tw - TB;
            TT = TR - TS;
        }

        E Tt = Tf + Ts;
        E TK = TC + TJ;
        ri[(rs[4])] = Tt - TK;
        ri[0] = Tt + TK;

        E T19 = T16 + T17;
        E T1e = T1a + T1d;
        ii[0] = T19 + T1e;
        ii[(rs[4])] = T1e - T19;

        E T15 = Tf - Ts;
        E T18 = T16 - T17;
        ri[(rs[6])] = T15 - T18;
        ri[(rs[2])] = T15 + T18;

        E T1f = TJ - TC;
        E T1g = T1d - T1a;
        ii[(rs[2])] = T1f + T1g;
        ii[(rs[6])] = T1g - T1f;

        E T12 = TT - TQ;
        E T13 = TV + TY;
        E T14 = KP707106781 * (T12 - T13);
        E T1h = KP707106781 * (T12 + T13);
        ri[(rs[7])] = (TL - TO) - T14;
        ii[(rs[5])] = (T1i - T1j) - T1h;
        ri[(rs[3])] = (TL - TO) + T14;
        ii[(rs[1])] = T1h + (T1i - T1j);

        E TU = TQ + TT;
        E TZ = TV - TY;
        E T10 = KP707106781 * (TU + TZ);
        E T1l = KP707106781 * (TZ - TU);
        ri[(rs[5])] = (TL + TO) - T10;
        ii[(rs[7])] = (T1j + T1i) - T1l;
        ri[(rs[1])] = (TL + TO) + T10;
        ii[(rs[3])] = T1l + (T1j + T1i);
    } else {
        // Odd iteration: simplified butterfly with symmetry assumption
        // Reuse twiddle factors from previous step or assume symmetry
        T2 = W[0]; T5 = W[1]; T3 = W[2]; T6 = W[3]; Tl = W[4]; Tm = W[5];
        T8 = T2 * T3 - T5 * T6;
        Tc = T2 * T6 + T5 * T3;
        Tg = T2 * T3 + T5 * T6;
        Ti = T2 * T6 - T5 * T3;
        Tn = T2 * Tl + T5 * Tm;
        Tz = Tg * Tm - Ti * Tl;
        Tp = T2 * Tm - T5 * Tl;
        Tx = Tg * Tl + Ti * Tm;

        // Minimal data flow for reduced complexity
        E a0 = ri[0], b0 = ii[0];
        E a4 = ri[(rs[4])], b4 = ii[(rs[4])];
        E sum_r = a0 + a4, diff_r = a0 - a4;
        E sum_i = b0 + b4, diff_i = b0 - b4;

        ri[0] = sum_r;
        ri[(rs[4])] = diff_r;
        ii[0] = sum_i;
        ii[(rs[4])] = diff_i;

        // Apply partial rotation only on subset
        E ar = T8 * a4 + Tc * b4;
        E ai = T8 * b4 - Tc * a4;
        ri[(rs[2])] += ar;
        ii[(rs[6])] -= ai;

        // Skip full update of other points — simulate pruning
        continue;
    }
}
}

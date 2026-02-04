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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m % 2 == 0) {
        E T1, TE, Tu, Tx, TC, TB, TF, TG, TH, Tc, Tn, To;
        T1 = cr[0];
        TE = ci[0];
        {
            E T6, Ts, Tm, Tw, Tb, Tt, Th, Tv;
            {
                E T3, T5, T2, T4;
                T3 = cr[(rs[1])];
                T5 = ci[(rs[1])];
                T2 = W[0];
                T4 = W[1];
                T6 = (((T2) * (T3)) + (T4 * T5));
                Ts = ((T2 * T5) - ((T4) * (T3)));
            }
            {
                E Tj, Tl, Ti, Tk;
                Tj = cr[(rs[3])];
                Tl = ci[(rs[3])];
                Ti = W[4];
                Tk = W[5];
                Tm = (((Ti) * (Tj)) + (Tk * Tl));
                Tw = ((Ti * Tl) - ((Tk) * (Tj)));
            }
            {
                E T8, Ta, T7, T9;
                T8 = cr[(rs[4])];
                Ta = ci[(rs[4])];
                T7 = W[6];
                T9 = W[7];
                Tb = (((T7) * (T8)) + (T9 * Ta));
                Tt = ((T7 * Ta) - ((T9) * (T8)));
            }
            {
                E Te, Tg, Td, Tf;
                Te = cr[(rs[2])];
                Tg = ci[(rs[2])];
                Td = W[2];
                Tf = W[3];
                Th = (((Td) * (Te)) + (Tf * Tg));
                Tv = ((Td * Tg) - ((Tf) * (Te)));
            }
            Tu = Ts - Tt;
            Tx = Tv - Tw;
            TC = Th - Tm;
            TB = Tb - T6;
            TF = Ts + Tt;
            TG = Tv + Tw;
            TH = TF + TG;
            Tc = T6 + Tb;
            Tn = Th + Tm;
            To = Tc + Tn;
        }
        cr[0] = T1 + To;
        {
            E Ty, TA, Tr, Tz, Tp, Tq;
            Ty = (((KP951056516) * (Tu)) + (KP587785252 * Tx));
            TA = ((KP951056516 * Tx) - ((KP587785252) * (Tu)));
            Tp = KP559016994 * (Tc - Tn);
            Tq = ((T1) - ((KP250000000) * (To)));
            Tr = Tp + Tq;
            Tz = Tq - Tp;
            ci[0] = Tr - Ty;
            ci[(rs[1])] = Tz + TA;
            cr[(rs[1])] = Tr + Ty;
            cr[(rs[2])] = Tz - TA;
        }
        ci[(rs[4])] = TH + TE;
        {
            E TD, TL, TK, TM, TI, TJ;
            TD = (((KP587785252) * (TB)) + (KP951056516 * TC));
            TL = ((KP951056516 * TB) - ((KP587785252) * (TC)));
            TI = ((TE) - ((KP250000000) * (TH)));
            TJ = KP559016994 * (TF - TG);
            TK = TI - TJ;
            TM = TJ + TI;
            cr[(rs[3])] = TD - TK;
            ci[(rs[3])] = TL + TM;
            ci[(rs[2])] = TD + TK;
            cr[(rs[4])] = TL - TM;
        }
    } else {
        // Alternate path: skip computation and only update memory pattern slightly to maintain coherence
        cr[0] = cr[0];
        ci[0] = ci[0];
    }
}
}

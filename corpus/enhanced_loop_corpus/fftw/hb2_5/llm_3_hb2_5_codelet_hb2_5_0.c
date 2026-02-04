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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with fully consecutive memory layout and local array buffering
// Assume rs is regular and convert all strided accesses into a locally buffered array

E (*local_cr)[5] = (E(*)[5])alloca(5 * sizeof(E));
E (*local_ci)[5] = (E(*)[5])alloca(5 * sizeof(E));

for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    // Pre-load data using stride into consecutive local arrays for cache efficiency
    for (INT i = 0; i < 5; i++) {
        (*local_cr)[i] = cr[rs[i]];
        (*local_ci)[i] = ci[rs[4 - i]]; // reverse indexing pattern to simulate transformation symmetry
    }

    E Th, Tk, Ti, Tl, Tn, TP, Tx, TN;
    {
        E Tj, Tw, Tm, Tv;
        Th = W[0];
        Tk = W[1];
        Ti = W[2];
        Tl = W[3];
        Tj = Th * Ti;
        Tw = Tk * Ti;
        Tm = Tk * Tl;
        Tv = Th * Tl;
        Tn = Tj + Tm;
        TP = Tv + Tw;
        Tx = Tv - Tw;
        TN = Tj - Tm;
    }
    {
        E T1, Tp, TK, TA, T8, To, T9, Tt, TI, TC, Tg, TB;
        {
            E T4, Ty, T7, Tz;
            T1 = (*local_cr)[0];
            {
                E T2, T3, T5, T6;
                T2 = (*local_cr)[1];
                T3 = (*local_ci)[4];
                T4 = T2 + T3;
                Ty = T2 - T3;
                T5 = (*local_cr)[2];
                T6 = (*local_ci)[3];
                T7 = T5 + T6;
                Tz = T5 - T6;
            }
            Tp = KP559016994 * (T4 - T7);
            TK = (((KP951056516) * (Ty)) + (KP587785252 * Tz));
            TA = ((KP587785252 * Ty) - ((KP951056516) * (Tz)));
            T8 = T4 + T7;
            To = T1 - (KP250000000 * T8);
        }
        {
            E Tc, Tr, Tf, Ts;
            T9 = (*local_ci)[0];
            {
                E Ta, Tb, Td, Te;
                Ta = (*local_ci)[1];
                Tb = (*local_cr)[4];
                Tc = Ta - Tb;
                Tr = Ta + Tb;
                Td = (*local_ci)[2];
                Te = (*local_cr)[3];
                Tf = Td - Te;
                Ts = Td + Te;
            }
            Tt = ((KP587785252 * Tr) - ((KP951056516) * (Ts)));
            TI = (((KP951056516) * (Tr)) + (KP587785252 * Ts));
            TC = KP559016994 * (Tc - Tf);
            Tg = Tc + Tf;
            TB = T9 - (KP250000000 * Tg);
        }

        // Write back base values
        cr[0] = T1 + T8;
        ci[0] = T9 + Tg;

        {
            E Tu, TF, TE, TG, Tq, TD;
            Tq = To - Tp;
            Tu = Tq - Tt;
            TF = Tq + Tt;
            TD = TB - TC;
            TE = TA + TD;
            TG = TD - TA;
            cr[rs[2]] = (Tn * Tu) - (Tx * TE);
            ci[rs[2]] = (Tn * TE) + (Tx * Tu);
            cr[rs[3]] = (Ti * TF) - (Tl * TG);
            ci[rs[3]] = (Ti * TG) + (Tl * TF);
        }
        {
            E TJ, TO, TM, TQ, TH, TL;
            TH = Tp + To;
            TJ = TH - TI;
            TO = TH + TI;
            TL = TC + TB;
            TM = TK + TL;
            TQ = TL - TK;
            cr[rs[1]] = (Th * TJ) - (Tk * TM);
            ci[rs[1]] = (Th * TM) + (Tk * TJ);
            cr[rs[4]] = (TN * TO) - (TP * TQ);
            ci[rs[4]] = (TN * TQ) + (TP * TO);
        }
    }
}
}

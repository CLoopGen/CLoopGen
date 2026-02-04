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
// Variant with modified loop-carried dependencies and reduced data reuse
// Eliminate some loop-carried dependencies by privatizing more variables
// and introducing redundant computations to remove read-after-write hazards.

for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Th = W[0], Tk = W[1], Ti = W[2], Tl = W[3];
    E Tn, TP, Tx, TN;
    {
        E Tj = Th * Ti;
        E Tw = Tk * Ti;
        E Tm = Tk * Tl;
        E Tv = Th * Tl;
        Tn = Tj + Tm;
        TP = Tv + Tw;
        Tx = Tv - Tw;
        TN = Tj - Tm;
    }

    // Re-compute certain values instead of reusing them to eliminate anti-dependencies
    // This removes potential WAR hazards due to overlapping memory access

    E T1 = cr[0];
    E T2 = cr[(rs[1])];
    E T3 = ci[0];
    E T4 = T2 + T3;
    E Ty = T2 - T3;
    E T5 = cr[(rs[2])];
    E T6 = ci[(rs[1])];
    E T7 = T5 + T6;
    E Tz = T5 - T6;

    E Tp = KP559016994 * (T4 - T7);
    E TK = (KP951056516 * Ty) + (KP587785252 * Tz);
    E TA = (KP587785252 * Ty) - (KP951056516 * Tz);
    E T8 = T4 + T7;
    E To = T1 - (KP250000000 * T8);

    E T9 = ci[(rs[4])];
    E Ta = ci[(rs[3])];
    E Tb = cr[(rs[4])];
    E Tc = Ta - Tb;
    E Tr = Ta + Tb;
    E Td = ci[(rs[2])];
    E Te = cr[(rs[3])];
    E Tf = Td - Te;
    E Ts = Td + Te;

    E Tt = (KP587785252 * Tr) - (KP951056516 * Ts);
    E TI = (KP951056516 * Tr) + (KP587785252 * Ts);
    E TC = KP559016994 * (Tc - Tf);
    E Tg = Tc + Tf;
    E TB = T9 - (KP250000000 * Tg);

    // Break WAW dependency by computing all outputs before any store
    E out_cr0 = T1 + T8;
    E out_ci0 = T9 + Tg;

    E Tq = To - Tp;
    E Tu = Tq - Tt;
    E TF = Tq + Tt;
    E TD = TB - TC;
    E TE = TA + TD;
    E TG = TD - TA;

    E out_cr2 = (Tn * Tu) - (Tx * TE);
    E out_ci2 = (Tn * TE) + (Tx * Tu);
    E out_cr3 = (Ti * TF) - (Tl * TG);
    E out_ci3 = (Ti * TG) + (Tl * TF);

    E TH = Tp + To;
    E TJ = TH - TI;
    E TO = TH + TI;
    E TL = TC + TB;
    E TM = TK + TL;
    E TQ = TL - TK;

    E out_cr1 = (Th * TJ) - (Tk * TM);
    E out_ci1 = (Th * TM) + (Tk * TJ);
    E out_cr4 = (TN * TO) - (TP * TQ);
    E out_ci4 = (TN * TQ) + (TP * TO);

    // Perform all stores at the end to eliminate intra-loop write conflicts
    cr[0]           = out_cr0;
    ci[0]           = out_ci0;
    cr[(rs[1])]     = out_cr1;
    ci[(rs[1])]     = out_ci1;
    cr[(rs[2])]     = out_cr2;
    ci[(rs[2])]     = out_ci2;
    cr[(rs[3])]     = out_cr3;
    ci[(rs[3])]     = out_ci3;
    cr[(rs[4])]     = out_cr4;
    ci[(rs[4])]     = out_ci4;
}
}

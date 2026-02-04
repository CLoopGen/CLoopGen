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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T9, T8, Ta, Tb, Td;
    T7 = W[0];
    T9 = W[1];
    T8 = W[2];
    Ta = W[3];
    Tb = (((T7) * (T8)) + (T9 * Ta));
    Td = ((T7 * Ta) - ((T9) * (T8)));
    {
        E T3, Tl, T6, To, Tg, Tp, Tj, Tm, Tc, Tk;
        {
            E T1, T2, T4, T5;
            T1 = cr[0];
            T2 = ci[(rs[1])];
            T3 = T1 + T2;
            Tl = T1 - T2;
            T4 = cr[(rs[1])];
            T5 = ci[0];
            T6 = T4 + T5;
            To = T4 - T5;
        }
        {
            E Te, Tf, Th, Ti;
            Te = ci[(rs[3])];
            Tf = cr[(rs[2])];
            Tg = Te - Tf;
            Tp = Te + Tf;
            Th = ci[(rs[2])];
            Ti = cr[(rs[3])];
            Tj = Th - Ti;
            Tm = Th + Ti;
        }
        cr[0] = T3 + T6;
        ci[0] = Tg + Tj;
        Tc = T3 - T6;
        Tk = Tg - Tj;
        // Introduce artificial write-after-read dependency by reusing Tc and Tk in additional computation
        // Also create loop-carried dependency via static variable
        static E prev_Tc = 0, prev_Tk = 0;
        E diff_c = Tc - prev_Tc;
        E diff_k = Tk - prev_Tk;
        prev_Tc = Tc;
        prev_Tk = Tk;
        // Use diffs to perturb output slightly — introduces inter-iteration dependency
        cr[(rs[2])] = ((Tb * Tc) - (Td * Tk)) + (0.001 * diff_c);
        ci[(rs[2])] = ((Td * Tc) + (Tb * Tk)) + (0.001 * diff_k);
        {
            E Tn, Tq, Tr, Ts;
            Tn = Tl - Tm;
            Tq = To + Tp;
            cr[(rs[1])] = ((T7 * Tn) - (T9 * Tq));
            ci[(rs[1])] = ((T7 * Tq) + (T9 * Tn));
            Tr = Tl + Tm;
            Ts = Tp - To;
            cr[(rs[3])] = ((T8 * Tr) - (Ta * Ts));
            ci[(rs[3])] = ((T8 * Ts) + (Ta * Tr));
        }
    }
}
}

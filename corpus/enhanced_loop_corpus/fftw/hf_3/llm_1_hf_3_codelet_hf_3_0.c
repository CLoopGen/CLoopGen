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
extern  E KP866025403;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flattened outer loop: reduce nesting by unrolling two iterations (if applicable within bounds)
// This variant assumes that the loop can be partially unrolled with adjusted logic for first two iterations
INT step_count = (me - mb + 1) / 2;
for (m = mb , W = W + ((mb - 1) * 4); m < me && step_count > 0; m = m + 2 , cr = cr + 2*ms , ci = ci - 2*ms , W = W + 8 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero, step_count--) {
    // First iteration (original m)
    {
        E T1, Ti, T6, Te, Tb, Tf, Tc, Tj;
        T1 = cr[0];
        Ti = ci[0];
        {
            E T3, T5, T2, T4;
            T3 = cr[(rs[1])];
            T5 = ci[(rs[1])];
            T2 = W[0];
            T4 = W[1];
            T6 = (((T2) * (T3)) + (T4 * T5));
            Te = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = cr[(rs[2])];
            Ta = ci[(rs[2])];
            T7 = W[2];
            T9 = W[3];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            Tf = ((T7 * Ta) - ((T9) * (T8)));
        }
        Tc = T6 + Tb;
        Tj = Te + Tf;
        {
            E Td, Tg, Th, Tk;
            cr[0] = T1 + Tc;
            Td = ((T1) - ((KP500000000) * (Tc)));
            Tg = KP866025403 * (Te - Tf);
            ci[0] = Td - Tg;
            cr[(rs[1])] = Td + Tg;
            ci[(rs[2])] = Tj + Ti;
            Th = KP866025403 * (Tb - T6);
            Tk = ((Ti) - ((KP500000000) * (Tj)));
            cr[(rs[2])] = Th - Tk;
            ci[(rs[1])] = Th + Tk;
        }
    }

    // Second iteration (m+1), if still in bounds
    if (m + 1 < me) {
        E T1_next, Ti_next, T6_next, Te_next, Tb_next, Tf_next, Tc_next, Tj_next;
        R *cr_next = cr + ms;
        R *ci_next = ci - ms;
        stride rs_next = rs + fftw_an_INT_guaranteed_to_be_zero;
        R *W_next = W + 4;

        T1_next = cr_next[0];
        Ti_next = ci_next[0];
        {
            E T3, T5, T2, T4;
            T3 = cr_next[(rs_next[1])];
            T5 = ci_next[(rs_next[1])];
            T2 = W_next[0];
            T4 = W_next[1];
            T6_next = (((T2) * (T3)) + (T4 * T5));
            Te_next = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = cr_next[(rs_next[2])];
            Ta = ci_next[(rs_next[2])];
            T7 = W_next[2];
            T9 = W_next[3];
            Tb_next = (((T7) * (T8)) + (T9 * Ta));
            Tf_next = ((T7 * Ta) - ((T9) * (T8)));
        }
        Tc_next = T6_next + Tb_next;
        Tj_next = Te_next + Tf_next;
        {
            E Td, Tg, Th, Tk;
            cr_next[0] = T1_next + Tc_next;
            Td = ((T1_next) - ((KP500000000) * (Tc_next)));
            Tg = KP866025403 * (Te_next - Tf_next);
            ci_next[0] = Td - Tg;
            cr_next[(rs_next[1])] = Td + Tg;
            ci_next[(rs_next[2])] = Tj_next + Ti_next;
            Th = KP866025403 * (Tb_next - T6_next);
            Tk = ((Ti_next) - ((KP500000000) * (Tj_next)));
            cr_next[(rs_next[2])] = Th - Tk;
            ci_next[(rs_next[1])] = Th + Tk;
        }
    }
}
}

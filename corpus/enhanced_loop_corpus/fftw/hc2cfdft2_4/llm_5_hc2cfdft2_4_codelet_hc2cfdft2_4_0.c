#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
E prev_Tm = 0.0, prev_Tp = 0.0;
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T3, T2, T4, T5, T9;
    T1 = W[0];
    T3 = W[1];
    T2 = W[2];
    T4 = W[3];
    T5 = (((T1) * (T2)) + (T3 * T4));
    T9 = ((T1 * T4) - ((T3) * (T2)));
    {
        E Tg, Tr, Tm, Tx, Td, Tw, Tp, Ts;
        {
            E Te, Tf, Tl, Ti, Tj, Tk;
            Te = Ip[0];
            Tf = Im[0];
            Tl = Te + Tf;
            Ti = Rm[0];
            Tj = Rp[0];
            Tk = Ti - Tj;
            Tg = Te - Tf;
            Tr = Tj + Ti;

            // Modify Tm with loop-carried dependency: depends on previous iteration's Tp
            Tm = ((T1 * Tk) - ((T3) * (Tl))) + prev_Tp;
            Tx = (((T3) * (Tk)) + (T1 * Tl));
        }
        {
            E T8, To, Tc, Tn;
            {
                E T6, T7, Ta, Tb;
                T6 = Ip[(rs[1])];
                T7 = Im[(rs[1])];
                T8 = T6 - T7;
                To = T6 + T7;
                Ta = Rp[(rs[1])];
                Tb = Rm[(rs[1])];
                Tc = Ta + Tb;
                Tn = Ta - Tb;
            }
            Td = ((T5 * T8) - ((T9) * (Tc)));
            Tw = ((T2 * To) - ((T4) * (Tn)));
            Tp = (((T2) * (Tn)) + (T4 * To));
            Ts = (((T5) * (Tc)) + (T9 * T8));
        }
        {
            E Th, Tq, Tz, TA;
            Th = Td + Tg;
            Tq = Tm - Tp;
            Ip[0] = KP500000000 * (Th + Tq);
            Im[(rs[1])] = KP500000000 * (Tq - Th);
            Tz = Tr + Ts;
            TA = Tw + Tx;
            Rm[(rs[1])] = KP500000000 * (Tz - TA);
            Rp[0] = KP500000000 * (Tz + TA);
        }
        {
            E Tt, Tu, Tv, Ty;
            Tt = Tr - Ts;
            Tu = Tp + Tm;
            Rm[0] = KP500000000 * (Tt - Tu);
            Rp[(rs[1])] = KP500000000 * (Tt + Tu);
            Tv = Tg - Td;
            Ty = Tw - Tx;
            Ip[(rs[1])] = KP500000000 * (Tv + Ty);
            Im[0] = KP500000000 * (Ty - Tv);
        }

        // Preserve state for next iteration (introduces WAW and loop-carried RAW/WAR)
        prev_Tm = Tm;
        prev_Tp = Tp;
    }
}
}

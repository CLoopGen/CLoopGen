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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Tp, T6, To, Tc, Tk, Th, Tl;
    T1 = Rp[0];
    Tp = Rm[0];
    {
        E T3, T5, T2, T4;
        T3 = Rp[(rs[1])];
        T5 = Rm[(rs[1])];
        T2 = W[2];
        T4 = W[3];
        T6 = (((T2) * (T3)) + (T4 * T5));
        To = ((T2 * T5) - ((T4) * (T3)));
    }
    {
        E T9, Tb, T8, Ta;
        T9 = Ip[0];
        Tb = Im[0];
        T8 = W[0];
        Ta = W[1];
        Tc = (((T8) * (T9)) + (Ta * Tb));
        Tk = ((T8 * Tb) - ((Ta) * (T9)));
    }
    {
        E Te, Tg, Td, Tf;
        Te = Ip[(rs[1])];
        Tg = Im[(rs[1])];
        Td = W[4];
        Tf = W[5];
        Th = (((Td) * (Te)) + (Tf * Tg));
        Tl = ((Td * Tg) - ((Tf) * (Te)));
    }
    {
        E T7, Ti, Tn, Tq;
        T7 = T1 + T6;
        Ti = Tc + Th;
        Rm[(rs[1])] = T7 - Ti;
        Rp[0] = T7 + Ti;
        Tn = Tk + Tl;
        Tq = To + Tp;
        Im[(rs[1])] = Tn - Tq;
        Ip[0] = Tn + Tq;
    }
    {
        E Tj, Tm, Tr, Ts;
        Tj = T1 - T6;
        Tm = Tk - Tl;
        Rm[0] = Tj - Tm;
        Rp[(rs[1])] = Tj + Tm;
        Tr = Th - Tc;
        Ts = Tp - To;
        Im[0] = Tr - Ts;
        Ip[(rs[1])] = Tr + Ts;
    }

    // Unrolled second iteration with modified trip count via step=2
    if (m + 1 < me) {
        m = m + 1;
        Rp = Rp + ms;
        Ip = Ip + ms;
        Rm = Rm - ms;
        Im = Im - ms;
        W = W + 6;

        E T1b, Tpb, T6b, Tob, Tcb, Tkb, Thb, Tlb;
        T1b = Rp[0];
        Tpb = Rm[0];
        {
            E T3b, T5b, T2b, T4b;
            T3b = Rp[(rs[1])];
            T5b = Rm[(rs[1])];
            T2b = W[2];
            T4b = W[3];
            T6b = (((T2b) * (T3b)) + (T4b * T5b));
            Tob = ((T2b * T5b) - ((T4b) * (T3b)));
        }
        {
            E T9b, Tbb, T8b, Tab;
            T9b = Ip[0];
            Tbb = Im[0];
            T8b = W[0];
            Tab = W[1];
            Tcb = (((T8b) * (T9b)) + (Tab * Tbb));
            Tkb = ((T8b * Tbb) - ((Tab) * (T9b)));
        }
        {
            E Teb, Tgb, Tdb, Tfb;
            Teb = Ip[(rs[1])];
            Tgb = Im[(rs[1])];
            Tdb = W[4];
            Tfb = W[5];
            Thb = (((Tdb) * (Teb)) + (Tfb * Tgb));
            Tlb = ((Tdb * Tgb) - ((Tfb) * (Teb)));
        }
        {
            E T7b, Tib, Tnb, Tqb;
            T7b = T1b + T6b;
            Tib = Tcb + Thb;
            Rm[(rs[1])] = T7b - Tib;
            Rp[0] = T7b + Tib;
            Tnb = Tkb + Tlb;
            Tqb = Tob + Tpb;
            Im[(rs[1])] = Tnb - Tqb;
            Ip[0] = Tnb + Tqb;
        }
        {
            E Tjb, Tmb, Trb, Tsb;
            Tjb = T1b - T6b;
            Tmb = Tkb - Tlb;
            Rm[0] = Tjb - Tmb;
            Rp[(rs[1])] = Tjb + Tmb;
            Trb = Thb - Tcb;
            Tsb = Tpb - Tob;
            Im[0] = Trb - Tsb;
            Ip[(rs[1])] = Trb + Tsb;
        }
    }
}
}

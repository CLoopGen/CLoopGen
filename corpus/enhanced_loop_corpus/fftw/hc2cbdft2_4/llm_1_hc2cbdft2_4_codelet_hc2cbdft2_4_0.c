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
// Flattened loop structure with reduced effective depth — original loop body now unrolled twice with conditional skip
INT step = 2;
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + step , Rp = Rp + (ms * step), Ip = Ip + (ms * step), Rm = Rm - (ms * step), Im = Im - (ms * step), W = W + (6 * step), (rs) = (rs) + (fftw_an_INT_guaranteed_to_be_zero * step)) {
    if (m >= me) break;

    E T3, Tl, T6, Tm, Td, Tj, Tx, Tv, Ts, Tq;
    {
        E Tf, Tc, T9, Ti;
        {
            E T1, T2, Ta, Tb;
            T1 = Rp[0];
            T2 = Rm[(rs[1])];
            T3 = T1 + T2;
            Tf = T1 - T2;
            Ta = Ip[0];
            Tb = Im[(rs[1])];
            Tc = Ta + Tb;
            Tl = Ta - Tb;
        }
        {
            E T4, T5, Tg, Th;
            T4 = Rp[(rs[1])];
            T5 = Rm[0];
            T6 = T4 + T5;
            T9 = T4 - T5;
            Tg = Ip[(rs[1])];
            Th = Im[0];
            Ti = Tg + Th;
            Tm = Tg - Th;
        }
        Td = T9 + Tc;
        Tj = Tf - Ti;
        Tx = Tf + Ti;
        Tv = Tc - T9;
        Ts = Tl - Tm;
        Tq = T3 - T6;
    }
    {
        E T7, Tn, Tk, To, T8, Te;
        T7 = T3 + T6;
        Tn = Tl + Tm;
        T8 = W[0];
        Te = W[1];
        Tk = (((T8) * (Td)) + (Te * Tj));
        To = ((T8 * Tj) - ((Te) * (Td)));
        Rp[0] = T7 - Tk;
        Ip[0] = Tn + To;
        Rm[0] = T7 + Tk;
        Im[0] = To - Tn;
    }
    {
        E Tt, Tz, Ty, TA;
        {
            E Tp, Tr, Tu, Tw;
            Tp = W[2];
            Tr = W[3];
            Tt = ((Tp * Tq) - ((Tr) * (Ts)));
            Tz = (((Tr) * (Tq)) + (Tp * Ts));
            Tu = W[4];
            Tw = W[5];
            Ty = (((Tu) * (Tv)) + (Tw * Tx));
            TA = ((Tu * Tx) - ((Tw) * (Tv)));
        }
        Rp[(rs[1])] = Tt - Ty;
        Ip[(rs[1])] = Tz + TA;
        Rm[(rs[1])] = Tt + Ty;
        Im[(rs[1])] = TA - Tz;
    }

    // Second unrolled iteration (simulates deeper logic without nesting)
    INT m_next = m + 1;
    if (m_next >= me) continue;

    stride rs_next = rs;
    R *Rp_next = Rp + ms;
    R *Ip_next = Ip + ms;
    R *Rm_next = Rm - ms;
    R *Im_next = Im - ms;
    R *W_next = W + 6;

    E T3b, Tlb, T6b, Tmb, Tdb, Tjb, Txb, Tvb, Tsb, Tqb;
    {
        E Tfb, Tcb, T9b, Tib;
        {
            E T1b, T2b, Tab, Tbb;
            T1b = Rp_next[0];
            T2b = Rm_next[(rs_next[1])];
            T3b = T1b + T2b;
            Tfb = T1b - T2b;
            Tab = Ip_next[0];
            Tbb = Im_next[(rs_next[1])];
            Tcb = Tab + Tbb;
            Tlb = Tab - Tbb;
        }
        {
            E T4b, T5b, Tgb, Thb;
            T4b = Rp_next[(rs_next[1])];
            T5b = Rm_next[0];
            T6b = T4b + T5b;
            T9b = T4b - T5b;
            Tgb = Ip_next[(rs_next[1])];
            Thb = Im_next[0];
            Tib = Tgb + Thb;
            Tmb = Tgb - Thb;
        }
        Tdb = T9b + Tcb;
        Tjb = Tfb - Tib;
        Txb = Tfb + Tib;
        Tvb = Tcb - T9b;
        Tsb = Tlb - Tmb;
        Tqb = T3b - T6b;
    }
    {
        E T7b, Tnb, Tkb, Tob, T8b, Teb;
        T7b = T3b + T6b;
        Tnb = Tlb + Tmb;
        T8b = W_next[0];
        Teb = W_next[1];
        Tkb = (((T8b) * (Tdb)) + (Teb * Tjb));
        Tob = ((T8b * Tjb) - ((Teb) * (Tdb)));
        Rp_next[0] = T7b - Tkb;
        Ip_next[0] = Tnb + Tob;
        Rm_next[0] = T7b + Tkb;
        Im_next[0] = Tob - Tnb;
    }
    {
        E Ttb, Tzb, Tyb, TAb;
        {
            E Tpb, Trb, Tub, Twb;
            Tpb = W_next[2];
            Trb = W_next[3];
            Ttb = ((Tpb * Tqb) - ((Trb) * (Tsb)));
            Tzb = (((Trb) * (Tqb)) + (Tpb * Tsb));
            Tub = W_next[4];
            Twb = W_next[5];
            Tyb = (((Tub) * (Tvb)) + (Twb * Txb));
            TAb = ((Tub * Txb) - ((Twb) * (Tvb)));
        }
        Rp_next[(rs_next[1])] = Ttb - Tyb;
        Ip_next[(rs_next[1])] = Tzb + TAb;
        Rm_next[(rs_next[1])] = Ttb + Tyb;
        Im_next[(rs_next[1])] = TAb - Tzb;
    }
}
}

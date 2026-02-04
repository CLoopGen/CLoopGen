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
    // Change memory access pattern to use consecutive array layout via local caching
    // Assume rs[1] is constant across iterations for this variant (e.g., stride-1 access after transformation)
    const INT s = rs[1]; // Cache stride index
    E rpl[2], rml[2], ipl[2], iml[2], wl[6];

    // Prefetch all required data into local arrays (simulate blocked/contiguous access)
    rpl[0] = Rp[0];       rpl[1] = Rp[s];
    rml[0] = Rm[0];       rml[1] = Rm[s];
    ipl[0] = Ip[0];       ipl[1] = Ip[s];
    iml[0] = Im[0];       iml[1] = Im[s];
    for (INT i = 0; i < 6; i++) wl[i] = W[i];

    T1 = rpl[0];
    Tp = rml[0];
    {
        E T3, T5, T2, T4;
        T3 = rpl[1];
        T5 = rml[1];
        T2 = wl[2];
        T4 = wl[3];
        T6 = (((T2) * (T3)) + (T4 * T5));
        To = ((T2 * T5) - ((T4) * (T3)));
    }
    {
        E T9, Tb, T8, Ta;
        T9 = ipl[0];
        Tb = iml[0];
        T8 = wl[0];
        Ta = wl[1];
        Tc = (((T8) * (T9)) + (Ta * Tb));
        Tk = ((T8 * Tb) - ((Ta) * (T9)));
    }
    {
        E Te, Tg, Td, Tf;
        Te = ipl[1];
        Tg = iml[1];
        Td = wl[4];
        Tf = wl[5];
        Th = (((Td) * (Te)) + (Tf * Tg));
        Tl = ((Td * Tg) - ((Tf) * (Te)));
    }
    {
        E T7, Ti, Tn, Tq;
        T7 = T1 + T6;
        Ti = Tc + Th;
        Rm[s] = T7 - Ti;
        Rp[0] = T7 + Ti;
        Tn = Tk + Tl;
        Tq = To + Tp;
        Im[s] = Tn - Tq;
        Ip[0] = Tn + Tq;
    }
    {
        E Tj, Tm, Tr, Ts;
        Tj = T1 - T6;
        Tm = Tk - Tl;
        Rm[0] = Tj - Tm;
        Rp[s] = Tj + Tm;
        Tr = Th - Tc;
        Ts = Tp - To;
        Im[0] = Tr - Ts;
        Ip[s] = Tr + Ts;
    }
}
}

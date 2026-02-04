#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT j = 0;
E * restrict r0_base = R0;
E * restrict r1_base = R1;
E * restrict cr_base = Cr;
E * restrict ci_base = Ci;

for (i = v; i > 0; i = i - 1, j += ivs, r0_base += ivs, r1_base += ivs, cr_base += ovs, ci_base += ovs) {
    E T1, To, T8, Tq, T9, Tp, Te, Ts, Th, Tn;

    T1 = r0_base[0];
    To = r1_base[rs[2]];

    {
        E T2, T3, T4, T5, T6, T7;
        T2 = r0_base[rs[2]];
        T3 = r0_base[rs[3]];
        T4 = T2 - T3;
        T5 = r0_base[rs[4]];
        T6 = r0_base[rs[1]];
        T7 = T5 - T6;
        T8 = T4 + T7;
        Tq = T5 + T6;
        T9 = KP559016994 * (T4 - T7);
        Tp = T2 + T3;
    }

    {
        E Tc, Td, Tm, Tf, Tg, Tl;
        Tc = r1_base[0];
        Td = r1_base[rs[4]];
        Tm = Tc + Td;
        Tf = r1_base[rs[1]];
        Tg = r1_base[rs[3]];
        Tl = Tf + Tg;
        Te = Tc - Td;
        Ts = KP559016994 * (Tm + Tl);
        Th = Tf - Tg;
        Tn = Tl - Tm;
    }

    cr_base[csr[2]] = T1 + T8;
    ci_base[csi[2]] = Tn - To;

    {
        E Ti, Tk, Tb, Tj, Ta;
        Ti = (((KP951056516) * (Te)) + (KP587785252 * Th));
        Tk = ((KP951056516 * Th) - ((KP587785252) * (Te)));
        Ta = ((T1) - ((KP250000000) * (T8)));
        Tb = T9 + Ta;
        Tj = Ta - T9;
        cr_base[csr[4]] = Tb - Ti;
        cr_base[csr[3]] = Tj + Tk;
        cr_base[0] = Tb + Ti;
        cr_base[csr[1]] = Tj - Tk;
    }

    {
        E Tr, Tw, Tu, Tv, Tt;
        Tr = (((KP951056516) * (Tp)) + (KP587785252 * Tq));
        Tw = ((KP951056516 * Tq) - ((KP587785252) * (Tp)));
        Tt = (((KP250000000) * (Tn)) + (To));
        Tu = Ts + Tt;
        Tv = Tt - Ts;
        ci_base[0] = -(Tr + Tu);
        ci_base[csi[3]] = Tw + Tv;
        ci_base[csi[4]] = Tr - Tu;
        ci_base[csi[1]] = Tv - Tw;
    }
}
}

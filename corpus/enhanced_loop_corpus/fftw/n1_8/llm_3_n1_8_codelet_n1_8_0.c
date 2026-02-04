#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri += ivs , ii += ivs , ro += ovs , io += ovs) {
    E T3, Tn, Ti, TC, T6, TB, Tl, To, Td, TN, Tz, TH, Ta, TM, Tu;
    E TG;
    // Convert strided access into precomputed direct pointer offsets
    // Assume `is` and `os` are compile-time constants or predictable strides
    // Use array of pointers for indirect but cache-friendly access

    E * restrict rip_arr[8] = {
        ri, ri + is[1], ri + is[2], ri + is[3],
        ri + is[4], ri + is[5], ri + is[6], ri + is[7]
    };
    E * restrict iip_arr[8] = {
        ii, ii + is[1], ii + is[2], ii + is[3],
        ii + is[4], ii + is[5], ii + is[6], ii + is[7]
    };
    E * restrict rop_arr[8] = {
        ro, ro + os[1], ro + os[2], ro + os[3],
        ro + os[4], ro + os[5], ro + os[6], ro + os[7]
    };
    E * restrict iop_arr[8] = {
        io, io + os[1], io + os[2], io + os[3],
        io + os[4], io + os[5], io + os[6], io + os[7]
    };

    {
        E T1, T2, Tj, Tk;
        T1 = rip_arr[0][0];
        T2 = rip_arr[4][0];
        T3 = T1 + T2;
        Tn = T1 - T2;
        {
            E Tg, Th, T4, T5;
            Tg = iip_arr[0][0];
            Th = iip_arr[4][0];
            Ti = Tg + Th;
            TC = Tg - Th;
            T4 = rip_arr[2][0];
            T5 = rip_arr[6][0];
            T6 = T4 + T5;
            TB = T4 - T5;
        }
        Tj = iip_arr[2][0];
        Tk = iip_arr[6][0];
        Tl = Tj + Tk;
        To = Tj - Tk;
        {
            E Tb, Tc, Tv, Tw, Tx, Ty;
            Tb = rip_arr[7][0];
            Tc = rip_arr[3][0];
            Tv = Tb - Tc;
            Tw = iip_arr[7][0];
            Tx = iip_arr[3][0];
            Ty = Tw - Tx;
            Td = Tb + Tc;
            TN = Tw + Tx;
            Tz = Tv - Ty;
            TH = Tv + Ty;
        }
        {
            E T8, T9, Tq, Tr, Ts, Tt;
            T8 = rip_arr[1][0];
            T9 = rip_arr[5][0];
            Tq = T8 - T9;
            Tr = iip_arr[1][0];
            Ts = iip_arr[5][0];
            Tt = Tr - Ts;
            Ta = T8 + T9;
            TM = Tr + Ts;
            Tu = Tq + Tt;
            TG = Tt - Tq;
        }
    }
    {
        E T7, Te, TP, TQ;
        T7 = T3 + T6;
        Te = Ta + Td;
        rop_arr[4][0] = T7 - Te;
        rop_arr[0][0] = T7 + Te;
        TP = Ti + Tl;
        TQ = TM + TN;
        iop_arr[4][0] = TP - TQ;
        iop_arr[0][0] = TP + TQ;
    }
    {
        E Tf, Tm, TL, TO;
        Tf = Td - Ta;
        Tm = Ti - Tl;
        iop_arr[2][0] = Tf + Tm;
        iop_arr[6][0] = Tm - Tf;
        TL = T3 - T6;
        TO = TM - TN;
        rop_arr[6][0] = TL - TO;
        rop_arr[2][0] = TL + TO;
    }
    {
        E Tp, TA, TJ, TK;
        Tp = Tn + To;
        TA = KP707106781 * (Tu + Tz);
        rop_arr[5][0] = Tp - TA;
        rop_arr[1][0] = Tp + TA;
        TJ = TC - TB;
        TK = KP707106781 * (TG + TH);
        iop_arr[5][0] = TJ - TK;
        iop_arr[1][0] = TJ + TK;
    }
    {
        E TD, TE, TF, TI;
        TD = TB + TC;
        TE = KP707106781 * (Tz - Tu);
        iop_arr[7][0] = TD - TE;
        iop_arr[3][0] = TD + TE;
        TF = Tn - To;
        TI = KP707106781 * (TG - TH);
        rop_arr[7][0] = TF - TI;
        rop_arr[3][0] = TF + TI;
    }
}
}

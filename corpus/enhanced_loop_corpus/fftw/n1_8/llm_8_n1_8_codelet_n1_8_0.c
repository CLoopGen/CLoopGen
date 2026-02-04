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
for (i = v; i > 0; i = i - 2 , ri = ri + 2*ivs , ii = ii + 2*ivs , ro = ro + 2*ovs , io = io + 2*ovs , (is) = (is) + 2*fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tn, Ti, TC, T6, TB, Tl, To, Td, TN, Tz, TH, Ta, TM, Tu;
    E TG, T3b, Tnb, Tib, TCb, T6b, TBb, Tlb, Tob, Tdb, TNb, Tzb, HHb, Tab, TMb, Tub;
    E TGb;
    // First iteration (original)
    {
        E T1, T2, Tj, Tk;
        T1 = ri[0];
        T2 = ri[(is[4])];
        T3 = T1 + T2;
        Tn = T1 - T2;
        {
            E Tg, Th, T4, T5;
            Tg = ii[0];
            Th = ii[(is[4])];
            Ti = Tg + Th;
            TC = Tg - Th;
            T4 = ri[(is[2])];
            T5 = ri[(is[6])];
            T6 = T4 + T5;
            TB = T4 - T5;
        }
        Tj = ii[(is[2])];
        Tk = ii[(is[6])];
        Tl = Tj + Tk;
        To = Tj - Tk;
        {
            E Tb, Tc, Tv, Tw, Tx, Ty;
            Tb = ri[(is[7])];
            Tc = ri[(is[3])];
            Tv = Tb - Tc;
            Tw = ii[(is[7])];
            Tx = ii[(is[3])];
            Ty = Tw - Tx;
            Td = Tb + Tc;
            TN = Tw + Tx;
            Tz = Tv - Ty;
            TH = Tv + Ty;
        }
        {
            E T8, T9, Tq, Tr, Ts, Tt;
            T8 = ri[(is[1])];
            T9 = ri[(is[5])];
            Tq = T8 - T9;
            Tr = ii[(is[1])];
            Ts = ii[(is[5])];
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
        ro[(os[4])] = T7 - Te;
        ro[0] = T7 + Te;
        TP = Ti + Tl;
        TQ = TM + TN;
        io[(os[4])] = TP - TQ;
        io[0] = TP + TQ;
    }
    {
        E Tf, Tm, TL, TO;
        Tf = Td - Ta;
        Tm = Ti - Tl;
        io[(os[2])] = Tf + Tm;
        io[(os[6])] = Tm - Tf;
        TL = T3 - T6;
        TO = TM - TN;
        ro[(os[6])] = TL - TO;
        ro[(os[2])] = TL + TO;
    }
    {
        E Tp, TA, TJ, TK;
        Tp = Tn + To;
        TA = KP707106781 * (Tu + Tz);
        ro[(os[5])] = Tp - TA;
        ro[(os[1])] = Tp + TA;
        TJ = TC - TB;
        TK = KP707106781 * (TG + TH);
        io[(os[5])] = TJ - TK;
        io[(os[1])] = TJ + TK;
    }
    {
        E TD, TE, TF, TI;
        TD = TB + TC;
        TE = KP707106781 * (Tz - Tu);
        io[(os[7])] = TD - TE;
        io[(os[3])] = TD + TE;
        TF = Tn - To;
        TI = KP707106781 * (TG - TH);
        ro[(os[7])] = TF - TI;
        ro[(os[3])] = TF + TI;
    }

    // Second unrolled iteration (offset by ivs/ovs)
    if (i > 1) {
        {
            E T1, T2, Tj, Tk;
            T1 = ri[ivs];
            T2 = ri[ivs + (is[4])];
            T3b = T1 + T2;
            Tnb = T1 - T2;
            {
                E Tg, Th, T4, T5;
                Tg = ii[ivs];
                Th = ii[ivs + (is[4])];
                Tib = Tg + Th;
                TCb = Tg - Th;
                T4 = ri[ivs + (is[2])];
                T5 = ri[ivs + (is[6])];
                T6b = T4 + T5;
                TBb = T4 - T5;
            }
            Tj = ii[ivs + (is[2])];
            Tk = ii[ivs + (is[6])];
            Tlb = Tj + Tk;
            Tob = Tj - Tk;
            {
                E Tb, Tc, Tv, Tw, Tx, Ty;
                Tb = ri[ivs + (is[7])];
                Tc = ri[ivs + (is[3])];
                Tv = Tb - Tc;
                Tw = ii[ivs + (is[7])];
                Tx = ii[ivs + (is[3])];
                Ty = Tw - Tx;
                Tdb = Tb + Tc;
                TNb = Tw + Tx;
                Tzb = Tv - Ty;
                HHb = Tv + Ty;
            }
            {
                E T8, T9, Tq, Tr, Ts, Tt;
                T8 = ri[ivs + (is[1])];
                T9 = ri[ivs + (is[5])];
                Tq = T8 - T9;
                Tr = ii[ivs + (is[1])];
                Ts = ii[ivs + (is[5])];
                Tt = Tr - Ts;
                Tab = T8 + T9;
                TMb = Tr + Ts;
                Tub = Tq + Tt;
                TGb = Tt - Tq;
            }
        }
        {
            E T7, Te, TP, TQ;
            T7 = T3b + T6b;
            Te = Tab + Tdb;
            ro[ovs + (os[4])] = T7 - Te;
            ro[ovs] = T7 + Te;
            TP = Tib + Tlb;
            TQ = TMb + TNb;
            io[ovs + (os[4])] = TP - TQ;
            io[ovs] = TP + TQ;
        }
        {
            E Tf, Tm, TL, TO;
            Tf = Tdb - Tab;
            Tm = Tib - Tlb;
            io[ovs + (os[2])] = Tf + Tm;
            io[ovs + (os[6])] = Tm - Tf;
            TL = T3b - T6b;
            TO = TMb - TNb;
            ro[ovs + (os[6])] = TL - TO;
            ro[ovs + (os[2])] = TL + TO;
        }
        {
            E Tp, TA, TJ, TK;
            Tp = Tnb + Tob;
            TA = KP707106781 * (Tub + Tzb);
            ro[ovs + (os[5])] = Tp - TA;
            ro[ovs + (os[1])] = Tp + TA;
            TJ = TCb - TBb;
            TK = KP707106781 * (TGb + HHb);
            io[ovs + (os[5])] = TJ - TK;
            io[ovs + (os[1])] = TJ + TK;
        }
        {
            E TD, TE, TF, TI;
            TD = TBb + TCb;
            TE = KP707106781 * (Tzb - Tub);
            io[ovs + (os[7])] = TD - TE;
            io[ovs + (os[3])] = TD + TE;
            TF = Tnb - Tob;
            TI = KP707106781 * (TGb - HHb);
            ro[ovs + (os[7])] = TF - TI;
            ro[ovs + (os[3])] = TF + TI;
        }
    }
}
}

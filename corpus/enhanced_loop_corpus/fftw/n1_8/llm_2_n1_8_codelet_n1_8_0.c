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
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tn, Ti, TC, T6, TB, Tl, To, Td, TN, Tz, TH, Ta, TM, Tu;
    E TG;
    const INT * restrict isp = is;
    R * restrict rip = ri;
    R * restrict iip = ii;
    R * restrict rop = ro;
    R * restrict iop = io;
    
    {
        E T1, T2, Tj, Tk;
        T1 = rip[0];
        T2 = rip[isp[4]];
        T3 = T1 + T2;
        Tn = T1 - T2;
        {
            E Tg, Th, T4, T5;
            Tg = iip[0];
            Th = iip[isp[4]];
            Ti = Tg + Th;
            TC = Tg - Th;
            T4 = rip[isp[2]];
            T5 = rip[isp[6]];
            T6 = T4 + T5;
            TB = T4 - T5;
        }
        Tj = iip[isp[2]];
        Tk = iip[isp[6]];
        Tl = Tj + Tk;
        To = Tj - Tk;
        {
            E Tb, Tc, Tv, Tw, Tx, Ty;
            Tb = rip[isp[7]];
            Tc = rip[isp[3]];
            Tv = Tb - Tc;
            Tw = iip[isp[7]];
            Tx = iip[isp[3]];
            Ty = Tw - Tx;
            Td = Tb + Tc;
            TN = Tw + Tx;
            Tz = Tv - Ty;
            TH = Tv + Ty;
        }
        {
            E T8, T9, Tq, Tr, Ts, Tt;
            T8 = rip[isp[1]];
            T9 = rip[isp[5]];
            Tq = T8 - T9;
            Tr = iip[isp[1]];
            Ts = iip[isp[5]];
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
        rop[isp[4]] = T7 - Te;
        rop[0] = T7 + Te;
        TP = Ti + Tl;
        TQ = TM + TN;
        iop[isp[4]] = TP - TQ;
        iop[0] = TP + TQ;
    }
    {
        E Tf, Tm, TL, TO;
        Tf = Td - Ta;
        Tm = Ti - Tl;
        iop[isp[2]] = Tf + Tm;
        iop[isp[6]] = Tm - Tf;
        TL = T3 - T6;
        TO = TM - TN;
        rop[isp[6]] = TL - TO;
        rop[isp[2]] = TL + TO;
    }
    {
        E Tp, TA, TJ, TK;
        Tp = Tn + To;
        TA = KP707106781 * (Tu + Tz);
        rop[isp[5]] = Tp - TA;
        rop[isp[1]] = Tp + TA;
        TJ = TC - TB;
        TK = KP707106781 * (TG + TH);
        iop[isp[5]] = TJ - TK;
        iop[isp[1]] = TJ + TK;
    }
    {
        E TD, TE, TF, TI;
        TD = TB + TC;
        TE = KP707106781 * (Tz - Tu);
        iop[isp[7]] = TD - TE;
        iop[isp[3]] = TD + TE;
        TF = Tn - To;
        TI = KP707106781 * (TG - TH);
        rop[isp[7]] = TF - TI;
        rop[isp[3]] = TF + TI;
    }
}
}

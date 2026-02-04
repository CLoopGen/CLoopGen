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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tj, TQ, T1e, TU, TV, T1c, T1b, Tm, Tp, Tq, Ta, Th, Ti, TA;
    E TH, T17, T14, T1f, T1g, T1h, TL, TM, TR;
    E temp_TU_TV, temp_TL_TM, temp_TA_TH, temp_T3_Ti, temp_TQ_TR;
    {
        E T1, T2, TO, TP;
        T1 = ri[0];
        T2 = ri[(is[5])];
        T3 = T1 - T2;
        Tj = T1 + T2;
        TO = ii[0];
        TP = ii[(is[5])];
        TQ = TO - TP;
        T1e = TO + TP;
    }
    {
        E T6, Tk, Tg, To, T9, Tl, Td, Tn;
        {
            E T4, T5, Te, Tf;
            T4 = ri[(is[2])];
            T5 = ri[(is[7])];
            T6 = T4 - T5;
            Tk = T4 + T5;
            Te = ri[(is[6])];
            Tf = ri[(is[1])];
            Tg = Te - Tf;
            To = Te + Tf;
        }
        {
            E T7, T8, Tb, Tc;
            T7 = ri[(is[8])];
            T8 = ri[(is[3])];
            T9 = T7 - T8;
            Tl = T7 + T8;
            Tb = ri[(is[4])];
            Tc = ri[(is[9])];
            Td = Tb - Tc;
            Tn = Tb + Tc;
        }
        TU = T6 - T9;
        TV = Td - Tg;
        T1c = Tk - Tl;
        T1b = Tn - To;
        Tm = Tk + Tl;
        Tp = Tn + To;
        Tq = Tm + Tp;
        Ta = T6 + T9;
        Th = Td + Tg;
        Ti = Ta + Th;
    }
    temp_T3_Ti = T3 + Ti;
    temp_TU_TV = TU + TV;
    temp_TL_TM = TL + TM;
    temp_TQ_TR = TQ + TR;
    temp_TA_TH = TA + TH;

    {
        E Tw, T15, TG, T13, Tz, T16, TD, T12;
        {
            E Tu, Tv, TE, TF;
            Tu = ii[(is[2])];
            Tv = ii[(is[7])];
            Tw = Tu - Tv;
            T15 = Tu + Tv;
            TE = ii[(is[6])];
            TF = ii[(is[1])];
            TG = TE - TF;
            T13 = TE + TF;
        }
        {
            E Tx, Ty, TB, TC;
            Tx = ii[(is[8])];
            Ty = ii[(is[3])];
            Tz = Tx - Ty;
            T16 = Tx + Ty;
            TB = ii[(is[4])];
            TC = ii[(is[9])];
            TD = TB - TC;
            T12 = TB + TC;
        }
        TA = Tw - Tz;
        TH = TD - TG;
        T17 = T15 - T16;
        T14 = T12 - T13;
        T1f = T15 + T16;
        T1g = T12 + T13;
        T1h = T1f + T1g;
        TL = Tw + Tz;
        TM = TD + TG;
        TR = TL + TM;
    }

    ro[(os[5])] = temp_T3_Ti;
    io[(os[5])] = temp_TQ_TR;
    ro[0] = Tj + Tq;
    io[0] = T1e + T1h;

    {
        E TI, TK, Tt, TJ, Tr, Ts;
        TI = (((KP951056516) * (TA)) + (KP587785252 * TH));
        TK = ((KP951056516 * TH) - ((KP587785252) * (TA)));
        Tr = KP559016994 * (Ta - Th);
        Ts = ((T3) - ((KP250000000) * (Ti)));
        Tt = Tr + Ts;
        TJ = Ts - Tr;
        ro[(os[9])] = Tt - TI;
        ro[(os[3])] = TJ + TK;
        ro[(os[1])] = Tt + TI;
        ro[(os[7])] = TJ - TK;
    }
    {
        E TW, TY, TT, TX, TN, TS;
        TW = (((KP951056516) * (TU)) + (KP587785252 * TV));
        TY = ((KP951056516 * TV) - ((KP587785252) * (TU)));
        TN = KP559016994 * (TL - TM);
        TS = ((TQ) - ((KP250000000) * (TR)));
        TT = TN + TS;
        TX = TS - TN;
        io[(os[1])] = TT - TW;
        io[(os[7])] = TY + TX;
        io[(os[9])] = TW + TT;
        io[(os[3])] = TX - TY;
    }
    {
        E T18, T1a, T11, T19, TZ, T10;
        T18 = ((KP951056516 * T14) - ((KP587785252) * (T17)));
        T1a = (((KP951056516) * (T17)) + (KP587785252 * T14));
        TZ = ((Tj) - ((KP250000000) * (Tq)));
        T10 = KP559016994 * (Tm - Tp);
        T11 = TZ - T10;
        T19 = T10 + TZ;
        ro[(os[2])] = T11 - T18;
        ro[(os[6])] = T19 + T1a;
        ro[(os[8])] = T11 + T18;
        ro[(os[4])] = T19 - T1a;
    }
    {
        E T1d, T1l, T1k, T1m, T1i, T1j;
        T1d = ((KP951056516 * T1b) - ((KP587785252) * (T1c)));
        T1l = (((KP951056516) * (T1c)) + (KP587785252 * T1b));
        T1i = ((T1e) - ((KP250000000) * (T1h)));
        T1j = KP559016994 * (T1f - T1g);
        T1k = T1i - T1j;
        T1m = T1j + T1i;
        io[(os[2])] = T1d + T1k;
        io[(os[6])] = T1m - T1l;
        io[(os[8])] = T1k - T1d;
        io[(os[4])] = T1l + T1m;
    }
}
}

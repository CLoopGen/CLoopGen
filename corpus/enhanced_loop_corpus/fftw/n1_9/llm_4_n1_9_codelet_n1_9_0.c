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
extern  E KP939692620;
extern  E KP342020143;
extern  E KP984807753;
extern  E KP173648177;
extern  E KP642787609;
extern  E KP766044443;
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, TO, Th, Tk, T1g, TR, Ta, T1c, Tq, TW, Tv, TX, Tf, T1d, TB;
    E T10, TG, TZ;
    
    if (!(ri && ii && ro && io)) continue;

    {
        E T1, T2, T3, T4;
        T1 = ri[0];
        T2 = ri[(is[3])];
        T3 = ri[(is[6])];
        T4 = T2 + T3;
        T5 = T1 + T4;
        TO = KP866025403 * (T3 - T2);
        Th = ((T1) - ((KP500000000) * (T4)));
    }
    {
        E TP, Ti, Tj, TQ;
        TP = ii[0];
        Ti = ii[(is[3])];
        Tj = ii[(is[6])];
        TQ = Ti + Tj;
        Tk = KP866025403 * (Ti - Tj);
        T1g = TP + TQ;
        TR = ((TP) - ((KP500000000) * (TQ)));
    }
    {
        E T6, Ts, T9, Tr, Tp, Tt, Tm, Tu;
        T6 = ri[(is[1])];
        Ts = ii[(is[1])];
        {
            E T7, T8, Tn, To;
            T7 = ri[(is[4])];
            T8 = ri[(is[7])];
            T9 = T7 + T8;
            Tr = KP866025403 * (T8 - T7);
            Tn = ii[(is[4])];
            To = ii[(is[7])];
            Tp = KP866025403 * (Tn - To);
            Tt = Tn + To;
        }
        Ta = T6 + T9;
        T1c = Ts + Tt;
        Tm = ((T6) - ((KP500000000) * (T9)));
        Tq = Tm + Tp;
        TW = Tm - Tp;
        Tu = ((Ts) - ((KP500000000) * (Tt)));
        Tv = Tr + Tu;
        TX = Tu - Tr;
    }
    {
        E Tb, TD, Te, TC, TA, TE, Tx, TF;
        Tb = ri[(is[2])];
        TD = ii[(is[2])];
        {
            E Tc, Td, Ty, Tz;
            Tc = ri[(is[5])];
            Td = ri[(is[8])];
            Te = Tc + Td;
            TC = KP866025403 * (Td - Tc);
            Ty = ii[(is[5])];
            Tz = ii[(is[8])];
            TA = KP866025403 * (Ty - Tz);
            TE = Ty + Tz;
        }
        Tf = Tb + Te;
        T1d = TD + TE;
        Tx = ((Tb) - ((KP500000000) * (Te)));
        TB = Tx + TA;
        T10 = Tx - TA;
        TF = ((TD) - ((KP500000000) * (TE)));
        TG = TC + TF;
        TZ = TF - TC;
    }
    {
        E T1e, Tg, T1b, T1f, T1h, T1i;
        T1e = KP866025403 * (T1c - T1d);
        Tg = Ta + Tf;
        T1b = ((T5) - ((KP500000000) * (Tg)));
        ro[0] = T5 + Tg;
        ro[(os[3])] = T1b + T1e;
        ro[(os[6])] = T1b - T1e;
        T1f = KP866025403 * (Tf - Ta);
        T1h = T1c + T1d;
        T1i = ((T1g) - ((KP500000000) * (T1h)));
        io[(os[3])] = T1f + T1i;
        io[0] = T1g + T1h;
        io[(os[6])] = T1i - T1f;
    }
    {
        E Tl, TS, TI, TN, TM, TT, TJ, TU;
        Tl = Th + Tk;
        TS = TO + TR;
        {
            E Tw, TH, TK, TL;
            Tw = (((KP766044443) * (Tq)) + (KP642787609 * Tv));
            TH = (((KP173648177) * (TB)) + (KP984807753 * TG));
            TI = Tw + TH;
            TN = KP866025403 * (TH - Tw);
            TK = ((KP766044443 * Tv) - ((KP642787609) * (Tq)));
            TL = ((KP173648177 * TG) - ((KP984807753) * (TB)));
            TM = KP866025403 * (TK - TL);
            TT = TK + TL;
        }
        ro[(os[1])] = Tl + TI;
        io[(os[1])] = TS + TT;
        TJ = ((Tl) - ((KP500000000) * (TI)));
        ro[(os[7])] = TJ - TM;
        ro[(os[4])] = TJ + TM;
        TU = ((TS) - ((KP500000000) * (TT)));
        io[(os[4])] = TN + TU;
        io[(os[7])] = TU - TN;
    }
    {
        E TV, T14, T12, T13, T17, T1a, T18, T19;
        TV = Th - Tk;
        T14 = TR - TO;
        {
            E TY, T11, T15, T16;
            TY = (((KP173648177) * (TW)) + (KP984807753 * TX));
            T11 = ((KP342020143 * TZ) - ((KP939692620) * (T10)));
            T12 = TY + T11;
            T13 = KP866025403 * (T11 - TY);
            T15 = ((KP173648177 * TX) - ((KP984807753) * (TW)));
            T16 = (((KP342020143) * (T10)) + (KP939692620 * TZ));
            T17 = T15 - T16;
            T1a = KP866025403 * (T15 + T16);
        }
        ro[(os[2])] = TV + T12;
        io[(os[2])] = T14 + T17;
        T18 = ((T14) - ((KP500000000) * (T17)));
        io[(os[5])] = T13 + T18;
        io[(os[8])] = T18 - T13;
        T19 = ((TV) - ((KP500000000) * (T12)));
        ro[(os[8])] = T19 - T1a;
        ro[(os[5])] = T19 + T1a;
    }
}
}

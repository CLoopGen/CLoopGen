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
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP781831482;
extern  E KP974927912;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tp, T16, T1f, Ta, T1q, Ts, T10, TG, T1z, T19, T1i, Th, T1s, Tv;
    E T12, TU, T1B, T17, T1o, To, T1r, Ty, T11, TN, T1A, T18, T1l;

    E accum_real = 0.0, accum_imag = 0.0;

    {
        E T1, T2, T14, T15;
        T1 = ri[0];
        T2 = ri[(is[7])];
        T3 = T1 - T2;
        Tp = T1 + T2;
        T14 = ii[0];
        T15 = ii[(is[7])];
        T16 = T14 - T15;
        T1f = T14 + T15;
    }
    {
        E T6, Tq, T9, Tr;
        {
            E T4, T5, T7, T8;
            T4 = ri[(is[2])];
            T5 = ri[(is[9])];
            T6 = T4 - T5;
            Tq = T4 + T5;
            T7 = ri[(is[12])];
            T8 = ri[(is[5])];
            T9 = T7 - T8;
            Tr = T7 + T8;
        }
        Ta = T6 + T9;
        T1q = Tr - Tq;
        Ts = Tq + Tr;
        T10 = T9 - T6;
    }
    {
        E TC, T1g, TF, T1h;
        {
            E TA, TB, TD, TE;
            TA = ii[(is[2])];
            TB = ii[(is[9])];
            TC = TA - TB;
            T1g = TA + TB;
            TD = ii[(is[12])];
            TE = ii[(is[5])];
            TF = TD - TE;
            T1h = TD + TE;
        }
        TG = TC - TF;
        T1z = T1g - T1h;
        T19 = TC + TF;
        T1i = T1g + T1h;
    }
    {
        E Td, Tt, Tg, Tu;
        {
            E Tb, Tc, Te, Tf;
            Tb = ri[(is[4])];
            Tc = ri[(is[11])];
            Td = Tb - Tc;
            Tt = Tb + Tc;
            Te = ri[(is[10])];
            Tf = ri[(is[3])];
            Tg = Te - Tf;
            Tu = Te + Tf;
        }
        Th = Td + Tg;
        T1s = Tt - Tu;
        Tv = Tt + Tu;
        T12 = Tg - Td;
    }
    {
        E TQ, T1m, TT, T1n;
        {
            E TO, TP, TR, TS;
            TO = ii[(is[4])];
            TP = ii[(is[11])];
            TQ = TO - TP;
            T1m = TO + TP;
            TR = ii[(is[10])];
            TS = ii[(is[3])];
            TT = TR - TS;
            T1n = TR + TS;
        }
        TU = TQ - TT;
        T1B = T1n - T1m;
        T17 = TQ + TT;
        T1o = T1m + T1n;
    }
    {
        E Tk, Tw, Tn, Tx;
        {
            E Ti, Tj, Tl, Tm;
            Ti = ri[(is[6])];
            Tj = ri[(is[13])];
            Tk = Ti - Tj;
            Tw = Ti + Tj;
            Tl = ri[(is[8])];
            Tm = ri[(is[1])];
            Tn = Tl - Tm;
            Tx = Tl + Tm;
        }
        To = Tk + Tn;
        T1r = Tw - Tx;
        Ty = Tw + Tx;
        T11 = Tn - Tk;
    }
    {
        E TJ, T1j, TM, T1k;
        {
            E TH, TI, TK, TL;
            TH = ii[(is[6])];
            TI = ii[(is[13])];
            TJ = TH - TI;
            T1j = TH + TI;
            TK = ii[(is[8])];
            TL = ii[(is[1])];
            TM = TK - TL;
            T1k = TK + TL;
        }
        TN = TJ - TM;
        T1A = T1k - T1j;
        T18 = TJ + TM;
        T1l = T1j + T1k;
    }

    accum_real += T3 + Ta + Th + To;
    accum_imag += T16 + T19 + T17 + T18;

    ro[(os[7])] = accum_real;
    io[(os[7])] = accum_imag;
    ro[0] = Tp + Ts + Tv + Ty;
    io[0] = T1f + T1i + T1o + T1l;

    {
        E TV, Tz, T1e, T1d;
        TV = ((KP974927912 * TG) - ((KP781831482) * (TN))) - (KP433883739 * TU);
        Tz = (((KP623489801) * (To)) + (T3)) + (-(((KP900968867) * (Th)) + (KP222520933 * Ta)));
        ro[(os[5])] = Tz - TV;
        ro[(os[9])] = Tz + TV;
        T1e = ((KP974927912 * T10) - ((KP781831482) * (T11))) - (KP433883739 * T12);
        T1d = (((KP623489801) * (T18)) + (T16)) + (-(((KP900968867) * (T17)) + (KP222520933 * T19)));
        io[(os[5])] = T1d - T1e;
        io[(os[9])] = T1e + T1d;
    }
    {
        E TX, TW, T1b, T1c;
        TX = (((KP781831482) * (TG)) + (KP974927912 * TU)) + (KP433883739 * TN);
        TW = (((KP623489801) * (Ta)) + (T3)) + (-(((KP900968867) * (To)) + (KP222520933 * Th)));
        ro[(os[13])] = TW - TX;
        ro[(os[1])] = TW + TX;
        T1b = (((KP781831482) * (T10)) + (KP974927912 * T12)) + (KP433883739 * T11);
        T1c = (((KP623489801) * (T19)) + (T16)) + (-(((KP900968867) * (T18)) + (KP222520933 * T17)));
        io[(os[1])] = T1b + T1c;
        io[(os[13])] = T1c - T1b;
    }
    {
        E TZ, TY, T13, T1a;
        TZ = (((KP433883739) * (TG)) + (KP974927912 * TN)) - (KP781831482 * TU);
        TY = (((KP623489801) * (Th)) + (T3)) + (-(((KP222520933) * (To)) + (KP900968867 * Ta)));
        ro[(os[11])] = TY - TZ;
        ro[(os[3])] = TY + TZ;
        T13 = (((KP433883739) * (T10)) + (KP974927912 * T11)) - (KP781831482 * T12);
        T1a = (((KP623489801) * (T17)) + (T16)) + (-(((KP222520933) * (T18)) + (KP900968867 * T19)));
        io[(os[3])] = T13 + T1a;
        io[(os[11])] = T1a - T13;
    }
    {
        E T1t, T1p, T1C, T1y;
        T1t = ((KP781831482 * T1q) - ((KP433883739) * (T1r))) - (KP974927912 * T1s);
        T1p = (((KP623489801) * (T1i)) + (T1f)) + (-(((KP900968867) * (T1l)) + (KP222520933 * T1o)));
        io[(os[6])] = T1p - T1t;
        io[(os[8])] = T1t + T1p;
        T1C = ((KP781831482 * T1z) - ((KP433883739) * (T1A))) - (KP974927912 * T1B);
        T1y = (((KP623489801) * (Ts)) + (Tp)) + (-(((KP900968867) * (Ty)) + (KP222520933 * Tv)));
        ro[(os[6])] = T1y - T1C;
        ro[(os[8])] = T1y + T1C;
    }
    {
        E T1v, T1u, T1E, T1D;
        T1v = (((KP433883739) * (T1q)) + (KP781831482 * T1s)) - (KP974927912 * T1r);
        T1u = (((KP623489801) * (T1o)) + (T1f)) + (-(((KP222520933) * (T1l)) + (KP900968867 * T1i)));
        io[(os[4])] = T1u - T1v;
        io[(os[10])] = T1v + T1u;
        T1E = (((KP433883739) * (T1z)) + (KP781831482 * T1B)) - (KP974927912 * T1A);
        T1D = (((KP623489801) * (Tv)) + (Tp)) + (-(((KP222520933) * (Ty)) + (KP900968867 * Ts)));
        ro[(os[4])] = T1D - T1E;
        ro[(os[10])] = T1D + T1E;
    }
    {
        E T1w, T1x, T1G, T1F;
        T1w = (((KP974927912) * (T1q)) + (KP433883739 * T1s)) + (KP781831482 * T1r);
        T1x = (((KP623489801) * (T1l)) + (T1f)) + (-(((KP900968867) * (T1o)) + (KP222520933 * T1i)));
        io[(os[2])] = T1w + T1x;
        io[(os[12])] = T1x - T1w;
        T1G = (((KP974927912) * (T1z)) + (KP433883739 * T1B)) + (KP781831482 * T1A);
        T1F = (((KP623489801) * (Ty)) + (Tp)) + (-(((KP900968867) * (Tv)) + (KP222520933 * Ts)));
        ro[(os[12])] = T1F - T1G;
        ro[(os[2])] = T1F + T1G;
    }

    accum_real = 0.0;
    accum_imag = 0.0;
}
}

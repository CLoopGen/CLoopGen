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
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (INT outer = 0; outer < v; outer++) {
        i = v - outer;
        {
            E T5, TR, TA, Ts, TS, Tz, Ta, TU, TD, Tx, TV, TC, Tg, T1a, TG;
            E TJ, T1u, T1d, Tl, T1f, TL, TO, T1v, T1i;
            {
                E T1, T2, T3, T4;
                T1 = ri[0];
                T2 = ri[(is[4])];
                T3 = ri[(is[8])];
                T4 = T2 + T3;
                T5 = T1 + T4;
                TR = ((T1) - ((KP500000000) * (T4)));
                TA = KP866025403 * (T3 - T2);
            }
            {
                E To, Tp, Tq, Tr;
                To = ii[0];
                Tp = ii[(is[4])];
                Tq = ii[(is[8])];
                Tr = Tp + Tq;
                Ts = To + Tr;
                TS = KP866025403 * (Tp - Tq);
                Tz = ((To) - ((KP500000000) * (Tr)));
            }
            {
                E T6, T7, T8, T9;
                T6 = ri[(is[6])];
                T7 = ri[(is[10])];
                T8 = ri[(is[2])];
                T9 = T7 + T8;
                Ta = T6 + T9;
                TU = ((T6) - ((KP500000000) * (T9)));
                TD = KP866025403 * (T8 - T7);
            }
            {
                E Tt, Tu, Tv, Tw;
                Tt = ii[(is[6])];
                Tu = ii[(is[10])];
                Tv = ii[(is[2])];
                Tw = Tu + Tv;
                Tx = Tt + Tw;
                TV = KP866025403 * (Tu - Tv);
                TC = ((Tt) - ((KP500000000) * (Tw)));
            }
            {
                E Tc, Td, Te, Tf;
                Tc = ri[(is[3])];
                Td = ri[(is[7])];
                Te = ri[(is[11])];
                Tf = Td + Te;
                Tg = Tc + Tf;
                T1a = KP866025403 * (Te - Td);
                TG = ((Tc) - ((KP500000000) * (Tf)));
            }
            {
                E T1b, TH, TI, T1c;
                T1b = ii[(is[3])];
                TH = ii[(is[7])];
                TI = ii[(is[11])];
                T1c = TH + TI;
                TJ = KP866025403 * (TH - TI);
                T1u = T1b + T1c;
                T1d = ((T1b) - ((KP500000000) * (T1c)));
            }
            {
                E Th, Ti, Tj, Tk;
                Th = ri[(is[9])];
                Ti = ri[(is[1])];
                Tj = ri[(is[5])];
                Tk = Ti + Tj;
                Tl = Th + Tk;
                T1f = KP866025403 * (Tj - Ti);
                TL = ((Th) - ((KP500000000) * (Tk)));
            }
            {
                E T1g, TM, TN, T1h;
                T1g = ii[(is[9])];
                TM = ii[(is[1])];
                TN = ii[(is[5])];
                T1h = TM + TN;
                TO = KP866025403 * (TM - TN);
                T1v = T1g + T1h;
                T1i = ((T1g) - ((KP500000000) * (T1h)));
            }
            {
                E Tb, Tm, T1t, T1w;
                Tb = T5 + Ta;
                Tm = Tg + Tl;
                ro[(os[6])] = Tb - Tm;
                ro[0] = Tb + Tm;
                {
                    E T1x, T1y, Tn, Ty;
                    T1x = Ts + Tx;
                    T1y = T1u + T1v;
                    io[(os[6])] = T1x - T1y;
                    io[0] = T1x + T1y;
                    Tn = Tg - Tl;
                    Ty = Ts - Tx;
                    io[(os[3])] = Tn + Ty;
                    io[(os[9])] = Ty - Tn;
                }
                T1t = T5 - Ta;
                T1w = T1u - T1v;
                ro[(os[3])] = T1t - T1w;
                ro[(os[9])] = T1t + T1w;
                {
                    E T11, T1l, T1k, T1m, T14, T18, T17, T19;
                    {
                        E TZ, T10, T1e, T1j;
                        TZ = TA + Tz;
                        T10 = TD + TC;
                        T11 = TZ - T10;
                        T1l = TZ + T10;
                        T1e = T1a + T1d;
                        T1j = T1f + T1i;
                        T1k = T1e - T1j;
                        T1m = T1e + T1j;
                    }
                    {
                        E T12, T13, T15, T16;
                        T12 = TG + TJ;
                        T13 = TL + TO;
                        T14 = T12 - T13;
                        T18 = T12 + T13;
                        T15 = TR + TS;
                        T16 = TU + TV;
                        T17 = T15 + T16;
                        T19 = T15 - T16;
                    }
                    io[(os[1])] = T11 - T14;
                    ro[(os[1])] = T19 + T1k;
                    io[(os[7])] = T11 + T14;
                    ro[(os[7])] = T19 - T1k;
                    ro[(os[10])] = T17 - T18;
                    io[(os[10])] = T1l - T1m;
                    ro[(os[4])] = T17 + T18;
                    io[(os[4])] = T1l + T1m;
                }
                {
                    E TF, T1r, T1q, T1s, TQ, TY, TX, T1n;
                    {
                        E TB, TE, T1o, T1p;
                        TB = Tz - TA;
                        TE = TC - TD;
                        TF = TB - TE;
                        T1r = TB + TE;
                        T1o = T1d - T1a;
                        T1p = T1i - T1f;
                        T1q = T1o - T1p;
                        T1s = T1o + T1p;
                    }
                    {
                        E TK, TP, TT, TW;
                        TK = TG - TJ;
                        TP = TL - TO;
                        TQ = TK - TP;
                        TY = TK + TP;
                        TT = TR - TS;
                        TW = TU - TV;
                        TX = TT + TW;
                        T1n = TT - TW;
                    }
                    io[(os[5])] = TF - TQ;
                    ro[(os[5])] = T1n + T1q;
                    io[(os[11])] = TF + TQ;
                    ro[(os[11])] = T1n - T1q;
                    ro[(os[2])] = TX - TY;
                    io[(os[2])] = T1r - T1s;
                    ro[(os[8])] = TX + TY;
                    io[(os[8])] = T1r + T1s;
                }
            }
        }
        ri = ri + ivs;
        ii = ii + ivs;
        ro = ro + ovs;
        io = io + ovs;
        is = is + fftw_an_INT_guaranteed_to_be_zero;
        os = os + fftw_an_INT_guaranteed_to_be_zero;
    }
}

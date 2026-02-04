#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 2 , cr = cr + (2 * ms) , ci = ci - (2 * ms) , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tf, Ti, Tg, Tj, Tl, Tp, TP, TR, TF, TG, TH, T15, TL, TT;
    E Tf2, Ti2, Tg2, Tj2, Tl2, Tp2, TP2, TR2, TF2, TG2, TH2, T152, TL2, TT2;

    // First iteration (m)
    {
        E Th, To, Tk, Tn;
        Tf = W[0];
        Ti = W[1];
        Tg = W[2];
        Tj = W[3];
        Th = Tf * Tg;
        To = Ti * Tg;
        Tk = Ti * Tj;
        Tn = Tf * Tj;
        Tl = Th - Tk;
        Tp = Tn + To;
        TP = Th + Tk;
        TR = Tn - To;
        TF = W[4];
        TG = W[5];
        TH = Tf * TF + Ti * TG;
        T15 = TP * TG - TR * TF;
        TL = Tf * TG - Ti * TF;
        TT = TP * TF + TR * TG;
    }

    {
        E T7, T1f, T1i, Tw, TI, TW, T18, TM, Te, T19, T1a, TD, TJ, TZ, T12;
        E TN, Tm, TE;
        {
            E T3, TU, Tv, TV, T6, T16, Ts, T17;
            {
                E T1, T2, Tt, Tu;
                T1 = cr[0];
                T2 = ci[(rs[3])];
                T3 = T1 + T2;
                TU = T1 - T2;
                Tt = ci[(rs[5])];
                Tu = cr[(rs[6])];
                Tv = Tt - Tu;
                TV = Tt + Tu;
            }
            {
                E T4, T5, Tq, Tr;
                T4 = cr[(rs[2])];
                T5 = ci[(rs[1])];
                T6 = T4 + T5;
                T16 = T4 - T5;
                Tq = ci[(rs[7])];
                Tr = cr[(rs[4])];
                Ts = Tq - Tr;
                T17 = Tq + Tr;
            }
            T7 = T3 + T6;
            T1f = TU + TV;
            T1i = T17 - T16;
            Tw = Ts + Tv;
            TI = T3 - T6;
            TW = TU - TV;
            T18 = T16 + T17;
            TM = Ts - Tv;
        }
        {
            E Ta, TX, TC, T11, Td, T10, Tz, TY;
            {
                E T8, T9, TA, TB;
                T8 = cr[(rs[1])];
                T9 = ci[(rs[2])];
                Ta = T8 + T9;
                TX = T8 - T9;
                TA = ci[(rs[4])];
                TB = cr[(rs[7])];
                TC = TA - TB;
                T11 = TA + TB;
            }
            {
                E Tb, Tc, Tx, Ty;
                Tb = ci[0];
                Tc = cr[(rs[3])];
                Td = Tb + Tc;
                T10 = Tb - Tc;
                Tx = ci[(rs[6])];
                Ty = cr[(rs[5])];
                Tz = Tx - Ty;
                TY = Tx + Ty;
            }
            Te = Ta + Td;
            T19 = TX + TY;
            T1a = T10 + T11;
            TD = Tz + TC;
            TJ = TC - Tz;
            TZ = TX - TY;
            T12 = T10 - T11;
            TN = Ta - Td;
        }
        cr[0] = T7 + Te;
        ci[0] = Tw + TD;
        Tm = T7 - Te;
        TE = Tw - TD;
        cr[(rs[4])] = Tl * Tm - Tp * TE;
        ci[(rs[4])] = Tp * Tm + Tl * TE;
        {
            E TQ, TS, TK, TO;
            TQ = TI + TJ;
            TS = TN + TM;
            cr[(rs[2])] = TP * TQ - TR * TS;
            ci[(rs[2])] = TP * TS + TR * TQ;
            TK = TI - TJ;
            TO = TM - TN;
            cr[(rs[6])] = TH * TK - TL * TO;
            ci[(rs[6])] = TH * TO + TL * TK;
        }
        {
            E T1h, T1l, T1k, T1m, T1g, T1j;
            T1g = KP707106781 * (T19 + T1a);
            T1h = T1f - T1g;
            T1l = T1f + T1g;
            T1j = KP707106781 * (TZ - T12);
            T1k = T1i + T1j;
            T1m = T1i - T1j;
            cr[(rs[3])] = Tg * T1h - Tj * T1k;
            ci[(rs[3])] = Tg * T1k + Tj * T1h;
            cr[(rs[7])] = TF * T1l - TG * T1m;
            ci[(rs[7])] = TF * T1m + TG * T1l;
        }
        {
            E T14, T1d, T1c, T1e, T13, T1b;
            T13 = KP707106781 * (TZ + T12);
            T14 = TW - T13;
            T1d = TW + T13;
            T1b = KP707106781 * (T19 - T1a);
            T1c = T18 - T1b;
            T1e = T18 + T1b;
            cr[(rs[5])] = TT * T14 - T15 * T1c;
            ci[(rs[5])] = T15 * T14 + TT * T1c;
            cr[(rs[1])] = Tf * T1d - Ti * T1e;
            ci[(rs[1])] = Ti * T1d + Tf * T1e;
        }
    }

    // Second iteration (m+1), if within bounds
    if (m + 1 < me) {
        {
            E Th2, To2, Tk2, Tn2;
            Tf2 = W[6];
            Ti2 = W[7];
            Tg2 = W[8];
            Tj2 = W[9];
            Th2 = Tf2 * Tg2;
            To2 = Ti2 * Tg2;
            Tk2 = Ti2 * Tj2;
            Tn2 = Tf2 * Tj2;
            Tl2 = Th2 - Tk2;
            Tp2 = Tn2 + To2;
            TP2 = Th2 + Tk2;
            TR2 = Tn2 - To2;
            TF2 = W[10];
            TG2 = W[11];
            TH2 = Tf2 * TF2 + Ti2 * TG2;
            T152 = TP2 * TG2 - TR2 * TF2;
            TL2 = Tf2 * TG2 - Ti2 * TF2;
            TT2 = TP2 * TF2 + TR2 * TG2;
        }

        {
            E T72, T1f2, T1i2, Tw2, TI2, TW2, T182, TM2, Te2, T192, T1a2, TD2, TJ2, TZ2, T122;
            E TN2, Tm2, TE2;
            {
                E T32, TU2, Tv2, TV2, T62, T162, Ts2, T172;
                {
                    E T1, T2, Tt, Tu;
                    T1 = cr[ms];
                    T2 = ci[(rs[3]) + ms];
                    T32 = T1 + T2;
                    TU2 = T1 - T2;
                    Tt = ci[(rs[5]) + ms];
                    Tu = cr[(rs[6]) + ms];
                    Tv2 = Tt - Tu;
                    TV2 = Tt + Tu;
                }
                {
                    E T4, T5, Tq, Tr;
                    T4 = cr[(rs[2]) + ms];
                    T5 = ci[(rs[1]) + ms];
                    T62 = T4 + T5;
                    T162 = T4 - T5;
                    Tq = ci[(rs[7]) + ms];
                    Tr = cr[(rs[4]) + ms];
                    Ts2 = Tq - Tr;
                    T172 = Tq + Tr;
                }
                T72 = T32 + T62;
                T1f2 = TU2 + TV2;
                T1i2 = T172 - T162;
                Tw2 = Ts2 + Tv2;
                TI2 = T32 - T62;
                TW2 = TU2 - TV2;
                T182 = T162 + T172;
                TM2 = Ts2 - Tv2;
            }
            {
                E Ta, TX, TC, T11, Td, T10, Tz, TY;
                {
                    E T8, T9, TA, TB;
                    T8 = cr[(rs[1]) + ms];
                    T9 = ci[(rs[2]) + ms];
                    Ta = T8 + T9;
                    TX = T8 - T9;
                    TA = ci[(rs[4]) + ms];
                    TB = cr[(rs[7]) + ms];
                    TC = TA - TB;
                    T11 = TA + TB;
                }
                {
                    E Tb, Tc, Tx, Ty;
                    Tb = ci[ms];
                    Tc = cr[(rs[3]) + ms];
                    Td = Tb + Tc;
                    T10 = Tb - Tc;
                    Tx = ci[(rs[6]) + ms];
                    Ty = cr[(rs[5]) + ms];
                    Tz = Tx - Ty;
                    TY = Tx + Ty;
                }
                Te2 = Ta + Td;
                T192 = TX + TY;
                T1a2 = T10 + T11;
                TD2 = Tz + TC;
                TJ2 = TC - Tz;
                TZ2 = TX - TY;
                T122 = T10 - T11;
                TN2 = Ta - Td;
            }
            cr[ms] = T72 + Te2;
            ci[ms] = Tw2 + TD2;
            Tm2 = T72 - Te2;
            TE2 = Tw2 - TD2;
            cr[(rs[4]) + ms] = Tl2 * Tm2 - Tp2 * TE2;
            ci[(rs[4]) + ms] = Tp2 * Tm2 + Tl2 * TE2;
            {
                E TQ2, TS2, TK2, TO2;
                TQ2 = TI2 + TJ2;
                TS2 = TN2 + TM2;
                cr[(rs[2]) + ms] = TP2 * TQ2 - TR2 * TS2;
                ci[(rs[2]) + ms] = TP2 * TS2 + TR2 * TQ2;
                TK2 = TI2 - TJ2;
                TO2 = TM2 - TN2;
                cr[(rs[6]) + ms] = TH2 * TK2 - TL2 * TO2;
                ci[(rs[6]) + ms] = TH2 * TO2 + TL2 * TK2;
            }
            {
                E T1h2, T1l2, T1k2, T1m2, T1g2, T1j2;
                T1g2 = KP707106781 * (T192 + T1a2);
                T1h2 = T1f2 - T1g2;
                T1l2 = T1f2 + T1g2;
                T1j2 = KP707106781 * (TZ2 - T122);
                T1k2 = T1i2 + T1j2;
                T1m2 = T1i2 - T1j2;
                cr[(rs[3]) + ms] = Tg2 * T1h2 - Tj2 * T1k2;
                ci[(rs[3]) + ms] = Tg2 * T1k2 + Tj2 * T1h2;
                cr[(rs[7]) + ms] = TF2 * T1l2 - TG2 * T1m2;
                ci[(rs[7]) + ms] = TF2 * T1m2 + TG2 * T1l2;
            }
            {
                E T142, T1d2, T1c2, T1e2, T132, T1b2;
                T132 = KP707106781 * (TZ2 + T122);
                T142 = TW2 - T132;
                T1d2 = TW2 + T132;
                T1b2 = KP707106781 * (T192 - T1a2);
                T1c2 = T182 - T1b2;
                T1e2 = T182 + T1b2;
                cr[(rs[5]) + ms] = TT2 * T142 - T152 * T1c2;
                ci[(rs[5]) + ms] = T152 * T142 + TT2 * T1c2;
                cr[(rs[1]) + ms] = Tf2 * T1d2 - Ti2 * T1e2;
                ci[(rs[1]) + ms] = Ti2 * T1d2 + Tf2 * T1e2;
            }
        }
    }
}
}

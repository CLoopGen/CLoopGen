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
extern  E KP353553390;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 14); m < me; m = m + 2 , Rp = Rp + (2 * ms) , Ip = Ip + (2 * ms) , Rm = Rm - (2 * ms) , Im = Im - (2 * ms) , W = W + 28 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E Tv, TX, Ts, TY, TE, T1a, TJ, T19, T1l, T1m, T9, T10, Ti, T11, TP;
    E T16, TU, T17, T1i, T1j;
    E Tv2, TX2, Ts2, TY2, TE2, T1a2, TJ2, T192, T1l2, T1m2, T92, T102, Ti2, T112, TP2;
    E T162, TU2, T172, T1i2, T1j2;

    {
        E Tt, Tu, TD, Tz, TA, TB, Tn, TI, Tr, TG, Tk, To;
        Tt = Ip[0];
        Tu = Im[0];
        TD = Tt + Tu;
        Tz = Rm[0];
        TA = Rp[0];
        TB = Tz - TA;
        {
            E Tl, Tm, Tp, Tq;
            Tl = Ip[(rs[2])];
            Tm = Im[(rs[2])];
            Tn = Tl - Tm;
            TI = Tl + Tm;
            Tp = Rp[(rs[2])];
            Tq = Rm[(rs[2])];
            Tr = Tp + Tq;
            TG = Tp - Tq;
        }
        Tv = Tt - Tu;
        TX = TA + Tz;
        Tk = W[6];
        To = W[7];
        Ts = ((Tk * Tn) - ((To) * (Tr)));
        TY = (((Tk) * (Tr)) + (To * Tn));
        {
            E Ty, TC, TF, TH;
            Ty = W[0];
            TC = W[1];
            TE = ((Ty * TB) - ((TC) * (TD)));
            T1a = (((TC) * (TB)) + (Ty * TD));
            TF = W[8];
            TH = W[9];
            TJ = (((TF) * (TG)) + (TH * TI));
            T19 = ((TF * TI) - ((TH) * (TG)));
        }
        T1l = TJ + TE;
        T1m = T1a - T19;
    }

    {
        E T4, TO, T8, TM, Td, TT, Th, TR;
        {
            E T2, T3, T6, T7;
            T2 = Ip[(rs[1])];
            T3 = Im[(rs[1])];
            T4 = T2 - T3;
            TO = T2 + T3;
            T6 = Rp[(rs[1])];
            T7 = Rm[(rs[1])];
            T8 = T6 + T7;
            TM = T6 - T7;
        }
        {
            E Tb, Tc, Tf, Tg;
            Tb = Ip[(rs[3])];
            Tc = Im[(rs[3])];
            Td = Tb - Tc;
            TT = Tb + Tc;
            Tf = Rp[(rs[3])];
            Tg = Rm[(rs[3])];
            Th = Tf + Tg;
            TR = Tf - Tg;
        }
        {
            E T1, T5, Ta, Te;
            T1 = W[2];
            T5 = W[3];
            T9 = ((T1 * T4) - ((T5) * (T8)));
            T10 = (((T1) * (T8)) + (T5 * T4));
            Ta = W[10];
            Te = W[11];
            Ti = ((Ta * Td) - ((Te) * (Th)));
            T11 = (((Ta) * (Th)) + (Te * Td));
            {
                E TL, TN, TQ, TS;
                TL = W[4];
                TN = W[5];
                TP = (((TL) * (TM)) + (TN * TO));
                T16 = ((TL * TO) - ((TN) * (TM)));
                TQ = W[12];
                TS = W[13];
                TU = (((TQ) * (TR)) + (TS * TT));
                T17 = ((TQ * TT) - ((TS) * (TR)));
            }
            T1i = T17 - T16;
            T1j = TP - TU;
        }
    }

    {
        E T1h, T1t, T1w, T1y, T1o, T1s, T1r, T1x;
        {
            E T1f, T1g, T1u, T1v;
            T1f = Tv - Ts;
            T1g = T10 - T11;
            T1h = KP500000000 * (T1f - T1g);
            T1t = KP500000000 * (T1g + T1f);
            T1u = T1i - T1j;
            T1v = T1l + T1m;
            T1w = KP353553390 * (T1u - T1v);
            T1y = KP353553390 * (T1u + T1v);
        }
        {
            E T1k, T1n, T1p, T1q;
            T1k = T1i + T1j;
            T1n = T1l - T1m;
            T1o = KP353553390 * (T1k + T1n);
            T1s = KP353553390 * (T1n - T1k);
            T1p = TX - TY;
            T1q = T9 - Ti;
            T1r = KP500000000 * (T1p - T1q);
            T1x = KP500000000 * (T1p + T1q);
        }
        Ip[(rs[1])] = T1h + T1o;
        Rp[(rs[1])] = T1x + T1y;
        Im[(rs[2])] = T1o - T1h;
        Rm[(rs[2])] = T1x - T1y;
        Rm[0] = T1r - T1s;
        Im[0] = T1w - T1t;
        Rp[(rs[3])] = T1r + T1s;
        Ip[(rs[3])] = T1t + T1w;
    }

    {
        E Tx, T15, T1c, T1e, TW, T14, T13, T1d;
        {
            E Tj, Tw, T18, T1b;
            Tj = T9 + Ti;
            Tw = Ts + Tv;
            Tx = Tj + Tw;
            T15 = Tw - Tj;
            T18 = T16 + T17;
            T1b = T19 + T1a;
            T1c = T18 - T1b;
            T1e = T18 + T1b;
        }
        {
            E TK, TV, TZ, T12;
            TK = TE - TJ;
            TV = TP + TU;
            TW = TK - TV;
            T14 = TV + TK;
            TZ = TX + TY;
            T12 = T10 + T11;
            T13 = TZ - T12;
            T1d = TZ + T12;
        }
        Ip[0] = KP500000000 * (Tx + TW);
        Rp[0] = KP500000000 * (T1d + T1e);
        Im[(rs[3])] = KP500000000 * (TW - Tx);
        Rm[(rs[3])] = KP500000000 * (T1d - T1e);
        Rm[(rs[1])] = KP500000000 * (T13 - T14);
        Im[(rs[1])] = KP500000000 * (T1c - T15);
        Rp[(rs[2])] = KP500000000 * (T13 + T14);
        Ip[(rs[2])] = KP500000000 * (T15 + T1c);
    }

    {
        E Tt2, Tu2, TD2, Tz2, TA2, TB2, Tn2, TI2, Tr2, TG2, Tk2, To2;
        Tt2 = Ip[ms];
        Tu2 = Im[ms];
        TD2 = Tt2 + Tu2;
        Tz2 = Rm[-ms];
        TA2 = Rp[ms];
        TB2 = Tz2 - TA2;
        {
            E Tl2, Tm2, Tp2, Tq2;
            Tl2 = Ip[ms + (rs[2])];
            Tm2 = Im[ms + (rs[2])];
            Tn2 = Tl2 - Tm2;
            TI2 = Tl2 + Tm2;
            Tp2 = Rp[ms + (rs[2])];
            Tq2 = Rm[-ms - (rs[2])];
            Tr2 = Tp2 + Tq2;
            TG2 = Tp2 - Tq2;
        }
        Tv2 = Tt2 - Tu2;
        TX2 = TA2 + Tz2;
        Tk2 = W[6+14];
        To2 = W[7+14];
        Ts2 = ((Tk2 * Tn2) - ((To2) * (Tr2)));
        TY2 = (((Tk2) * (Tr2)) + (To2 * Tn2));
        {
            E Ty2, TC2, TF2, TH2;
            Ty2 = W[0+14];
            TC2 = W[1+14];
            TE2 = ((Ty2 * TB2) - ((TC2) * (TD2)));
            T1a2 = (((TC2) * (TB2)) + (Ty2 * TD2));
            TF2 = W[8+14];
            TH2 = W[9+14];
            TJ2 = (((TF2) * (TG2)) + (TH2 * TI2));
            T192 = ((TF2 * TI2) - ((TH2) * (TG2)));
        }
        T1l2 = TJ2 + TE2;
        T1m2 = T1a2 - T192;
    }

    {
        E T42, TO2, T82, TM2, Td2, TT2, Th2, TR2;
        {
            E T22, T32, T62, T72;
            T22 = Ip[ms + (rs[1])];
            T32 = Im[ms + (rs[1])];
            T42 = T22 - T32;
            TO2 = T22 + T32;
            T62 = Rp[ms + (rs[1])];
            T72 = Rm[-ms - (rs[1])];
            T82 = T62 + T72;
            TM2 = T62 - T72;
        }
        {
            E Tb2, Tc2, Tf2, Tg2;
            Tb2 = Ip[ms + (rs[3])];
            Tc2 = Im[ms + (rs[3])];
            Td2 = Tb2 - Tc2;
            TT2 = Tb2 + Tc2;
            Tf2 = Rp[ms + (rs[3])];
            Tg2 = Rm[-ms - (rs[3])];
            Th2 = Tf2 + Tg2;
            TR2 = Tf2 - Tg2;
        }
        {
            E T12, T52, Ta2, Te2;
            T12 = W[2+14];
            T52 = W[3+14];
            T92 = ((T12 * T42) - ((T52) * (T82)));
            T102 = (((T12) * (T82)) + (T52 * T42));
            Ta2 = W[10+14];
            Te2 = W[11+14];
            Ti2 = ((Ta2 * Td2) - ((Te2) * (Th2)));
            T112 = (((Ta2) * (Th2)) + (Te2 * Td2));
            {
                E TL2, TN2, TQ2, TS2;
                TL2 = W[4+14];
                TN2 = W[5+14];
                TP2 = (((TL2) * (TM2)) + (TN2 * TO2));
                T162 = ((TL2 * TO2) - ((TN2) * (TM2)));
                TQ2 = W[12+14];
                TS2 = W[13+14];
                TU2 = (((TQ2) * (TR2)) + (TS2 * TT2));
                T172 = ((TQ2 * TT2) - ((TS2) * (TR2)));
            }
            T1i2 = T172 - T162;
            T1j2 = TP2 - TU2;
        }
    }

    {
        E T1h2, T1t2, T1w2, T1y2, T1o2, T1s2, T1r2, T1x2;
        {
            E T1f2, T1g2, T1u2, T1v2;
            T1f2 = Tv2 - Ts2;
            T1g2 = T102 - T112;
            T1h2 = KP500000000 * (T1f2 - T1g2);
            T1t2 = KP500000000 * (T1g2 + T1f2);
            T1u2 = T1i2 - T1j2;
            T1v2 = T1l2 + T1m2;
            T1w2 = KP353553390 * (T1u2 - T1v2);
            T1y2 = KP353553390 * (T1u2 + T1v2);
        }
        {
            E T1k2, T1n2, T1p2, T1q2;
            T1k2 = T1i2 + T1j2;
            T1n2 = T1l2 - T1m2;
            T1o2 = KP353553390 * (T1k2 + T1n2);
            T1s2 = KP353553390 * (T1n2 - T1k2);
            T1p2 = TX2 - TY2;
            T1q2 = T92 - Ti2;
            T1r2 = KP500000000 * (T1p2 - T1q2);
            T1x2 = KP500000000 * (T1p2 + T1q2);
        }
        Ip[ms + (rs[1])] = T1h2 + T1o2;
        Rp[ms + (rs[1])] = T1x2 + T1y2;
        Im[ms + (rs[2])] = T1o2 - T1h2;
        Rm[-ms - (rs[2])] = T1x2 - T1y2;
        Rm[-ms] = T1r2 - T1s2;
        Im[ms] = T1w2 - T1t2;
        Rp[ms + (rs[3])] = T1r2 + T1s2;
        Ip[ms + (rs[3])] = T1t2 + T1w2;
    }

    {
        E Tx2, T152, T1c2, T1e2, TW2, T142, T132, T1d2;
        {
            E Tj2, Tw2, T182, T1b2;
            Tj2 = T92 + Ti2;
            Tw2 = Ts2 + Tv2;
            Tx2 = Tj2 + Tw2;
            T152 = Tw2 - Tj2;
            T182 = T162 + T172;
            T1b2 = T192 + T1a2;
            T1c2 = T182 - T1b2;
            T1e2 = T182 + T1b2;
        }
        {
            E TK2, TV2, TZ2, T122;
            TK2 = TE2 - TJ2;
            TV2 = TP2 + TU2;
            TW2 = TK2 - TV2;
            T142 = TV2 + TK2;
            TZ2 = TX2 + TY2;
            T122 = T102 + T112;
            T132 = TZ2 - T122;
            T1d2 = TZ2 + T122;
        }
        Ip[ms] = KP500000000 * (Tx2 + TW2);
        Rp[ms] = KP500000000 * (T1d2 + T1e2);
        Im[ms + (rs[3])] = KP500000000 * (TW2 - Tx2);
        Rm[-ms - (rs[3])] = KP500000000 * (T1d2 - T1e2);
        Rm[ms - (rs[1])] = KP500000000 * (T132 - T142);
        Im[ms + (rs[1])] = KP500000000 * (T1c2 - T152);
        Rp[ms - (rs[2])] = KP500000000 * (T132 + T142);
        Ip[ms + (rs[2])] = KP500000000 * (T152 + T1c2);
    }
}
}

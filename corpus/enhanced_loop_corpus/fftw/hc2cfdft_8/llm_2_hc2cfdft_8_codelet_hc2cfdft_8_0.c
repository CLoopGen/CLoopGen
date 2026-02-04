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
for (m = mb , W = W + ((mb - 1) * 14); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 14 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tv, TX, Ts, TY, TE, T1a, TJ, T19, T1l, T1m, T9, T10, Ti, T11, TP;
    E T16, TU, T17, T1i, T1j;
    const INT rs2 = rs[2];
    const INT rs1 = rs[1];
    const INT rs3 = rs[3];
    E * restrict local_Rp = Rp;
    E * restrict local_Ip = Ip;
    E * restrict local_Rm = Rm;
    E * restrict local_Im = Im;
    E * restrict local_W = W;
    {
        E Tt, Tu, TD, Tz, TA, TB, Tn, TI, Tr, TG, Tk, To;
        Tt = local_Ip[0];
        Tu = local_Im[0];
        TD = Tt + Tu;
        Tz = local_Rm[0];
        TA = local_Rp[0];
        TB = Tz - TA;
        {
            E Tl, Tm, Tp, Tq;
            Tl = local_Ip[rs2];
            Tm = local_Im[rs2];
            Tn = Tl - Tm;
            TI = Tl + Tm;
            Tp = local_Rp[rs2];
            Tq = local_Rm[rs2];
            Tr = Tp + Tq;
            TG = Tp - Tq;
        }
        Tv = Tt - Tu;
        TX = TA + Tz;
        Tk = local_W[6];
        To = local_W[7];
        Ts = ((Tk * Tn) - ((To) * (Tr)));
        TY = (((Tk) * (Tr)) + (To * Tn));
        {
            E Ty, TC, TF, TH;
            Ty = local_W[0];
            TC = local_W[1];
            TE = ((Ty * TB) - ((TC) * (TD)));
            T1a = (((TC) * (TB)) + (Ty * TD));
            TF = local_W[8];
            TH = local_W[9];
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
            T2 = local_Ip[rs1];
            T3 = local_Im[rs1];
            T4 = T2 - T3;
            TO = T2 + T3;
            T6 = local_Rp[rs1];
            T7 = local_Rm[rs1];
            T8 = T6 + T7;
            TM = T6 - T7;
        }
        {
            E Tb, Tc, Tf, Tg;
            Tb = local_Ip[rs3];
            Tc = local_Im[rs3];
            Td = Tb - Tc;
            TT = Tb + Tc;
            Tf = local_Rp[rs3];
            Tg = local_Rm[rs3];
            Th = Tf + Tg;
            TR = Tf - Tg;
        }
        {
            E T1, T5, Ta, Te;
            T1 = local_W[2];
            T5 = local_W[3];
            T9 = ((T1 * T4) - ((T5) * (T8)));
            T10 = (((T1) * (T8)) + (T5 * T4));
            Ta = local_W[10];
            Te = local_W[11];
            Ti = ((Ta * Td) - ((Te) * (Th)));
            T11 = (((Ta) * (Th)) + (Te * Td));
            {
                E TL, TN, TQ, TS;
                TL = local_W[4];
                TN = local_W[5];
                TP = (((TL) * (TM)) + (TN * TO));
                T16 = ((TL * TO) - ((TN) * (TM)));
                TQ = local_W[12];
                TS = local_W[13];
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
        local_Ip[rs1] = T1h + T1o;
        local_Rp[rs1] = T1x + T1y;
        local_Im[rs2] = T1o - T1h;
        local_Rm[rs2] = T1x - T1y;
        local_Rm[0] = T1r - T1s;
        local_Im[0] = T1w - T1t;
        local_Rp[rs3] = T1r + T1s;
        local_Ip[rs3] = T1t + T1w;
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
        local_Ip[0] = KP500000000 * (Tx + TW);
        local_Rp[0] = KP500000000 * (T1d + T1e);
        local_Im[rs3] = KP500000000 * (TW - Tx);
        local_Rm[rs3] = KP500000000 * (T1d - T1e);
        local_Rm[rs1] = KP500000000 * (T13 - T14);
        local_Im[rs1] = KP500000000 * (T1c - T15);
        local_Rp[rs2] = KP500000000 * (T13 + T14);
        local_Ip[rs2] = KP500000000 * (T15 + T1c);
    }
}
}

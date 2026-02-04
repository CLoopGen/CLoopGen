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
    const E kp5 = KP500000000;
    const E kp35 = KP353553390;

    for (INT unroll_factor = 0; unroll_factor < 2; ++unroll_factor) {
        if (m + unroll_factor >= me) break;

        INT offset = unroll_factor * ms;
        INT w_offset = unroll_factor * 14;

        E Tt = Ip[offset];
        E Tu = Im[offset];
        E TD = Tt + Tu;
        E Tz = Rm[-offset];
        E TA = Rp[offset];
        E TB = Tz - TA;

        E Tl = Ip[offset + (rs[2])];
        E Tm = Im[offset + (rs[2])];
        E Tn = Tl - Tm;
        E TI = Tl + Tm;
        E Tp = Rp[offset + (rs[2])];
        E Tq = Rm[-offset - (rs[2])];
        E Tr = Tp + Tq;
        E TG = Tp - Tq;

        Tv = Tt - Tu;
        TX = TA + Tz;
        E Tk = W[6 + w_offset];
        E To = W[7 + w_offset];
        Ts = (Tk * Tn) - (To * Tr);
        TY = (Tk * Tr) + (To * Tn);

        E Ty = W[0 + w_offset];
        E TC = W[1 + w_offset];
        TE = (Ty * TB) - (TC * TD);
        T1a = (TC * TB) + (Ty * TD);
        E TF = W[8 + w_offset];
        E TH = W[9 + w_offset];
        TJ = (TF * TG) + (TH * TI);
        T19 = (TF * TI) - (TH * TG);

        T1l = TJ + TE;
        T1m = T1a - T19;

        E T2 = Ip[offset + (rs[1])];
        E T3 = Im[offset + (rs[1])];
        E T4 = T2 - T3;
        E TO_val = T2 + T3;
        E T6 = Rp[offset + (rs[1])];
        E T7 = Rm[-offset - (rs[1])];
        E T8 = T6 + T7;
        E TM = T6 - T7;

        E Tb = Ip[offset + (rs[3])];
        E Tc = Im[offset + (rs[3])];
        E Td = Tb - Tc;
        E TT_val = Tb + Tc;
        E Tf = Rp[offset + (rs[3])];
        E Tg = Rm[-offset - (rs[3])];
        E Th = Tf + Tg;
        E TR = Tf - Tg;

        E T1_val = W[2 + w_offset];
        E T5_val = W[3 + w_offset];
        T9 = (T1_val * T4) - (T5_val * T8);
        T10 = (T1_val * T8) + (T5_val * T4);
        E Ta = W[10 + w_offset];
        E Te = W[11 + w_offset];
        Ti = (Ta * Td) - (Te * Th);
        T11 = (Ta * Th) + (Te * Td);

        E TL = W[4 + w_offset];
        E TN = W[5 + w_offset];
        TP = (TL * TM) + (TN * TO_val);
        T16 = (TL * TO_val) - (TN * TM);
        E TQ = W[12 + w_offset];
        E TS = W[13 + w_offset];
        TU = (TQ * TR) + (TS * TT_val);
        T17 = (TQ * TT_val) - (TS * TR);

        T1i = T17 - T16;
        T1j = TP - TU;

        E T1f = Tv - Ts;
        E T1g = T10 - T11;
        E T1h = kp5 * (T1f - T1g);
        E T1t = kp5 * (T1g + T1f);
        E T1u = T1i - T1j;
        E T1v = T1l + T1m;
        E T1w = kp35 * (T1u - T1v);
        E T1y = kp35 * (T1u + T1v);

        E T1k = T1i + T1j;
        E T1n = T1l - T1m;
        E T1o = kp35 * (T1k + T1n);
        E T1s = kp35 * (T1n - T1k);
        E T1p = TX - TY;
        E T1q = T9 - Ti;
        E T1r = kp5 * (T1p - T1q);
        E T1x = kp5 * (T1p + T1q);

        Ip[offset + (rs[1])] = T1h + T1o;
        Rp[offset + (rs[1])] = T1x + T1y;
        Im[offset + (rs[2])] = T1o - T1h;
        Rm[-offset - (rs[2])] = T1x - T1y;
        Rm[-offset] = T1r - T1s;
        Im[offset] = T1w - T1t;
        Rp[offset + (rs[3])] = T1r + T1s;
        Ip[offset + (rs[3])] = T1t + T1w;

        E Tj = T9 + Ti;
        E Tw = Ts + Tv;
        E Tx = Tj + Tw;
        E T15 = Tw - Tj;
        E T18 = T16 + T17;
        E T1b = T19 + T1a;
        E T1c = T18 - T1b;
        E T1e = T18 + T1b;

        E TK = TE - TJ;
        E TV = TP + TU;
        E TW = TK - TV;
        E T14 = TV + TK;
        E TZ = TX + TY;
        E T12 = T10 + T11;
        E T13 = TZ - T12;
        E T1d = TZ + T12;

        Ip[offset] = kp5 * (Tx + TW);
        Rp[offset] = kp5 * (T1d + T1e);
        Im[offset + (rs[3])] = kp5 * (TW - Tx);
        Rm[-offset - (rs[3])] = kp5 * (T1d - T1e);
        Rm[offset - (rs[1])] = kp5 * (T13 - T14);
        Im[offset + (rs[1])] = kp5 * (T1c - T15);
        Rp[offset - (rs[2])] = kp5 * (T13 + T14);
        Ip[offset + (rs[2])] = kp5 * (T15 + T1c);
    }
}
}

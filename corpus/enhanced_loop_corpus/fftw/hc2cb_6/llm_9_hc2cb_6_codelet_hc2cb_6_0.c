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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Ty, Td, TE, Ta, TO, Tr, TB, Tk, TL, Tn, TH;
    const INT offset_r = rs[0], offset_i = rs[1], offset_j = rs[2];

    E sum_real = 0.0, sum_imag = 0.0;

    for (INT k = 0; k < 3; ++k) {
        E re_val = (k == 0) ? Rp[0] : (k == 1 ? Rp[offset_i] : Rp[offset_j]);
        E im_val = (k == 0) ? Rm[0] : (k == 1 ? Rm[offset_i] : Rm[offset_j]);
        E ip_val = (k == 0) ? Ip[0] : (k == 1 ? Ip[offset_i] : Ip[offset_j]);
        E imr_val = (k == 0) ? Im[0] : (k == 1 ? Im[offset_i] : Im[offset_j]);

        sum_real += re_val + im_val;
        sum_imag += ip_val - imr_val;
    }

    {
        E T1 = Rp[0], T2 = Rm[offset_j];
        T3 = T1 + T2;
        Ty = T1 - T2;
        E Tb = Ip[0], Tc = Im[offset_j];
        Td = Tb - Tc;
        TE = Tb + Tc;
    }
    {
        E T4 = Rp[offset_j], T5 = Rm[0];
        E T6 = T4 + T5;
        E Tz = T4 - T5;
        E T7 = Rm[offset_i], T8 = Rp[offset_i];
        E T9 = T7 + T8;
        E TA = T7 - T8;
        Ta = T6 + T9;
        TO = KP866025403 * (Tz - TA);
        Tr = KP866025403 * (T6 - T9);
        TB = Tz + TA;
    }
    {
        E Te = Ip[offset_j], Tf = Im[0];
        E Tg = Te - Tf;
        E TG = Te + Tf;
        E Th = Ip[offset_i], Ti = Im[offset_i];
        E Tj = Th - Ti;
        E TF = Th + Ti;
        Tk = Tg + Tj;
        TL = KP866025403 * (TG + TF);
        Tn = KP866025403 * (Tj - Tg);
        TH = TF - TG;
    }

    Rp[0] = T3 + Ta;
    Rm[0] = Td + Tk;

    {
        E TC = Ty + TB;
        E TI = TE - TH;
        E w4 = (W != NULL) ? W[4] : 0.0;
        E w5 = (W != NULL) ? W[5] : 0.0;
        Ip[offset_i] = (w4 * TC) - (w5 * TI);
        Im[offset_i] = (w5 * TC) + (w4 * TI);
    }

    {
        E Tm = T3 - (KP500000000 * Ta);
        E To = Tm - Tn;
        E Tu = Tm + Tn;
        E Tq = Td - (KP500000000 * Tk);
        E Ts = Tq - Tr;
        E Tw = Tq + Tr;
        E w2 = (W != NULL) ? W[2] : 0.0;
        E w3 = (W != NULL) ? W[3] : 0.0;
        E w6 = (W != NULL) ? W[6] : 0.0;
        E w7 = (W != NULL) ? W[7] : 0.0;

        Rp[offset_i] = (w2 * To) - (w3 * Ts);
        Rm[offset_i] = (w2 * Ts) + (w3 * To);
        Rp[offset_j] = (w6 * Tu) - (w7 * Tw);
        Rm[offset_j] = (w6 * Tw) + (w7 * Tu);
    }

    {
        E TK = Ty - (KP500000000 * TB);
        E TM = TK - TL;
        E TS = TK + TL;
        E TP = (KP500000000 * TH) + TE;
        E TQ = TO + TP;
        E TU = TP - TO;
        E w0 = (W != NULL) ? W[0] : 0.0;
        E w1 = (W != NULL) ? W[1] : 0.0;
        E w8 = (W != NULL) ? W[8] : 0.0;
        E w9 = (W != NULL) ? W[9] : 0.0;

        Ip[0] = (w0 * TM) - (w1 * TQ);
        Im[0] = (w1 * TM) + (w0 * TQ);
        Ip[offset_j] = (w8 * TS) - (w9 * TU);
        Im[offset_j] = (w9 * TS) + (w8 * TU);
    }

    W = W + 10;
}
}

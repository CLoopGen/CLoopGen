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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tf, Ti, Tg, Tj, Tl, Tp, TP, TR, TF, TG, TH, T15, TL, TT;
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
        TH = (((Tf) * (TF)) + (Ti * TG));
        T15 = ((TP * TG) - ((TR) * (TF)));
        TL = ((Tf * TG) - ((Ti) * (TF)));
        TT = (((TP) * (TF)) + (TR * TG));
    }
    {
        E T7, T1f, T1i, Tw, TI, TW, T18, TM, Te, T19, T1a, TD, TJ, TZ, T12;
        E TN, Tm, TE;
        {
            E T3, TU, Ts, T17, T6, T16, Tv, TV;
            {
                E T1, T2, Tq, Tr;
                T1 = Rp[0];
                T2 = Rm[(rs[3])];
                T3 = T1 + T2;
                TU = T1 - T2;
                Tq = Ip[0];
                Tr = Im[(rs[3])];
                Ts = Tq - Tr;
                T17 = Tq + Tr;
            }
            {
                E T4, T5, Tt, Tu;
                T4 = Rp[(rs[2])];
                T5 = Rm[(rs[1])];
                T6 = T4 + T5;
                T16 = T4 - T5;
                Tt = Ip[(rs[2])];
                Tu = Im[(rs[1])];
                Tv = Tt - Tu;
                TV = Tt + Tu;
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
            E Ta, TX, Tz, TY, Td, T10, TC, T11;
            {
                E T8, T9, Tx, Ty;
                T8 = Rp[(rs[1])];
                T9 = Rm[(rs[2])];
                Ta = T8 + T9;
                TX = T8 - T9;
                Tx = Ip[(rs[1])];
                Ty = Im[(rs[2])];
                Tz = Tx - Ty;
                TY = Tx + Ty;
            }
            {
                E Tb, Tc, TA, TB;
                Tb = Rm[0];
                Tc = Rp[(rs[3])];
                Td = Tb + Tc;
                T10 = Tb - Tc;
                TA = Ip[(rs[3])];
                TB = Im[0];
                TC = TA - TB;
                T11 = TA + TB;
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
        // Store intermediate values in local arrays to enable consecutive access
        E R_store[4], I_store[4];
        R_store[0] = T7 + Te;
        R_store[1] = ((TP * (TI + TJ)) - ((TR) * (TN + TM)));
        R_store[2] = ((Tl * (T7 - Te)) - ((Tp) * (Tw - TD)));
        R_store[3] = ((TH * (TI - TJ)) - ((TL) * (TM - TN)));

        I_store[0] = ((Tf * (TW + KP707106781*(T19 - T1a))) - ((Ti) * (T18 + KP707106781*(TZ + T12))));
        I_store[1] = ((Tg * (T1f - KP707106781*(T19 + T1a))) - ((Tj) * (T1i + KP707106781*(TZ - T12))));
        I_store[2] = ((TT * (TW - KP707106781*(TZ + T12))) - ((T15) * (T18 - KP707106781*(T19 - T1a))));
        I_store[3] = ((TF * (T1f + KP707106781*(T19 + T1a))) - ((TG) * (T1i - KP707106781*(TZ - T12))));

        // Consecutive write-back to output arrays
        for (INT i = 0; i < 4; ++i) {
            INT idx_r = (i == 0) ? 0 : (i == 1) ? rs[1] : (i == 2) ? rs[2] : rs[3];
            INT idx_i = (i == 0) ? 0 : (i == 1) ? rs[1] : (i == 2) ? rs[2] : rs[3];
            Rp[idx_r] = R_store[i];
            Ip[idx_i] = I_store[i];
        }

        // Handle corresponding imaginary outputs with same pattern
        E Im_store[4];
        Im_store[0] = (((Ti) * (TW + KP707106781*(T19 - T1a))) + (Tf * (T18 + KP707106781*(TZ + T12))));
        Im_store[1] = (((Tg) * (T1i + KP707106781*(TZ - T12))) + (Tj * (T1f - KP707106781*(T19 + T1a))));
        Im_store[2] = (((T15) * (TW - KP707106781*(TZ + T12))) + (TT * (T18 - KP707106781*(T19 - T1a))));
        Im_store[3] = (((TF) * (T1i - KP707106781*(TZ - T12))) + (TG * (T1f + KP707106781*(T19 + T1a))));

        Rm[0] = Tw + TD;
        Rm[rs[2]] = (((Tp) * (T7 - Te)) + (Tl * (Tw - TD)));
        Rm[rs[1]] = (((TP) * (TN + TM)) + (TR * (TI + TJ)));
        Rm[rs[3]] = (((TH) * (TM - TN)) + (TL * (TI - TJ)));

        for (INT i = 0; i < 4; ++i) {
            INT idx = (i == 0) ? 0 : (i == 1) ? rs[1] : (i == 2) ? rs[2] : rs[3];
            Im[idx] = Im_store[i];
        }
    }
}
}

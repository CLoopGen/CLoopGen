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
for (m = mb , W = W + ((mb - 1) * 14); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 14 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T18, T1c, To, Ty, TM, TY, TC, Te, TZ, T10, Tv, Tz, TP, TS;
    E TD;

    // Use local array pointers to enable linear, consecutive memory layout access
    // Flatten strided accesses into a temporary buffer for spatial locality
    E R_local[4], I_local[4], W_local[14];

    // Pre-load data using strided access once, then use consecutive indexing
    R_local[0] = Rp[0];           I_local[0] = Ip[0];
    R_local[1] = Rp[rs[1]];       I_local[1] = Ip[rs[1]];
    R_local[2] = Rp[rs[2]];       I_local[2] = Ip[rs[2]];
    R_local[3] = Rp[rs[3]];       I_local[3] = Ip[rs[3]];

    E Rm_local[4], Im_local[4];
    Rm_local[0] = Rm[0];          Im_local[0] = Im[0];
    Rm_local[1] = Rm[rs[1]];      Im_local[1] = Im[rs[1]];
    Rm_local[2] = Rm[rs[2]];      Im_local[2] = Im[rs[2]];
    Rm_local[3] = Rm[rs[3]];      Im_local[3] = Im[rs[3]];

    // Pre-load twiddle factors into local cache
    for (INT i = 0; i < 14; ++i) W_local[i] = W[i];

    {
        E T3, TK, Tk, TX, T6, TW, Tn, TL;
        {
            E T1 = R_local[0], T2 = Rm_local[3];
            T3 = T1 + T2;
            TK = T1 - T2;
            E Ti = I_local[0], Tj = Im_local[3];
            Tk = Ti - Tj;
            TX = Ti + Tj;
        }
        {
            E T4 = R_local[2], T5 = Rm_local[1];
            T6 = T4 + T5;
            TW = T4 - T5;
            E Tl = I_local[2], Tm = Im_local[1];
            Tn = Tl - Tm;
            TL = Tl + Tm;
        }
        T7 = T3 + T6;
        T18 = TK + TL;
        T1c = TX - TW;
        To = Tk + Tn;
        Ty = T3 - T6;
        TM = TK - TL;
        TY = TW + TX;
        TC = Tk - Tn;
    }
    {
        E Ta, TN, Tr, TO, Td, TQ, Tu, TR;
        {
            E T8 = R_local[1], T9 = Rm_local[2];
            Ta = T8 + T9;
            TN = T8 - T9;
            E Tp = I_local[1], Tq = Im_local[2];
            Tr = Tp - Tq;
            TO = Tp + Tq;
        }
        {
            E Tb = Rm_local[0], Tc = R_local[3];
            Td = Tb + Tc;
            TQ = Tb - Tc;
            E Ts = I_local[3], Tt = Im_local[0];
            Tu = Ts - Tt;
            TR = Ts + Tt;
        }
        Te = Ta + Td;
        TZ = TN + TO;
        T10 = TQ + TR;
        Tv = Tr + Tu;
        Tz = Tu - Tr;
        TP = TN - TO;
        TS = TQ - TR;
        TD = Ta - Td;
    }

    // Write back to global arrays using original strided pattern
    Rp[0] = T7 + Te;
    Rm[0] = To + Tv;

    {
        E Tg = T7 - Te, Tw = To - Tv;
        Rp[rs[2]] = ((W_local[6] * Tg) - (W_local[7] * Tw));
        Rm[rs[2]] = ((W_local[7] * Tg) + (W_local[6] * Tw));
    }
    {
        E TG = Ty + Tz, TI = TD + TC;
        Rp[rs[1]] = ((W_local[2] * TG) - (W_local[3] * TI));
        Rm[rs[1]] = ((W_local[2] * TI) + (W_local[3] * TG));
    }
    {
        E TA = Ty - Tz, TE = TC - TD;
        Rp[rs[3]] = ((W_local[10] * TA) - (W_local[11] * TE));
        Rm[rs[3]] = ((W_local[10] * TE) + (W_local[11] * TA));
    }
    {
        E T19 = KP707106781 * (TZ + T10);
        E T1a = T18 - T19, T1g = T18 + T19;
        E T1d = KP707106781 * (TP - TS);
        E T1e = T1c + T1d, T1i = T1c - T1d;

        Ip[rs[1]] = ((W_local[4] * T1a) - (W_local[5] * T1e));
        Im[rs[1]] = ((W_local[4] * T1e) + (W_local[5] * T1a));
        Ip[rs[3]] = ((W_local[12] * T1g) - (W_local[13] * T1i));
        Im[rs[3]] = ((W_local[12] * T1i) + (W_local[13] * T1g));
    }
    {
        E TT = KP707106781 * (TP + TS);
        E TU = TM - TT, T14 = TM + TT;
        E T11 = KP707106781 * (TZ - T10);
        E T12 = TY - T11, T16 = TY + T11;

        Ip[rs[2]] = ((W_local[8] * TU) - (W_local[9] * T12));
        Im[rs[2]] = ((W_local[9] * TU) + (W_local[8] * T12));
        Ip[0] = ((W_local[0] * T14) - (W_local[1] * T16));
        Im[0] = ((W_local[1] * T14) + (W_local[0] * T16));
    }
}
}

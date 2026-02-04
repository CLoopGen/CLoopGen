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
    E T7, T1e, TH, T19, TF, T13, TR, TU, Ti, T1f, TK, T16, Tu, T12, TM;
    E TP;
    // Use local arrays to accumulate data with consecutive memory layout
    E local_Rp[4], local_Im[4], local_Rm[4], local_Ip[4];
    E local_W[14];

    // Prefetch and reorder strided accesses into consecutive local storage
    local_Rp[0] = Rp[0];
    local_Rp[1] = Rp[rs[1]];
    local_Rp[2] = Rp[rs[2]];
    local_Rp[3] = Rp[rs[3]];

    local_Rm[0] = Rm[0];
    local_Rm[1] = Rm[rs[1]];
    local_Rm[2] = Rm[rs[2]];
    local_Rm[3] = Rm[rs[3]];

    local_Ip[0] = Ip[0];
    local_Ip[1] = Ip[rs[1]];
    local_Ip[2] = Ip[rs[2]];
    local_Ip[3] = Ip[rs[3]];

    local_Im[0] = Im[0];
    local_Im[1] = Im[rs[1]];
    local_Im[2] = Im[rs[2]];
    local_Im[3] = Im[rs[3]];

    for (INT i = 0; i < 14; ++i) {
        local_W[i] = W[i];
    }

    {
        E T1, T18, T6, T17;
        T1 = local_Rp[0];
        T18 = local_Rm[0];
        {
            E T3 = local_Rp[2], T5 = local_Rm[2];
            E T2 = local_W[6], T4 = local_W[7];
            T6 = T2 * T3 + T4 * T5;
            T17 = T2 * T5 - T4 * T3;
        }
        T7 = T1 + T6;
        T1e = T18 - T17;
        TH = T1 - T6;
        T19 = T17 + T18;
    }
    {
        E Tz, TS, TE, TT;
        {
            E Tw = local_Ip[3], Ty = local_Im[3];
            E Tv = local_W[12], Tx = local_W[13];
            Tz = Tv * Tw + Tx * Ty;
            TS = Tv * Ty - Tx * Tw;
        }
        {
            E TB = local_Ip[1], TD = local_Im[1];
            E TA = local_W[4], TC = local_W[5];
            TE = TA * TB + TC * TD;
            TT = TA * TD - TC * TB;
        }
        TF = Tz + TE;
        T13 = TS + TT;
        TR = Tz - TE;
        TU = TS - TT;
    }
    {
        E Tc, TI, Th, TJ;
        {
            E T9 = local_Rp[1], Tb = local_Rm[1];
            E T8 = local_W[2], Ta = local_W[3];
            Tc = T8 * T9 + Ta * Tb;
            TI = T8 * Tb - Ta * T9;
        }
        {
            E Te = local_Rp[3], Tg = local_Rm[3];
            E Td = local_W[10], Tf = local_W[11];
            Th = Td * Te + Tf * Tg;
            TJ = Td * Tg - Tf * Te;
        }
        Ti = Tc + Th;
        T1f = Tc - Th;
        TK = TI - TJ;
        T16 = TI + TJ;
    }
    {
        E To, TN, Tt, TO;
        {
            E Tl = local_Ip[0], Tn = local_Im[0];
            E Tk = local_W[0], Tm = local_W[1];
            To = Tk * Tl + Tm * Tn;
            TN = Tk * Tn - Tm * Tl;
        }
        {
            E Tq = local_Ip[2], Ts = local_Im[2];
            E Tp = local_W[8], Tr = local_W[9];
            Tt = Tp * Tq + Tr * Ts;
            TO = Tp * Ts - Tr * Tq;
        }
        Tu = To + Tt;
        T12 = TN + TO;
        TM = To - Tt;
        TP = TN - TO;
    }
    {
        E Tj, TG, T1b, T1c;
        Tj = T7 + Ti;
        TG = Tu + TF;
        Rm[rs[3]] = Tj - TG;
        Rp[0] = Tj + TG;
        {
            E T15 = T12 + T13, T1a = T16 + T19;
            Im[rs[3]] = T15 - T1a;
            Ip[0] = T15 + T1a;
            E T11 = T7 - Ti, T14 = T12 - T13;
            Rm[rs[1]] = T11 - T14;
            Rp[rs[2]] = T11 + T14;
        }
        T1b = TF - Tu;
        T1c = T19 - T16;
        Im[rs[1]] = T1b - T1c;
        Ip[rs[2]] = T1b + T1c;
        {
            E TX = TH - TK, T1g = T1e - T1f;
            E TY = TP - TM, TZ = TR + TU;
            E T10 = KP707106781 * (TY - TZ);
            E T1d = KP707106781 * (TY + TZ);
            Rm[0] = TX - T10;
            Ip[rs[1]] = T1d + T1g;
            Rp[rs[3]] = TX + T10;
            Im[rs[2]] = T1d - T1g;
        }
        {
            E TL = TH + TK, T1i = T1f + T1e;
            E TQ = TM + TP, TV = TR - TU;
            E TW = KP707106781 * (TQ + TV);
            E T1h = KP707106781 * (TV - TQ);
            Rm[rs[2]] = TL - TW;
            Ip[rs[3]] = T1h + T1i;
            Rp[rs[1]] = TL + TW;
            Im[0] = T1h - T1i;
        }
    }
}
}

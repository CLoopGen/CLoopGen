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

    // Define base pointers with precomputed offsets for indirect access via index array
    const INT idx[4] = {0, rs[1], rs[2], rs[3]};
    
    // Indirect access through index array to simulate irregular or gather-scatter pattern
    E * restrict rbp = Rp;
    E * restrict ibp = Ip;
    E * restrict rmbp = Rm;
    E * restrict imbp = Im;
    E * restrict wb = W;

    #define GATHER_RP(i) rbp[idx[i]]
    #define GATHER_IP(i) ibp[idx[i]]
    #define GATHER_RM(i) rmbp[idx[i]]
    #define GATHER_IM(i) imbp[idx[i]]

    {
        E T1, T18, T6, T17;
        T1 = GATHER_RP(0);
        T18 = GATHER_RM(0);
        {
            E T3 = GATHER_RP(2), T5 = GATHER_RM(2);
            E T2 = wb[6], T4 = wb[7];
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
            E Tw = GATHER_IP(3), Ty = GATHER_IM(3);
            E Tv = wb[12], Tx = wb[13];
            Tz = Tv * Tw + Tx * Ty;
            TS = Tv * Ty - Tx * Tw;
        }
        {
            E TB = GATHER_IP(1), TD = GATHER_IM(1);
            E TA = wb[4], TC = wb[5];
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
            E T9 = GATHER_RP(1), Tb = GATHER_RM(1);
            E T8 = wb[2], Ta = wb[3];
            Tc = T8 * T9 + Ta * Tb;
            TI = T8 * Tb - Ta * T9;
        }
        {
            E Te = GATHER_RP(3), Tg = GATHER_RM(3);
            E Td = wb[10], Tf = wb[11];
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
            E Tl = GATHER_IP(0), Tn = GATHER_IM(0);
            E Tk = wb[0], Tm = wb[1];
            To = Tk * Tl + Tm * Tn;
            TN = Tk * Tn - Tm * Tl;
        }
        {
            E Tq = GATHER_IP(2), Ts = GATHER_IM(2);
            E Tp = wb[8], Tr = wb[9];
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
        rmbp[idx[3]] = Tj - TG;
        rbp[0] = Tj + TG;
        {
            E T15 = T12 + T13, T1a = T16 + T19;
            imbp[idx[3]] = T15 - T1a;
            ibp[0] = T15 + T1a;
            E T11 = T7 - Ti, T14 = T12 - T13;
            rmbp[idx[1]] = T11 - T14;
            rbp[idx[2]] = T11 + T14;
        }
        T1b = TF - Tu;
        T1c = T19 - T16;
        imbp[idx[1]] = T1b - T1c;
        ibp[idx[2]] = T1b + T1c;
        {
            E TX = TH - TK, T1g = T1e - T1f;
            E TY = TP - TM, TZ = TR + TU;
            E T10 = KP707106781 * (TY - TZ);
            E T1d = KP707106781 * (TY + TZ);
            rmbp[0] = TX - T10;
            ibp[idx[1]] = T1d + T1g;
            rbp[idx[3]] = TX + T10;
            imbp[idx[2]] = T1d - T1g;
        }
        {
            E TL = TH + TK, T1i = T1f + T1e;
            E TQ = TM + TP, TV = TR - TU;
            E TW = KP707106781 * (TQ + TV);
            E T1h = KP707106781 * (TV - TQ);
            rmbp[idx[2]] = TL - TW;
            ibp[idx[3]] = T1h + T1i;
            rbp[idx[1]] = TL + TW;
            imbp[0] = T1h - T1i;
        }
    }
}
}

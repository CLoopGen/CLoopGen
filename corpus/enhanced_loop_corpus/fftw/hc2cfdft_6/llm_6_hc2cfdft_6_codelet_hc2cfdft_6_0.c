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
extern  E KP250000000;
extern  E KP500000000;
extern  E KP433012701;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, TM, Tc, TN, Ts, T10, TI, TR, TF, T11, TH, TU;
    {
        E T1, T2, TD, Tz, TA, TB, T7, Tf, Tb, Th, Tq, Tw, Tm, Tu;
        T1 = Ip[0];
        T2 = Im[0];
        TD = T1 + T2;
        Tz = Rm[0];
        TA = Rp[0];
        TB = Tz - TA;
        T7 = Ip[(rs[1])] + Im[(rs[1])];
        Tf = Ip[(rs[1])] - Im[(rs[1])];
        Tb = Rp[(rs[1])] - Rm[(rs[1])];
        Th = Rp[(rs[1])] + Rm[(rs[1])];
        Tq = Rp[(rs[2])] - Rm[(rs[2])];
        Tw = Rp[(rs[2])] + Rm[(rs[2])];
        Tm = Ip[(rs[2])] + Im[(rs[2])];
        Tu = Ip[(rs[2])] - Im[(rs[2])];

        T3 = T1 - T2;
        TM = TA + Tz;
        Tc = (W[5] * T7) + (W[4] * Tb);
        TN = (W[4] * T7) - (W[5] * Tb);
        Ts = (W[2] * Tf) - (W[3] * Th) - ((W[9] * Tm) + (W[8] * Tq));
        T10 = (W[3] * Tf) + (W[2] * Th) + ((W[8] * Tm) - (W[9] * Tq));
        TI = (W[2] * Tf) - (W[3] * Th) + ((W[9] * Tm) + (W[8] * Tq));
        TR = (W[8] * Tm) - (W[9] * Tq) - ((W[2] * Tf) - (W[3] * Th));
        TF = (W[6] * Tu) - (W[7] * Tw) + (W[0] * TB) - (W[1] * TD);
        T11 = (W[7] * Tu) + (W[6] * Tw) + (W[1] * TB) + (W[0] * TD);
        TH = (W[0] * TB) - (W[1] * TD) - ((W[6] * Tu) - (W[7] * Tw));
        TU = (W[7] * Tu) + (W[6] * Tw) - ((W[1] * TB) + (W[0] * TD));
    }
    {
        E Td, TG, TZ;
        Td = T3 - Tc;
        TG = Ts + TF;
        TZ = (KP500000000 * Td) - (KP250000000 * TG);
        Ip[0] = KP500000000 * (Td + TG);
        Im[(rs[1])] = (KP433012701 * (T10 - T11)) - TZ;
        Ip[(rs[2])] = TZ + (KP433012701 * (T10 - T11));
    }
    {
        E T13, T14, T15;
        T13 = TM + TN;
        T14 = T10 + T11;
        T15 = (KP500000000 * T13) - (KP250000000 * T14);
        Rp[(rs[2])] = T15 - (KP433012701 * (Ts - TF));
        Rp[0] = KP500000000 * (T13 + T14);
        Rm[(rs[1])] = (KP433012701 * (Ts - TF)) + T15;
    }
    {
        E TJ, TK, TX;
        TJ = TH - TI;
        TK = Tc + T3;
        TX = (KP500000000 * TK) + (KP250000000 * TJ);
        Im[(rs[2])] = KP500000000 * (TJ - TK);
        Im[0] = (KP433012701 * (TU - TR)) - TX;
        Ip[(rs[1])] = TX + (KP433012701 * (TU - TR));
    }
    {
        E TO, TV, TW;
        TO = TM - TN;
        TV = TR + TU;
        TW = (KP500000000 * TO) - (KP250000000 * TV);
        Rp[(rs[1])] = (KP433012701 * (TI + TH)) + TW;
        Rm[(rs[2])] = KP500000000 * (TO + TV);
        Rm[0] = TW - (KP433012701 * (TI + TH));
    }
}
}

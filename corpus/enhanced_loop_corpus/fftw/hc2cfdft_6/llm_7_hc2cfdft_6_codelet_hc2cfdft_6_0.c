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
for (m = mb; m < me; m += 2, Rp = Rp + 2*ms, Ip = Ip + 2*ms, Rm = Rm - 2*ms, Im = Im - 2*ms, W = W + 20, (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;

    for (INT inner = 0; inner < 2; inner++) {
        E T3, TM, Tc, TN, Ts, T10, TI, TR, TF, T11, TH, TU;
        INT offset = inner * ms;
        stride s = rs + inner;
        E *Wp = W + inner * 10;

        E T1 = Ip[offset], T2 = Im[offset];
        E TD = T1 + T2;
        E Tz = Rm[offset], TA = Rp[offset];
        E TB = Tz - TA;
        E T5 = Ip[s[1]], T6 = Im[s[1]];
        E T7 = T5 + T6;
        E Tf = T5 - T6;
        E T9 = Rp[s[1]], Ta = Rm[s[1]];
        E Tb = T9 - Ta;
        E Th = T9 + Ta;
        E To = Rp[s[2]], Tp = Rm[s[2]];
        E Tq = To - Tp;
        E Tw = To + Tp;
        E Tk = Ip[s[2]], Tl = Im[s[2]];
        E Tm = Tk + Tl;
        E Tu = Tk - Tl;

        T3 = T1 - T2;
        TM = TA + Tz;
        Tc = (Wp[5] * T7) + (Wp[4] * Tb);
        TN = (Wp[4] * T7) - (Wp[5] * Tb);

        E Ti = (Wp[2] * Tf) - (Wp[3] * Th);
        E TP = (Wp[3] * Tf) + (Wp[2] * Th);
        E Tr = (Wp[9] * Tm) + (Wp[8] * Tq);
        E TQ = (Wp[8] * Tm) - (Wp[9] * Tq);
        Ts = Ti - Tr;
        T10 = TP + TQ;
        TI = Ti + Tr;
        TR = TP - TQ;

        E Tx = (Wp[6] * Tu) - (Wp[7] * Tw);
        E TS = (Wp[7] * Tu) + (Wp[6] * Tw);
        E TE = (Wp[0] * TB) - (Wp[1] * TD);
        E TT = (Wp[1] * TB) + (Wp[0] * TD);
        TF = Tx + TE;
        T11 = TS + TT;
        TH = TE - Tx;
        TU = TS - TT;

        E Td = T3 - Tc;
        E TG = Ts + TF;
        E TZ = (KP500000000 * Td) - (KP250000000 * TG);
        Ip[offset] = KP500000000 * (Td + TG);
        Im[s[1]] = (KP433012701 * (T10 - T11)) - TZ;
        Ip[s[2]] = TZ + (KP433012701 * (T10 - T11));

        E T13 = TM + TN;
        E T14 = T10 + T11;
        E T15 = (KP500000000 * T13) - (KP250000000 * T14);
        Rp[s[2]] = T15 - (KP433012701 * (Ts - TF));
        Rp[offset] = KP500000000 * (T13 + T14);
        Rm[s[1]] = (KP433012701 * (Ts - TF)) + T15;

        E TJ = TH - TI;
        E TK = Tc + T3;
        E TX = (KP500000000 * TK) + (KP250000000 * TJ);
        Im[s[2]] = KP500000000 * (TJ - TK);
        Im[offset] = (KP433012701 * (TU - TR)) - TX;
        Ip[s[1]] = TX + (KP433012701 * (TU - TR));

        E TO = TM - TN;
        E TV = TR + TU;
        E TW = (KP500000000 * TO) - (KP250000000 * TV);
        Rp[s[1]] = (KP433012701 * (TI + TH)) + TW;
        Rm[s[2]] = KP500000000 * (TO + TV);
        Rm[offset] = TW - (KP433012701 * (TI + TH));
    }
}
}

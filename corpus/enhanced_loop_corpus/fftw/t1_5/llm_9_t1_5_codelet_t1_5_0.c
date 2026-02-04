#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 2, ri = ri + (ms * 2), ii = ii + (ms * 2), W = W + 16, (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;

    for (INT inner = 0; inner < 2; inner++) {
        E T1, TE, Tu, Tx, TJ, TI, TB, TC, TD, Tc, Tn, To;
        INT offset = inner * ms;
        INT w_offset = inner * 8;
        T1 = ri[offset];
        TE = ii[offset];
        {
            E T6, Ts, Tm, Tw, Tb, Tt, Th, Tv;
            {
                E T3 = ri[offset + rs[1]], T5 = ii[offset + rs[1]];
                E T2 = W[w_offset + 0], T4 = W[w_offset + 1];
                T6 = T2 * T3 + T4 * T5;
                Ts = T2 * T5 - T4 * T3;
            }
            {
                E Tj = ri[offset + rs[3]], Tl = ii[offset + rs[3]];
                E Ti = W[w_offset + 4], Tk = W[w_offset + 5];
                Tm = Ti * Tj + Tk * Tl;
                Tw = Ti * Tl - Tk * Tj;
            }
            {
                E T8 = ri[offset + rs[4]], Ta = ii[offset + rs[4]];
                E T7 = W[w_offset + 6], T9 = W[w_offset + 7];
                Tb = T7 * T8 + T9 * Ta;
                Tt = T7 * Ta - T9 * T8;
            }
            {
                E Te = ri[offset + rs[2]], Tg = ii[offset + rs[2]];
                E Td = W[w_offset + 2], Tf = W[w_offset + 3];
                Th = Td * Te + Tf * Tg;
                Tv = Td * Tg - Tf * Te;
            }
            Tu = Ts - Tt;
            Tx = Tv - Tw;
            TJ = Th - Tm;
            TI = T6 - Tb;
            TB = Ts + Tt;
            TC = Tv + Tw;
            TD = TB + TC;
            Tc = T6 + Tb;
            Tn = Th + Tm;
            To = Tc + Tn;
        }
        ri[offset] = T1 + To;
        ii[offset] = TD + TE;
        {
            E Ty = KP951056516 * Tu + KP587785252 * Tx;
            E TA = KP951056516 * Tx - KP587785252 * Tu;
            E Tp = KP559016994 * (Tc - Tn);
            E Tq = T1 - KP250000000 * To;
            E Tr = Tp + Tq;
            E Tz = Tq - Tp;
            ri[offset + rs[4]] = Tr - Ty;
            ri[offset + rs[3]] = Tz + TA;
            ri[offset + rs[1]] = Tr + Ty;
            ri[offset + rs[2]] = Tz - TA;
        }
        {
            E TK = KP951056516 * TI + KP587785252 * TJ;
            E TL = KP951056516 * TJ - KP587785252 * TI;
            E TF = KP559016994 * (TB - TC);
            E TG = TE - KP250000000 * TD;
            E TH = TF + TG;
            E TM = TG - TF;
            ii[offset + rs[1]] = TH - TK;
            ii[offset + rs[3]] = TM - TL;
            ii[offset + rs[4]] = TK + TH;
            ii[offset + rs[2]] = TL + TM;
        }
    }
}

}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP866025403;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 2 , rio = rio + 2*ms , iio = iio + 2*ms , W = W + 8 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T1, T4, T6, Tc, Td, Te, Tf, T9, Tl, To, Tq, Tw, Tx, Ty, Tt, Tz;
    E TR, TS, TN, TT, TF, TI, TK, TQ;
    E T1b, T4b, T6b, Tcb, Tdb, Teb, Tfb, T9b, Tlb, Tob, Tqb, Twb, Txb, Tyb, Ttb, Tzb;
    E TRb, TSb, TNb, TTb, TFb, TIb, TKb, TQb;

    // First iteration (m)
    T1 = rio[0]; T4 = rio[rs[1]] + rio[rs[2]]; T6 = T1 - KP500000000*T4; Tc = KP866025403*(rio[rs[2]] - rio[rs[1]]);
    Td = iio[0]; Te = iio[rs[1]] + iio[rs[2]]; Tf = Td - KP500000000*Te; T9 = KP866025403*(iio[rs[1]] - iio[rs[2]]);
    Tl = rio[vs[1]]; To = rio[vs[1]+rs[1]] + rio[vs[1]+rs[2]]; Tq = Tl - KP500000000*To; Tw = KP866025403*(rio[vs[1]+rs[2]] - rio[vs[1]+rs[1]]);
    Tx = iio[vs[1]]; Ty = iio[vs[1]+rs[1]] + iio[vs[1]+rs[2]]; Tz = Tx - KP500000000*Ty; Tt = KP866025403*(iio[vs[1]+rs[1]] - iio[vs[1]+rs[2]]);
    TR = iio[vs[2]]; TS = iio[vs[2]+rs[1]] + iio[vs[2]+rs[2]]; TT = TR - KP500000000*TS; TN = KP866025403*(iio[vs[2]+rs[1]] - iio[vs[2]+rs[2]]);
    TF = rio[vs[2]]; TI = rio[vs[2]+rs[1]] + rio[vs[2]+rs[2]]; TK = TF - KP500000000*TI; TQ = KP866025403*(rio[vs[2]+rs[2]] - rio[vs[2]+rs[1]]);

    // Second iteration (m+1), offset by ms
    T1b = rio[ms]; T4b = rio[ms + rs[1]] + rio[ms + rs[2]]; T6b = T1b - KP500000000*T4b; Tcb = KP866025403*(rio[ms + rs[2]] - rio[ms + rs[1]]);
    Tdb = iio[ms]; Teb = iio[ms + rs[1]] + iio[ms + rs[2]]; Tfb = Tdb - KP500000000*Te; T9b = KP866025403*(iio[ms + rs[1]] - iio[ms + rs[2]]);
    Tlb = rio[vs[1] + ms]; Tob = rio[vs[1] + ms + rs[1]] + rio[vs[1] + ms + rs[2]]; Tqb = Tlb - KP500000000*Tob; Twb = KP866025403*(rio[vs[1] + ms + rs[2]] - rio[vs[1] + ms + rs[1]]);
    Txb = iio[vs[1] + ms]; Tyb = iio[vs[1] + ms + rs[1]] + iio[vs[1] + ms + rs[2]]; Tzb = Txb - KP500000000*Tyb; Ttb = KP866025403*(iio[vs[1] + ms + rs[1]] - iio[vs[1] + ms + rs[2]]);
    TRb = iio[vs[2] + ms]; TSb = iio[vs[2] + ms + rs[1]] + iio[vs[2] + ms + rs[2]]; TTb = TRb - KP500000000*TSb; TNb = KP866025403*(iio[vs[2] + ms + rs[1]] - iio[vs[2] + ms + rs[2]]);
    TFb = rio[vs[2] + ms]; TIb = rio[vs[2] + ms + rs[1]] + rio[vs[2] + ms + rs[2]]; TKb = TFb - KP500000000*TIb; TQb = KP866025403*(rio[vs[2] + ms + rs[2]] - rio[vs[2] + ms + rs[1]]);

    // Store results for first iteration
    rio[0] = T1 + T4; iio[0] = Td + Te;
    rio[rs[1]] = Tl + To; iio[rs[1]] = Tx + Ty;
    rio[rs[2]] = TF + TI; iio[rs[2]] = TR + TS;

    rio[vs[1]] = W[0]*(T6 + T9) + W[1]*(Tc + Tf);
    iio[vs[1]] = W[0]*(Tc + Tf) - W[1]*(T6 + T9);
    rio[vs[1] + rs[1]] = W[0]*(Tq + Tw) + W[1]*(Tz + Tt);
    iio[vs[1] + rs[1]] = W[0]*(Tz + Tt) - W[1]*(Tq + Tw);
    rio[vs[1] + rs[2]] = W[0]*(TK + TN) + W[1]*(TT + TQ);
    iio[vs[1] + rs[2]] = W[0]*(TT + TQ) - W[1]*(TK + TN);
    rio[vs[2]] = W[2]*(T6 - T9) + W[3]*(Tf - Tc);
    iio[vs[2]] = W[2]*(Tf - Tc) - W[3]*(T6 - T9);
    rio[vs[2] + rs[1]] = W[2]*(Tq - Tt) + W[3]*(Tz - Tw);
    iio[vs[2] + rs[1]] = W[2]*(Tz - Tw) - W[3]*(Tq - Tt);
    rio[vs[2] + rs[2]] = W[2]*(TK - TN) + W[3]*(TT - TQ);
    iio[vs[2] + rs[2]] = W[2]*(TT - TQ) - W[3]*(TK - TN);

    // Store results for second iteration
    rio[ms] = T1b + T4b; iio[ms] = Tdb + Teb;
    rio[ms + rs[1]] = Tlb + Tob; iio[ms + rs[1]] = Txb + Tyb;
    rio[ms + rs[2]] = TFb + TIb; iio[ms + rs[2]] = TRb + TSb;

    rio[vs[1] + ms] = W[4]*(T6b + T9b) + W[5]*(Tcb + Tfb);
    iio[vs[1] + ms] = W[4]*(Tcb + Tfb) - W[5]*(T6b + T9b);
    rio[vs[1] + ms + rs[1]] = W[4]*(Tqb + Twb) + W[5]*(Tzb + Ttb);
    iio[vs[1] + ms + rs[1]] = W[4]*(Tzb + Ttb) - W[5]*(Tqb + Twb);
    rio[vs[1] + ms + rs[2]] = W[4]*(TKb + TNb) + W[5]*(TTb + TQb);
    iio[vs[1] + ms + rs[2]] = W[4]*(TTb + TQb) - W[5]*(TKb + TNb);
    rio[vs[2] + ms] = W[6]*(T6b - T9b) + W[7]*(Tfb - Tcb);
    iio[vs[2] + ms] = W[6]*(Tfb - Tcb) - W[7]*(T6b - T9b);
    rio[vs[2] + ms + rs[1]] = W[6]*(Tqb - Ttb) + W[7]*(Tzb - Twb);
    iio[vs[2] + ms + rs[1]] = W[6]*(Tzb - Twb) - W[7]*(Tqb - Ttb);
    rio[vs[2] + ms + rs[2]] = W[6]*(TKb - TNb) + W[7]*(TTb - TQb);
    iio[vs[2] + ms + rs[2]] = W[6]*(TTb - TQb) - W[7]*(TKb - TNb);
}
}

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
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T4, T7, T9, Tb, Tl, Tf, Tj;
    {
        E T8, Te, Ta, Td;
        T2 = W[0];
        T4 = W[1];
        T7 = W[2];
        T9 = W[3];
        T8 = T2 * T7;
        Te = T4 * T7;
        Ta = T4 * T9;
        Td = T2 * T9;
        Tb = T8 - Ta;
        Tl = Td - Te;
        Tf = Td + Te;
        Tj = T8 + Ta;
    }
    {
        E T1 = ri[0];
        E TI = ii[0];
        E T6 = (((T2) * (ri[(rs[1])])) + (T4 * ii[(rs[1])]));
        E Tw = ((T2 * ii[(rs[1])]) - ((T4) * (ri[(rs[1])])));
        E Tq = (((T7) * (ri[(rs[3])])) + (T9 * ii[(rs[3])]));
        E TA = ((T7 * ii[(rs[3])]) - ((T9) * (ri[(rs[3])])));
        E Th = (((Tb) * (ri[(rs[4])])) + (Tf * ii[(rs[4])]));
        E Tx = ((Tb * ii[(rs[4])]) - ((Tf) * (ri[(rs[4])])));
        E Tn = (((Tj) * (ri[(rs[2])])) + (Tl * ii[(rs[2])]));
        E Tz = ((Tj * ii[(rs[2])]) - ((Tl) * (ri[(rs[2])])));

        E Ty = Tw - Tx;
        E TB = Tz - TA;
        E TN = Tn - Tq;
        E TM = T6 - Th;
        E TH = Tw + Tx + Tz + TA;
        E Ts = T6 + Th + Tn + Tq;

        ri[0] = T1 + Ts;
        ii[0] = TH + TI;

        E TC = (((KP951056516) * (Ty)) + (KP587785252 * TB));
        E TE = ((KP951056516 * TB) - ((KP587785252) * (Ty)));
        E Tv = KP559016994 * (T6 + Th - Tn - Tq) + ((T1) - ((KP250000000) * (Ts)));
        E TD = ((T1) - ((KP250000000) * (Ts))) - KP559016994 * (T6 + Th - Tn - Tq);

        ri[(rs[4])] = Tv - TC;
        ri[(rs[3])] = TD + TE;
        ri[(rs[1])] = Tv + TC;
        ri[(rs[2])] = TD - TE;

        E TO = (((KP951056516) * (TM)) + (KP587785252 * TN));
        E TP = ((KP951056516 * TN) - ((KP587785252) * (TM)));
        E TL = KP559016994 * (Tw + Tx - Tz - TA) + ((TI) - ((KP250000000) * (TH)));
        E TQ = ((TI) - ((KP250000000) * (TH))) - KP559016994 * (Tw + Tx - Tz - TA);

        ii[(rs[1])] = TL - TO;
        ii[(rs[3])] = TQ - TP;
        ii[(rs[4])] = TO + TL;
        ii[(rs[2])] = TP + TQ;
    }
}
}

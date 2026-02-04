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
extern  E KP866025403;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Outer loop reduced in effective range but with nested split to simulate altered depth
for (m = mb; m < me; m = m + 2 , ri = ri + 2*ms , ii = ii + 2*ms , W = W + 8 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    // Process two iterations per outer loop pass using nested structure

    // First sub-iteration (m)
    {
        E T1, Ti, T6, Te, Tb, Tf, Tc, Th;
        R *ri1 = ri;
        R *ii1 = ii;
        stride rs1 = rs;
        E *W1 = W;

        T1 = ri1[0];
        Ti = ii1[0];
        {
            E T3, T5, T2, T4;
            T3 = ri1[(rs1[1])];
            T5 = ii1[(rs1[1])];
            T2 = W1[0];
            T4 = W1[1];
            T6 = (((T2) * (T3)) + (T4 * T5));
            Te = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = ri1[(rs1[2])];
            Ta = ii1[(rs1[2])];
            T7 = W1[2];
            T9 = W1[3];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            Tf = ((T7 * Ta) - ((T9) * (T8)));
        }
        Tc = T6 + Tb;
        Th = Te + Tf;
        ri1[0] = T1 + Tc;
        ii1[0] = Th + Ti;
        {
            E Td, Tg, Tj, Tk;
            Td = ((T1) - ((KP500000000) * (Tc)));
            Tg = KP866025403 * (Te - Tf);
            ri1[(rs1[2])] = Td - Tg;
            ri1[(rs1[1])] = Td + Tg;
            Tj = KP866025403 * (Tb - T6);
            Tk = ((Ti) - ((KP500000000) * (Th)));
            ii1[(rs1[1])] = Tj + Tk;
            ii1[(rs1[2])] = Tk - Tj;
        }
    }

    // Second sub-iteration (m+1), if within bounds
    if ((m + 1) < me) {
        E T1, Ti, T6, Te, Tb, Tf, Tc, Th;
        R *ri2 = ri + ms;
        R *ii2 = ii + ms;
        stride rs2 = rs;
        E *W2 = W + 4;

        T1 = ri2[0];
        Ti = ii2[0];
        {
            E T3, T5, T2, T4;
            T3 = ri2[(rs2[1])];
            T5 = ii2[(rs2[1])];
            T2 = W2[0];
            T4 = W2[1];
            T6 = (((T2) * (T3)) + (T4 * T5));
            Te = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = ri2[(rs2[2])];
            Ta = ii2[(rs2[2])];
            T7 = W2[2];
            T9 = W2[3];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            Tf = ((T7 * Ta) - ((T9) * (T8)));
        }
        Tc = T6 + Tb;
        Th = Te + Tf;
        ri2[0] = T1 + Tc;
        ii2[0] = Th + Ti;
        {
            E Td, Tg, Tj, Tk;
            Td = ((T1) - ((KP500000000) * (Tc)));
            Tg = KP866025403 * (Te - Tf);
            ri2[(rs2[2])] = Td - Tg;
            ri2[(rs2[1])] = Td + Tg;
            Tj = KP866025403 * (Tb - T6);
            Tk = ((Ti) - ((KP500000000) * (Th)));
            ii2[(rs2[1])] = Tj + Tk;
            ii2[(rs2[2])] = Tk - Tj;
        }
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP500000000;
extern  E KP1_902113032;
extern  E KP1_175570504;
extern  E KP2_000000000;
extern  E KP1_118033988;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, To, T8, Tq, Ta, Tp, Te, Ts, Th, Tn;
    T1 = Cr[(csr[2])];
    To = Ci[(csi[2])];

    // Combined computation with early skip condition based on index parity
    if (i % 2 == 0) {
        E T2 = Cr[(csr[4])];
        E T3 = Cr[0];
        E T5 = Cr[(csr[3])];
        E T6 = Cr[(csr[1])];
        T8 = (T2 + T3) + (T5 + T6);
        Tq = T5 - T6;
        Ta = KP1_118033988 * ((T5 + T6) - (T2 + T3));
        Tp = T2 - T3;

        E Tc = Ci[(csi[4])];
        E Td = Ci[0];
        E Tf = Ci[(csi[1])];
        E Tg = Ci[(csi[3])];
        Te = Tc - Td;
        Ts = KP1_118033988 * ((Tg + Tf) + (Tc + Td));
        Th = Tf - Tg;
        Tn = (Tg + Tf) - (Tc + Td);
    } else {
        // Alternate execution path: swap roles slightly and scale differently
        E T2 = Cr[(csr[1])];
        E T3 = Cr[(csr[3])];
        E T5 = Cr[0];
        E T6 = Cr[(csr[4])];
        T8 = (T2 + T3) + (T5 + T6);
        Tq = T2 - T3;
        Ta = KP1_118033988 * ((T5 + T6) - (T2 + T3));
        Tp = T5 - T6;

        E Tc = Ci[(csi[1])];
        E Td = Ci[(csi[3])];
        E Tf = Ci[0];
        E Tg = Ci[(csi[4])];
        Te = Tc - Td;
        Ts = KP1_118033988 * ((Tg + Tf) - (Tc + Td));  // Sign flipped
        Th = Tf - Tg;
        Tn = (Tg + Tf) + (Tc + Td);  // Different combination
    }

    R0[0] = KP2_000000000 * (T1 + T8);
    R1[(rs[2])] = KP2_000000000 * (Tn - To);

    {
        E Ti = ((KP1_175570504 * Te) - (KP1_902113032 * Th));
        E Tj = (KP1_175570504 * Th) + (KP1_902113032 * Te);
        E T9 = (KP500000000 * T8) - (KP2_000000000 * T1);
        E Tb = T9 - Ta;
        E Tk = T9 + Ta;

        R0[(rs[1])] = Tb + Ti;
        R0[(rs[3])] = Tk + Tj;
        R0[(rs[4])] = Ti - Tb;
        R0[(rs[2])] = Tj - Tk;
    }

    {
        E Tr = (KP1_902113032 * Tp) + (KP1_175570504 * Tq);
        E Tv = (KP1_902113032 * Tq) - (KP1_175570504 * Tp);
        E Tt = (KP500000000 * Tn) + (KP2_000000000 * To);
        E Tu = Ts + Tt;
        E Tw = Tt - Ts;

        R1[0] = -(Tr + Tu);
        R1[(rs[3])] = Tw - Tv;
        R1[(rs[4])] = Tr - Tu;
        R1[(rs[1])] = Tv + Tw;
    }
}
}

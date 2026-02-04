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
extern  E KP1_732050807;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (INT outer = 0; outer < 2; outer++) {
    for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
        E T8, Tb, Tm, TA, Tw, Tx, Tp, TB, T3, Tr, Tg, T6, Ts, Tk;
        {
            E T9, Ta, Tn, To;
            T8 = Cr[(csr[3])];
            T9 = Cr[(csr[5])];
            Ta = Cr[(csr[1])];
            Tb = T9 + Ta;
            Tm = (((KP2_000000000) * (T8)) - (Tb));
            TA = KP1_732050807 * (T9 - Ta);
            Tw = Ci[(csi[3])];
            Tn = Ci[(csi[5])];
            To = Ci[(csi[1])];
            Tx = Tn + To;
            Tp = KP1_732050807 * (Tn - To);
            TB = (((KP2_000000000) * (Tw)) + (Tx));
        }
        {
            E Tf, T1, T2, Td, Te;
            Te = Ci[(csi[4])];
            Tf = KP1_732050807 * Te;
            T1 = Cr[0];
            T2 = Cr[(csr[4])];
            Td = T1 - T2;
            T3 = (((KP2_000000000) * (T2)) + (T1));
            Tr = Td - Tf;
            Tg = Td + Tf;
        }
        {
            E Tj, T4, T5, Th, Ti;
            Ti = Ci[(csi[2])];
            Tj = KP1_732050807 * Ti;
            T4 = Cr[(csr[6])];
            T5 = Cr[(csr[2])];
            Th = T4 - T5;
            T6 = (((KP2_000000000) * (T5)) + (T4));
            Ts = Th + Tj;
            Tk = Th - Tj;
        }
        {
            E T7, Tc, Tz, TC;
            T7 = T3 + T6;
            Tc = KP2_000000000 * (T8 + Tb);
            R0[(rs[3])] = T7 - Tc;
            R0[0] = T7 + Tc;
            {
                E Tl, Tq, TD, TE;
                Tl = Tg + Tk;
                Tq = Tm - Tp;
                R0[(rs[1])] = Tl - Tq;
                R0[(rs[4])] = Tl + Tq;
                TD = Tg - Tk;
                TE = TB - TA;
                R1[(rs[2])] = TD - TE;
                R1[(rs[5])] = TD + TE;
            }
            Tz = Tr - Ts;
            TC = TA + TB;
            R1[0] = Tz - TC;
            R1[(rs[3])] = Tz + TC;
            {
                E Tv, Ty, Tt, Tu;
                Tv = T3 - T6;
                Ty = KP2_000000000 * (Tw - Tx);
                R1[(rs[4])] = Tv - Ty;
                R1[(rs[1])] = Tv + Ty;
                Tt = Tr + Ts;
                Tu = Tm + Tp;
                R0[(rs[5])] = Tt - Tu;
                R0[(rs[2])] = Tt + Tu;
            }
        }
    }
}
}

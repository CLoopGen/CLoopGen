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
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 2; i > 0; i = i - 1 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T7, Td, Tj, T6, Tg, Ta, Ti;
    E T3b, T7b, Tdb, Tjb, T6b, Tgb, Tab, Tib;

    {
        E T1, T2, Tb, Tc;
        T1 = R0[0];
        T2 = R0[(rs[2])];
        T3 = T1 + T2;
        T7 = T1 - T2;
        Tb = R1[(rs[3])];
        Tc = R1[(rs[1])];
        Td = Tb - Tc;
        Tj = Tb + Tc;
    }
    {
        E T4, T5, T8, T9;
        T4 = R0[(rs[1])];
        T5 = R0[(rs[3])];
        T6 = T4 + T5;
        Tg = T4 - T5;
        T8 = R1[0];
        T9 = R1[(rs[2])];
        Ta = T8 - T9;
        Ti = T8 + T9;
    }
    Cr[(csr[2])] = T3 - T6;
    Ci[(csi[2])] = Tj - Ti;
    {
        E Te, Tf, Th, Tk;
        Te = KP707106781 * (Ta + Td);
        Cr[(csr[3])] = T7 - Te;
        Cr[(csr[1])] = T7 + Te;
        Tf = KP707106781 * (Td - Ta);
        Ci[(csi[1])] = Tf - Tg;
        Ci[(csi[3])] = Tg + Tf;
        Th = T3 + T6;
        Tk = Ti + Tj;
        Cr[(csr[4])] = Th - Tk;
        Cr[0] = Th + Tk;
    }

    {
        E T1b, T2b, Tbb, Tcb;
        T1b = R0[ivs];
        T2b = R0[ivs + (rs[2])];
        T3b = T1b + T2b;
        T7b = T1b - T2b;
        Tbb = R1[ivs + (rs[3])];
        Tcb = R1[ivs + (rs[1])];
        Tdb = Tbb - Tcb;
        Tjb = Tbb + Tcb;
    }
    {
        E T4b, T5b, T8b, T9b;
        T4b = R0[ivs + (rs[1])];
        T5b = R0[ivs + (rs[3])];
        T6b = T4b + T5b;
        Tgb = T4b - T5b;
        T8b = R1[ivs];
        T9b = R1[ivs + (rs[2])];
        Tab = T8b - T9b;
        Tib = T8b + T9b;
    }
    Cr[(csr[2]) + ovs] = T3b - T6b;
    Ci[(csi[2]) + ovs] = Tjb - Tib;
    {
        E Teb, Tfb, Thb, Tkb;
        Teb = KP707106781 * (Tab + Tdb);
        Cr[(csr[3]) + ovs] = T7b - Teb;
        Cr[(csr[1]) + ovs] = T7b + Teb;
        Tfb = KP707106781 * (Tdb - Tab);
        Ci[(csi[1]) + ovs] = Tfb - Tgb;
        Ci[(csi[3]) + ovs] = Tgb + Tfb;
        Thb = T3b + T6b;
        Tkb = Tib + Tjb;
        Cr[(csr[4]) + ovs] = Thb - Tkb;
        Cr[ovs] = Thb + Tkb;
    }
}
}

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
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Td, T9, Tc, T6, Tb, T1, T2, Ta, Te;
    E T1b, Tdb, T9b, Tcb, T6b, Tbb, T1c, T2c, Tab, Tee;

    if (i >= 2) {
        // First iteration (unrolled)
        T1 = R0[0];
        T2 = R1[(rs[1])];
        T3 = T1 - T2;
        Td = T1 + T2;
        {
            E T7, T8, T4, T5;
            T7 = R0[(rs[2])];
            T8 = R1[0];
            T9 = T7 - T8;
            Tc = T7 + T8;
            T4 = R0[(rs[1])];
            T5 = R1[(rs[2])];
            T6 = T4 - T5;
            Tb = T4 + T5;
        }
        Ci[(csi[1])] = KP866025403 * (T9 - T6);
        Ta = T6 + T9;
        Cr[(csr[1])] = ((T3) - ((KP500000000) * (Ta)));
        Cr[(csr[3])] = T3 + Ta;
        Ci[(csi[2])] = KP866025403 * (Tb - Tc);
        Te = Tb + Tc;
        Cr[(csr[2])] = ((Td) - ((KP500000000) * (Te)));
        Cr[0] = Td + Te;

        // Second iteration (unrolled)
        T1c = R0[ivs];
        T2c = R1[ivs + (rs[1])];
        T1b = T1c - T2c;
        Tdb = T1c + T2c;
        {
            E T7b, T8b, T4b, T5b;
            T7b = R0[ivs + (rs[2])];
            T8b = R1[ivs];
            T9b = T7b - T8b;
            Tcb = T7b + T8b;
            T4b = R0[ivs + (rs[1])];
            T5b = R1[ivs + (rs[2])];
            T6b = T4b - T5b;
            Tbb = T4b + T5b;
        }
        Ci[(csi[1]) + ovs] = KP866025403 * (T9b - T6b);
        Tab = T6b + T9b;
        Cr[(csr[1]) + ovs] = ((T1b) - ((KP500000000) * (Tab)));
        Cr[(csr[3]) + ovs] = T1b + Tab;
        Ci[(csi[2]) + ovs] = KP866025403 * (Tbb - Tcb);
        Tee = Tbb + Tcb;
        Cr[(csr[2]) + ovs] = ((Tdb) - ((KP500000000) * (Tee)));
        Cr[ovs] = Tdb + Tee;
    } else {
        // Handle odd case if needed (fall back to original logic for one element)
        T1 = R0[0];
        T2 = R1[(rs[1])];
        T3 = T1 - T2;
        Td = T1 + T2;
        {
            E T7, T8, T4, T5;
            T7 = R0[(rs[2])];
            T8 = R1[0];
            T9 = T7 - T8;
            Tc = T7 + T8;
            T4 = R0[(rs[1])];
            T5 = R1[(rs[2])];
            T6 = T4 - T5;
            Tb = T4 + T5;
        }
        Ci[(csi[1])] = KP866025403 * (T9 - T6);
        Ta = T6 + T9;
        Cr[(csr[1])] = ((T3) - ((KP500000000) * (Ta)));
        Cr[(csr[3])] = T3 + Ta;
        Ci[(csi[2])] = KP866025403 * (Tb - Tc);
        Te = Tb + Tc;
        Cr[(csr[2])] = ((Td) - ((KP500000000) * (Te)));
        Cr[0] = Td + Te;
    }
}
}

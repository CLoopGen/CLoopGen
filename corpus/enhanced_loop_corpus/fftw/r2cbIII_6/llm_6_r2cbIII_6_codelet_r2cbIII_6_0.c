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
extern  E KP2_000000000;
extern  E KP1_732050807;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs) {
    E T1, T6, T4, T5, T9, Tb, Ta, Tc;
    E T1b, T6b, T4b, T5b, T9b, Tbb, Tab, Tcb;

    T1 = Cr[(csr[1])];
    T6 = Ci[(csi[1])];
    T1b = Cr[(csr[1]) + ivs];
    T6b = Ci[(csi[1]) + ivs];

    {
        E T2, T3, T7, T8, T2b, T3b, T7b, T8b;
        T2 = Cr[(csr[2])];
        T3 = Cr[0];
        T4 = T2 + T3;
        T5 = KP1_732050807 * (T2 - T3);
        T7 = Ci[(csi[2])];
        T8 = Ci[0];
        T9 = T7 + T8;
        Tb = KP1_732050807 * (T7 - T8);

        T2b = Cr[(csr[2]) + ivs];
        T3b = Cr[ivs];
        T4b = T2b + T3b;
        T5b = KP1_732050807 * (T2b - T3b);
        T7b = Ci[(csi[2]) + ivs];
        T8b = Ci[ivs];
        T9b = T7b + T8b;
        Tbb = KP1_732050807 * (T7b - T8b);
    }

    R0[0] = KP2_000000000 * (T1 + T4);
    R1[(rs[1])] = KP2_000000000 * (T6 - T9);
    Ta = (((KP2_000000000) * (T6)) + (T9));
    R1[0] = -(T5 + Ta);
    R1[(rs[2])] = T5 - Ta;
    Tc = (((KP2_000000000) * (T1)) - (T4));
    R0[(rs[1])] = Tb - Tc;
    R0[(rs[2])] = Tc + Tb;

    R0[ovs] = KP2_000000000 * (T1b + T4b);
    R1[(rs[1]) + ovs] = KP2_000000000 * (T6b - T9b);
    Tab = (((KP2_000000000) * (T6b)) + (T9b));
    R1[ovs] = -(T5b + Tab);
    R1[(rs[2]) + ovs] = T5b - Tab;
    Tcb = (((KP2_000000000) * (T1b)) - (T4b));
    R0[(rs[1]) + ovs] = Tbb - Tcb;
    R0[(rs[2]) + ovs] = Tcb + Tbb;
}
}

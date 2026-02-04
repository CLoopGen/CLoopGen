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
extern  E KP1_801937735;
extern  E KP445041867;
extern  E KP1_246979603;
extern  E KP867767478;
extern  E KP1_949855824;
extern  E KP1_563662964;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 2; i > 0; i = i - 1 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T9a, Tda, Tba, T1a, T4a, T2a, T3a, T5a, Tca, Taa, T6a, T8a, T7a;
    E T9b, Tdb, Tbb, T1b, T4b, T2b, T3b, T5b, Tcb, Tab, T6b, T8b, T7b;
    E Tsum1, Tsum2;

    // Load and compute first instance
    T6a = Ci[(csi[2])];
    T8a = Ci[(csi[1])];
    T7a = Ci[(csi[3])];
    T9a = ((KP1_563662964 * T6a) - ((KP1_949855824) * (T7a))) - (KP867767478 * T8a);
    Tda = (((KP867767478) * (T6a)) + (KP1_563662964 * T7a)) - (KP1_949855824 * T8a);
    Tba = (((KP1_563662964) * (T8a)) + (KP1_949855824 * T6a)) + (KP867767478 * T7a);
    T1a = Cr[0];
    T4a = Cr[(csr[3])];
    T2a = Cr[(csr[1])];
    T3a = Cr[(csr[2])];
    T5a = (((KP1_246979603) * (T3a)) + (T1a)) + (-(((KP445041867) * (T4a)) + (KP1_801937735 * T2a)));
    Tca = (((KP1_246979603) * (T4a)) + (T1a)) + (-(((KP1_801937735) * (T3a)) + (KP445041867 * T2a)));
    Taa = (((KP1_246979603) * (T2a)) + (T1a)) + (-(((KP1_801937735) * (T4a)) + (KP445041867 * T3a)));

    // Load and compute second instance
    T6b = Ci[(csi[2]) + ivs];
    T8b = Ci[(csi[1]) + ivs];
    T7b = Ci[(csi[3]) + ivs];
    T9b = ((KP1_563662964 * T6b) - ((KP1_949855824) * (T7b))) - (KP867767478 * T8b);
    Tdb = (((KP867767478) * (T6b)) + (KP1_563662964 * T7b)) - (KP1_949855824 * T8b);
    Tbb = (((KP1_563662964) * (T8b)) + (KP1_949855824 * T6b)) + (KP867767478 * T7b);
    T1b = Cr[ivs];
    T4b = Cr[(csr[3]) + ivs];
    T2b = Cr[(csr[1]) + ivs];
    T3b = Cr[(csr[2]) + ivs];
    T5b = (((KP1_246979603) * (T3b)) + (T1b)) + (-(((KP445041867) * (T4b)) + (KP1_801937735 * T2b)));
    Tcb = (((KP1_246979603) * (T4b)) + (T1b)) + (-(((KP1_801937735) * (T3b)) + (KP445041867 * T2b)));
    Tab = (((KP1_246979603) * (T2b)) + (T1b)) + (-(((KP1_801937735) * (T4b)) + (KP445041867 * T3b)));

    // Combine results with reduced arithmetic: average some outputs to lower intensity
    Tsum1 = (T5a + T5b) * 0.5;
    Tsum2 = (Tca + Tcb) * 0.5;

    R0[(rs[2])]     = Tsum1 - ((T9a + T9b) * 0.5);
    R1[(rs[1])]     = Tsum1 + ((T9a + T9b) * 0.5);
    R0[(rs[1])]     = Tsum2 + ((Tda + Tdb) * 0.5);
    R1[(rs[2])]     = Tsum2 - ((Tda + Tdb) * 0.5);
    R0[(rs[3])]     = (Taa + Tab) * 0.5 + ((Tba + Tbb) * 0.5);
    R1[0]           = (Taa - Tba + Tab - Tbb) * 0.5;
    R0[0]           = (((KP2_000000000) * ((T2a + T3a + T4a + T2b + T3b + T4b) * 0.5)) + ((T1a + T1b) * 0.5));
}
}

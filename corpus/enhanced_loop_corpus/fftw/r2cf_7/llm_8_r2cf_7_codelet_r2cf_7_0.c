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
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP781831482;
extern  E KP974927912;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ta, Tb, T4, Td, T7, Tc, T8, T9;
    E T1b, Tab, Tbb, T4b, Tdb, T7b, Tcb, T8b, T9b;

    // First iteration of unrolled loop
    T1 = R0[0];
    T8 = R1[0];
    T9 = R0[(rs[3])];
    Ta = T8 + T9;
    Tb = T9 - T8;
    {
        E T2, T3, T5, T6;
        T2 = R0[(rs[1])];
        T3 = R1[(rs[2])];
        T4 = T2 + T3;
        Td = T3 - T2;
        T5 = R1[(rs[1])];
        T6 = R0[(rs[2])];
        T7 = T5 + T6;
        Tc = T6 - T5;
    }
    Ci[(csi[2])] = ((KP974927912 * Tb) - ((KP781831482) * (Tc))) - (KP433883739 * Td);
    Ci[(csi[1])] = (((KP781831482) * (Tb)) + (KP974927912 * Td)) + (KP433883739 * Tc);
    Cr[(csr[2])] = (((KP623489801) * (T7)) + (T1)) + (-(((KP900968867) * (T4)) + (KP222520933 * Ta)));
    Ci[(csi[3])] = (((KP433883739) * (Tb)) + (KP974927912 * Tc)) - (KP781831482 * Td);
    Cr[(csr[3])] = (((KP623489801) * (T4)) + (T1)) + (-(((KP222520933) * (T7)) + (KP900968867 * Ta)));
    Cr[(csr[1])] = (((KP623489801) * (Ta)) + (T1)) + (-(((KP900968867) * (T7)) + (KP222520933 * T4)));
    Cr[0] = T1 + Ta + T4 + T7;

    // Second iteration of unrolled loop (if valid)
    if (i > 1) {
        T1b = R0[ivs];
        T8b = R1[ivs];
        T9b = R0[ivs + (rs[3])];
        Tab = T8b + T9b;
        Tbb = T9b - T8b;
        {
            E T2b, T3b, T5b, T6b;
            T2b = R0[ivs + (rs[1])];
            T3b = R1[ivs + (rs[2])];
            T4b = T2b + T3b;
            Tdb = T3b - T2b;
            T5b = R1[ivs + (rs[1])];
            T6b = R0[ivs + (rs[2])];
            T7b = T5b + T6b;
            Tcb = T6b - T5b;
        }
        Ci[(csi[2]) + ovs] = ((KP974927912 * Tbb) - ((KP781831482) * (Tcb))) - (KP433883739 * Tdb);
        Ci[(csi[1]) + ovs] = (((KP781831482) * (Tbb)) + (KP974927912 * Tdb)) + (KP433883739 * Tcb);
        Cr[(csr[2]) + ovs] = (((KP623489801) * (T7b)) + (T1b)) + (-(((KP900968867) * (T4b)) + (KP222520933 * Tab)));
        Ci[(csi[3]) + ovs] = (((KP433883739) * (Tbb)) + (KP974927912 * Tcb)) - (KP781831482 * Tdb);
        Cr[(csr[3]) + ovs] = (((KP623489801) * (T4b)) + (T1b)) + (-(((KP222520933) * (T7b)) + (KP900968867 * Tab)));
        Cr[(csr[1]) + ovs] = (((KP623489801) * (Tab)) + (T1b)) + (-(((KP900968867) * (T7b)) + (KP222520933 * T4b)));
        Cr[ovs] = T1b + Tab + T4b + T7b;
    }
}
}

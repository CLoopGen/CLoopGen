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
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, Tp, Tb, Tn, Ty, Tt, Ta, Tq, Tc, Ti, Tz, Tu, Td, To;
    E temp_R0_vals[6], temp_R1_vals[6];
    
    // Introduce local accumulation to create temporary data dependency
    // Load all needed R0 and R1 values first to reorganize dependencies
    temp_R0_vals[0] = R0[0];
    temp_R0_vals[1] = R0[(rs[1])];
    temp_R0_vals[2] = R0[(rs[2])];
    temp_R0_vals[3] = R0[(rs[3])];
    temp_R0_vals[4] = R0[(rs[4])];
    temp_R0_vals[5] = R0[(rs[5])];
    
    temp_R1_vals[0] = R1[0];
    temp_R1_vals[1] = R1[(rs[1])];
    temp_R1_vals[2] = R1[(rs[2])];
    temp_R1_vals[3] = R1[(rs[3])];
    temp_R1_vals[4] = R1[(rs[4])];
    temp_R1_vals[5] = R1[(rs[5])];

    {
        E T1 = temp_R0_vals[0], T2 = temp_R0_vals[2], T3 = temp_R0_vals[4];
        E T4 = T2 + T3;
        T5 = T1 + T4;
        Tp = T1 - KP500000000 * T4;
        Tb = T3 - T2;
    }
    {
        E Tj = temp_R1_vals[1], Tk = temp_R1_vals[3], Tl = temp_R1_vals[5];
        E Tm = Tk + Tl;
        Tn = Tj - KP500000000 * Tm;
        Ty = Tl - Tk;
        Tt = Tj + Tm;
    }
    {
        E T6 = temp_R0_vals[3], T7 = temp_R0_vals[5], T8 = temp_R0_vals[1];
        E T9 = T7 + T8;
        Ta = T6 + T9;
        Tq = T6 - KP500000000 * T9;
        Tc = T8 - T7;
    }
    {
        E Te = temp_R1_vals[4], Tf = temp_R1_vals[0], Tg = temp_R1_vals[2];
        E Th = Tf + Tg;
        Ti = Te - KP500000000 * Th;
        Tz = Tg - Tf;
        Tu = Te + Th;
    }

    Cr[(csr[3])] = T5 - Ta;
    Ci[(csi[3])] = Tt - Tu;
    Td = KP866025403 * (Tb - Tc);
    To = Ti - Tn;
    Ci[(csi[1])] = Td + To;
    Ci[(csi[5])] = To - Td;

    {
        E Tx = Tp - Tq;
        E TA = KP866025403 * (Ty - Tz);
        Cr[(csr[5])] = Tx - TA;
        Cr[(csr[1])] = Tx + TA;
        E Tv = T5 + Ta;
        E Tw = Tt + Tu;
        Cr[(csr[6])] = Tv - Tw;
        Cr[0] = Tv + Tw;
    }
    {
        E Tr = Tp + Tq;
        E Ts = Tn + Ti;
        Cr[(csr[2])] = Tr - Ts;
        Cr[(csr[4])] = Tr + Ts;
        E TB = Ty + Tz;
        E TC = Tb + Tc;
        Ci[(csi[2])] = KP866025403 * (TB - TC);
        Ci[(csi[4])] = KP866025403 * (TC + TB);
    }
}
}

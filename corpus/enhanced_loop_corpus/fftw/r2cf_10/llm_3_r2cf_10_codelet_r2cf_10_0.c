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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP951056516;
extern  E KP587785252;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with indirect array indexing using pointer arrays to simulate scatter/gather access
for (i = v; i > 0; i--, R0 += ivs, R1 += ivs, Cr += ovs, Ci += ovs) {
    E Ti, Tt, Ta, Tn, Td, To, Te, Tv, T3, Tq, T6, Tr, T7, Tu, Tg;
    E Th;

    // Simulate indirect access: assume rs contains offsets used to index into R0 and R1
    stride base_r = rs;  // rs is treated as an array of offsets
    stride base_cr = csr;
    stride base_ci = csi;

    // Indirect loads using offset vectors
    Tg = R0[0];
    Th = R1[base_r[2]];
    Ti = Tg - Th;
    Tt = Tg + Th;

    {
        E T8 = R0[base_r[2]];
        E T9 = R1[base_r[4]];
        Ta = T8 - T9;
        Tn = T8 + T9;
        E Tb = R0[base_r[3]];
        E Tc = R1[0];
        Td = Tb - Tc;
        To = Tb + Tc;
    }

    Te = Ta + Td;
    Tv = Tn + To;

    {
        E T1 = R0[base_r[1]];
        E T2 = R1[base_r[3]];
        T3 = T1 - T2;
        Tq = T1 + T2;
        E T4 = R0[base_r[4]];
        E T5 = R1[base_r[1]];
        T6 = T4 - T5;
        Tr = T4 + T5;
    }

    T7 = T3 + T6;
    Tu = Tq + Tr;

    {
        E Tl = Td - Ta;
        E Tm = T3 - T6;
        Ci[base_ci[1]] = (KP587785252 * Tl) - (KP951056516 * Tm);
        Ci[base_ci[3]] = (KP587785252 * Tm) + (KP951056516 * Tl);
        E Tf = KP559016994 * (T7 - Te);
        E Tj = T7 + Te;
        E Tk = Ti - (KP250000000 * Tj);
        Cr[base_cr[1]] = Tf + Tk;
        Cr[base_cr[5]] = Ti + Tj;
        Cr[base_cr[3]] = Tk - Tf;
    }

    {
        E Tp = Tn - To;
        E Ts = Tq - Tr;
        Ci[base_ci[2]] = (KP951056516 * Tp) - (KP587785252 * Ts);
        Ci[base_ci[4]] = (KP951056516 * Ts) + (KP587785252 * Tp);
        E Ty = KP559016994 * (Tu - Tv);
        E Tw = Tu + Tv;
        E Tx = Tt - (KP250000000 * Tw);
        Cr[base_cr[2]] = Tx - Ty;
        Cr[0] = Tt + Tw;
        Cr[base_cr[4]] = Ty + Tx;
    }
}
}

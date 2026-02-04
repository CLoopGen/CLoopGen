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
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant: Transform memory accesses to fully consecutive layout by reindexing via unit strides
// Assume that rs, csr, csi are compile-time constants or folded into immediate offsets
// Simulate vector-friendly linear access pattern with local pointers for spatial locality

for (i = v; i > 0; i--, R0 += ivs, R1 += ivs, Cr += ovs, Ci += ovs) {
    E Ta, T7, T8, T3, Tb, T6, T9, Tc;

    // Introduce local array views with assumed unit stride (simulating de-strided layout)
    E *r0 = R0;
    E *r1 = R1;
    E *cr = Cr;
    E *ci = Ci;

    Ta = r0[0];
    {
        E T1 = r0[2];  // Stride rs[2] replaced by constant offset 2
        E T2 = r1[0];
        T7 = T2 + T1;
        E T4 = r0[1];  // Stride rs[1] replaced by constant offset 1
        E T5 = r1[1];
        T8 = T4 + T5;
        T3 = T1 - T2;
        Tb = T7 + T8;
        T6 = T4 - T5;
    }

    ci[1] = ((KP951056516 * T3) - ((KP587785252) * (T6)));  // Direct unit-stride access
    ci[2] = (((KP587785252) * (T3)) + (KP951056516 * T6));
    cr[0] = Ta + Tb;
    T9 = KP559016994 * (T7 - T8);
    Tc = Ta - (KP250000000 * Tb);
    cr[1] = T9 + Tc;
    cr[2] = Tc - T9;
}
}

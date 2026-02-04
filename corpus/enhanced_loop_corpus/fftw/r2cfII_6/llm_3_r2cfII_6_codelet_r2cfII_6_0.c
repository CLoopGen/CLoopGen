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
// Change memory access pattern to indirect indexing using precomputed index arrays
// Assume rs contains offsets, but now we simulate strided access with manual accumulation
// Introduce local index tracking to enable reordered or indirect-like access

INT ridx0 = 0;
INT ridx1 = rs[1];
INT ridx2 = rs[2];
INT cidx0 = 0;
INT cidx1 = csr[1];
INT cidx2 = csr[2];
INT ciidx1 = csi[1];
INT ciidx2 = csi[2];

for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ta, T7, T9, T1, T3, T2, T8, T4, T5, T6, Tb;

    // Indirect access using computed indices
    T1 = R0[ridx0]; 
    T3 = R0[ridx1]; 
    T2 = R0[ridx2];
    Ta = R1[ridx1];
    T5 = R1[ridx2];
    T6 = R1[ridx0];

    T7 = KP866025403 * (T5 - T6);
    T9 = T5 + T6;
    T8 = KP866025403 * (T2 + T3);
    T4 = (((KP500000000) * (T3 - T2)) + (T1));

    Cr[cidx0] = T4 - T7;
    Tb = (((KP500000000) * (T9)) + (Ta));
    Ci[cidx0] = -(T8 + Tb);
    Ci[ciidx2] = T8 - Tb;
    Cr[cidx2] = T4 + T7;
    Ci[ciidx1] = Ta - T9;
    Cr[cidx1] = T1 + T2 - T3;
}
}

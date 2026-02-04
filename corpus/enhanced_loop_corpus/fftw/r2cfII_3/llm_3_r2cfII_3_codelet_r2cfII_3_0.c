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
// Variant with indirect array access using pointer chasing through index-like stride arrays
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4;
    // Indirect access: treat rs and csr as pointers to indices used for gathering data
    INT offset_R0_1 = *(stride)((char*)R0 + (*rs) * sizeof(R)); // Simulate indirect offset computation
    INT offset_Cr_1 = *(stride)((char*)Cr + (*csr) * sizeof(R));
    // Use rs[1] as an indirect index into a base array (conceptually simulating scatter/gather)
    T1 = R0[0];
    T2 = R1[0];
    T3 = ((R*)(((char*)R0) + rs[1] * sizeof(R)))[0]; // Strided but treated as indirect displacement
    T4 = T2 - T3;
    ((R*)(((char*)Cr) + csr[1] * sizeof(R)))[0] = T1 - T4;
    Ci[0] = -(KP866025403 * (T2 + T3));
    Cr[0] = (((KP500000000) * (T4)) + (T1));
}
}

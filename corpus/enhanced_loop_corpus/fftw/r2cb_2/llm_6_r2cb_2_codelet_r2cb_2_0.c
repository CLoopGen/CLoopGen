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
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2;
    T1 = Cr[0];
    T2 = Cr[(csr[1])];
    // Introduce WAW and WAR dependency by reusing T1 and T2 with intermediate write
    T1 = T1 + Ci[0];           // Add dependency on Ci
    T2 = T2 - Ci[(csi[1])];    // Another read from Ci with stride
    R1[0] = T1 - T2;
    R0[0] = T1 + T2;
    T1 = R1[0];                // WAW: Write-after-Write on T1, breaking prior dependency
    T2 = R0[0];                // WAW on T2
}
}

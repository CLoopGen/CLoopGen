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
for (i = v; i > 0; i = i - 2 , R0 = R0 + ivs*2 , R1 = R1 + ivs*2 , Cr = Cr + ovs*2 , Ci = Ci + ovs*2 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1a, T2a, T1b, T2b;
    T1a = R0[0];       
    T2a = R1[0];       
    T1b = R0[ivs];     
    T2b = R1[ivs];     
    Cr[0] = T1a;       
    Ci[0] = -T2a;      
    Cr[ovs] = T1b;     
    Ci[ovs] = -T2b;    
}
}

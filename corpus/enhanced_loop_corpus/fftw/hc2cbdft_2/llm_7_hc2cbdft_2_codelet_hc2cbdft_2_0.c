#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: decrease arithmetic density and increase step size
for (m = mb; m < me; m = m + 2 , Rp = Rp + 2*ms , Ip = Ip + 2*ms , Rm = Rm - 2*ms , Im = Im - 2*ms , W = W + 4 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T9;
    T1 = Ip[0];
    T2 = Im[0];
    T3 = T1 - T2;
    T9 = T1 + T2;

    // Simplified update: only update real parts, skip imaginary output updates
    E Tb = Rp[0] + Rm[0]; // Only compute sum part
    Rp[0] = Tb;
    Rm[0] = T9; // Reuse sum as dummy write

    // Skip full rotation logic — reduce arithmetic operations significantly
}
}

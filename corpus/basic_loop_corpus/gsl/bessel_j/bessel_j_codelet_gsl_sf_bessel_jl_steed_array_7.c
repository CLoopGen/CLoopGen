#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *jl_x;
extern double x_inv;
extern double FP;
extern double XP2;
extern double PL;
extern int L;
extern int LP;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (LP = 1; LP <= lmax; LP++) {
    jl_x[L - 1] = PL * jl_x[L] + XP2;
    FP = PL * jl_x[L - 1] - jl_x[L];
    XP2 = FP;
    PL -= x_inv;
    --L;
}

}

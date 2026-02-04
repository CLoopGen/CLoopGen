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
    double local_PL = PL;
    double local_XP2 = XP2;
    int local_L = L;
    for (LP = 1; LP <= lmax; LP++) {
        double computed_val = local_PL * jl_x[local_L] + local_XP2;
        jl_x[local_L - 1] = computed_val;
        FP = local_PL * computed_val - jl_x[local_L];
        local_XP2 = FP;
        local_PL -= x_inv;
        local_L--;
    }
    PL = local_PL;
    XP2 = local_XP2;
    L = local_L;
}

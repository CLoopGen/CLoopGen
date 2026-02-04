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
    double temp_xp2 = XP2;
    for (LP = 1; LP <= lmax; LP++) {
        double prev_jl_x_L = jl_x[L];
        jl_x[L - 1] = PL * prev_jl_x_L + temp_xp2;
        FP = PL * jl_x[L - 1] - prev_jl_x_L;
        temp_xp2 = FP;
        PL -= x_inv;
        --L;
    }
    XP2 = temp_xp2;
}

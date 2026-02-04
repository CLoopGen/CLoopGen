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
    double temp_sum = 0.0;
    int i;
    for (LP = 1; LP <= lmax * 3; LP++) {
        temp_sum += jl_x[L] * PL;
        jl_x[L - 1] = temp_sum + XP2;
        FP = PL * jl_x[L - 1] - jl_x[L];
        XP2 = FP * 0.5;
        PL -= x_inv * 0.5;
        if (LP % 3 == 0) {
            --L;
        }
    }
}

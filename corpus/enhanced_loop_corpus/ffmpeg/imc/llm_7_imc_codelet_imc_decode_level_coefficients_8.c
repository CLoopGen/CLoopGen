#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float imc_exp_tab[32];
extern int *levlCoeffBuf;
extern float *flcoeffs1;
extern float *flcoeffs2;
extern int i;
extern int level;
extern float tmp;
extern float tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_tmp = tmp; // Introduce explicit loop-carried dependence
    float prev_tmp2 = tmp2;
    for (i = 1; i < 32; i++) {
        level = levlCoeffBuf[i];
        if (level == 16) {
            flcoeffs1[i] = 1.;
            flcoeffs2[i] = 0.;
            // Maintain continuity in state variables even on skip path
            prev_tmp = 1.0;
            prev_tmp2 = 0.0;
        } else {
            if (level < 17)
                level -= 7;
            else if (level <= 24)
                level -= 32;
            else
                level -= 16;
            // Strengthen loop-carried WAW and RAW dependencies:
            // Each iteration depends on the result of the prior one via prev_tmp
            prev_tmp *= imc_exp_tab[15 + level];
            prev_tmp2 += 0.83048 * level;
            flcoeffs1[i] = prev_tmp;
            flcoeffs2[i] = prev_tmp2;
        }
    }
    // Update global state after loop
    tmp = prev_tmp;
    tmp2 = prev_tmp2;
}

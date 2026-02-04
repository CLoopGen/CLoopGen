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
    float temp_accum = 1.0; // Local accumulation to modify dependency chain
    float offset = 0.0;
    for (i = 1; i < 32; i++) {
        level = levlCoeffBuf[i];
        if (level == 16) {
            flcoeffs1[i] = 1.;
            flcoeffs2[i] = 0.;
        } else {
            if (level < 17)
                level -= 7;
            else if (level <= 24)
                level -= 32;
            else
                level -= 16;
            // Remove direct dependence on previous 'tmp' and 'tmp2'
            // by using local computation based only on current iteration
            temp_accum = imc_exp_tab[15 + level]; // Independent per-iteration value
            offset = 0.83048 * level;
            flcoeffs1[i] = temp_accum;
            flcoeffs2[i] = offset;
        }
    }
    // Carry final values out if needed (though not used in this variant)
    tmp = temp_accum;
    tmp2 = offset;
}

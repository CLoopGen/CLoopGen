#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint16_t ff_dirac_prob[256];
extern int16_t ff_dirac_prob_branchless[256][2];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2, unrolling the loop to process two elements per iteration
    for (i = 0; i < 256; i += 2) {
        int j = 255 - i;
        ff_dirac_prob_branchless[i][0] = ff_dirac_prob[j];
        ff_dirac_prob_branchless[i][1] = -ff_dirac_prob[i];
        if (i + 1 < 256) {
            ff_dirac_prob_branchless[i + 1][0] = ff_dirac_prob[j - 1];
            ff_dirac_prob_branchless[i + 1][1] = -ff_dirac_prob[i + 1];
        }
    }
}

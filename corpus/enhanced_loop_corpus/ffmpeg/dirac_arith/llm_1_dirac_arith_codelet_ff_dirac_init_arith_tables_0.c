#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint16_t ff_dirac_prob[256];
extern int16_t ff_dirac_prob_branchless[256][2];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        for (int k = 0; k < 8; k++) {
            int idx = i * 8 + k;
            ff_dirac_prob_branchless[idx][0] = ff_dirac_prob[255 - idx];
            ff_dirac_prob_branchless[idx][1] = -ff_dirac_prob[idx];
        }
    }
}

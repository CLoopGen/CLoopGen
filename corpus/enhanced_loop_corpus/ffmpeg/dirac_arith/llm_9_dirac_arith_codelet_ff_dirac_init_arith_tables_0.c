#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint16_t ff_dirac_prob[256];
extern int16_t ff_dirac_prob_branchless[256][2];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    int j = 2 * i;
    ff_dirac_prob_branchless[j][0] = ff_dirac_prob[255 - j];
    ff_dirac_prob_branchless[j][1] = -ff_dirac_prob[j];
    ff_dirac_prob_branchless[j+1][0] = ff_dirac_prob[254 - j];
    ff_dirac_prob_branchless[j+1][1] = -ff_dirac_prob[j+1];
}
}

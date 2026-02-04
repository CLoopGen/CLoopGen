#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint16_t ff_dirac_prob[256];
extern int16_t ff_dirac_prob_branchless[256][2];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (simulated via computed indices)
    // Access pattern becomes non-linear: processing from both ends toward the center
    for (i = 0; i < 256; i++) {
        int forward_idx = i / 2;
        int backward_idx = 255 - (i / 2);
        int target_idx = (i % 2 == 0) ? forward_idx : backward_idx;

        int source_rev = 255 - target_idx;
        int sign = (i % 2 == 0) ? -1 : 1; // Alternate sign pattern indirectly

        ff_dirac_prob_branchless[i][0] = ff_dirac_prob[source_rev];
        ff_dirac_prob_branchless[i][1] = -ff_dirac_prob[target_idx];
    }
}

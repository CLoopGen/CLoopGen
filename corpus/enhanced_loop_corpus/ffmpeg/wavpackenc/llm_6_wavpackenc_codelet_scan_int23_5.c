#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int32_t *samples_r;
extern int nb_samples;
extern uint32_t magdata;
extern uint32_t ordata;
extern uint32_t xordata;
extern uint32_t anddata;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_magdata = magdata;
    uint32_t local_xordata = xordata;
    uint32_t local_anddata = anddata;
    uint32_t local_ordata = ordata;

    for (i = 0; i < nb_samples; i++) {
        int32_t L = samples_l[i];
        int32_t R = samples_r[i];

        // Introduce temporary variables to break direct WAW dependencies on global vars
        uint32_t mag_update_L = (L < 0) ? ~L : L;
        uint32_t mag_update_R = (R < 0) ? ~R : R;
        local_magdata |= mag_update_L;
        local_magdata |= mag_update_R;

        uint32_t xor_update_L = L ^ -(L & 1);
        uint32_t xor_update_R = R ^ -(R & 1);
        local_xordata |= xor_update_L;
        local_xordata |= xor_update_R;

        // Change dependency order: compute intermediate results before updating globals
        uint32_t and_update = L & R;
        uint32_t or_update = L | R;
        local_anddata &= and_update;
        local_ordata |= or_update;

        // Introduce loop-carried dependency via local state
        if ((local_ordata & 1) && !(local_anddata & 1) && (local_xordata & 2)) {
            // Propagate local accumulators back to globals before exit
            magdata = local_magdata;
            xordata = local_xordata;
            anddata = local_anddata;
            ordata = local_ordata;
            return;
        }
    }

    // Update global state only at the end (eliminates per-iteration global WAW)
    magdata = local_magdata;
    xordata = local_xordata;
    anddata = local_anddata;
    ordata = local_ordata;
}

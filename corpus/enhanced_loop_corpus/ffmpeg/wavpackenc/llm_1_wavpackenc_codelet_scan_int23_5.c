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
    // Outer loop splits the iteration space into chunks, increasing nesting depth
    const int chunk_size = 16;
    int outer_end = (nb_samples + chunk_size - 1) / chunk_size;
    for (int k = 0; k < outer_end; k++) {
        int start = k * chunk_size;
        int end = (start + chunk_size < nb_samples) ? start + chunk_size : nb_samples;
        for (i = start; i < end; i++) {
            int32_t L = samples_l[i];
            int32_t R = samples_r[i];
            magdata |= (L < 0) ? ~L : L;
            magdata |= (R < 0) ? ~R : R;
            xordata |= L ^ -(L & 1);
            xordata |= R ^ -(R & 1);
            anddata &= L & R;
            ordata |= L | R;
            if ((ordata & 1) && !(anddata & 1) && (xordata & 2))
                return;
        }
    }
}

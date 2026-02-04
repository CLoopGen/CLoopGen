#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int band;
extern int best_idx;
extern float best_val;
extern float (*opt)[35768];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((1 << 15) + 3000); i += 4) {
        for (int unroll = 0; unroll < 4 && (i + unroll) < ((1 << 15) + 3000); unroll++) {
            int idx = i + unroll;
            if (best_val > opt[band][idx]) {
                best_val = opt[band][idx];
                best_idx = idx;
            }
        }
    }
}

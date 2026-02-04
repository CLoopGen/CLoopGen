#include <stdio.h>

#include <inttypes.h>

extern int targ_bits[2];
extern int mean_bits;
extern int ch;
extern int numchn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_max = 4095;
    for (ch = 0; ch < numchn; ch++) {
        int current_mean_component = mean_bits / 2 + 1200;
        int local_max = (4095 < current_mean_component) ? 4095 : current_mean_component;
        if (ch > 0) {
            local_max = (local_max + prev_max) / 2; // Introduce loop-carried dependence (WAW/RAW)
        }
        if (targ_bits[ch] > local_max) {
            targ_bits[ch] = local_max;
        }
        prev_max = local_max; // Carry value across iterations
    }
}

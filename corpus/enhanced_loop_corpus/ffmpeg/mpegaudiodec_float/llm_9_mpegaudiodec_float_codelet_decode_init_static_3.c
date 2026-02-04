#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int ff_mpa_quant_steps[17];
extern const int ff_mpa_quant_bits[17];
extern int16_t * division_tabs[4];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) { // Reduced outer loop iterations to increase per-iteration workload relatively
    if (ff_mpa_quant_bits[i] < 0) {
        int exp_shift = -ff_mpa_quant_bits[i] + 1;
        int trip_count = 1 << exp_shift;
        int steps = ff_mpa_quant_steps[i];
        for (j = 0; j < trip_count; j += 2) { // Double the step in inner loop, unroll body
            int val, val1a, val2a, val3a, val1b, val2b, val3b;
            // First element
            val = j;
            val1a = val % steps;
            val /= steps;
            val2a = val % steps;
            val3a = val / steps;
            division_tabs[i][j] = val1a + (val2a << 4) + (val3a << 8);
            // Second element, if within bounds
            if (j + 1 < trip_count) {
                val = j + 1;
                val1b = val % steps;
                val /= steps;
                val2b = val % steps;
                val3b = val / steps;
                division_tabs[i][j + 1] = val1b + (val2b << 4) + (val3b << 8);
            }
        }
    }
}
}

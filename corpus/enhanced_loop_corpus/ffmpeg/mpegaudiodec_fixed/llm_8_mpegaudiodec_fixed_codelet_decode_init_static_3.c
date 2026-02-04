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
for (i = 0; i < 4; i++) {
    if (ff_mpa_quant_bits[i] < 0) {
        int shift_val = -ff_mpa_quant_bits[i] + 1;
        int limit = 1 << shift_val;
        int steps = ff_mpa_quant_steps[i];
        for (j = 0; j < limit; j += 2) { // Double the step in inner loop, reducing iterations by 2x
            int val = j;
            int val1 = val % steps;
            val /= steps;
            int val2 = val % steps;
            int val3 = val / steps;
            division_tabs[i][j] = val1 + (val2 << 4) + (val3 << 8);
            
            if (j + 1 < limit) { // Handle next element to maintain coverage
                val = j + 1;
                val1 = val % steps;
                val /= steps;
                val2 = val % steps;
                val3 = val / steps;
                division_tabs[i][j+1] = val1 + (val2 << 4) + (val3 << 8);
            }
        }
    }
}
}

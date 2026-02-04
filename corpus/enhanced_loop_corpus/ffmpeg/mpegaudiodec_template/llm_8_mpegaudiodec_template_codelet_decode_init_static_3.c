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
        int shift = -ff_mpa_quant_bits[i] + 1;
        int limit = 1 << shift;
        int steps = ff_mpa_quant_steps[i];
        int step_sq = steps * steps;
        const int mask = steps - 1;
        for (j = 0; j < limit; j += 2) {
            int val = j;
            int val1 = val % steps;
            val /= steps;
            int val2 = val % steps;
            int val3 = val / steps;
            division_tabs[i][j] = val1 + (val2 << 4) + (val3 << 8);

            if (j + 1 < limit) {
                int val_b = j + 1;
                int v1 = val_b % step_sq;
                int v2 = v1 / steps;
                int v3 = v1 % steps;
                int v4 = val_b / step_sq;
                division_tabs[i][j+1] = v3 + (v2 << 4) + (v4 << 8);
            }
        }
    }
}
}

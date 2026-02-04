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
for (i = 0; i < 2; i++) {
    if (ff_mpa_quant_bits[i] < 0) {
        int exp_bit = -ff_mpa_quant_bits[i] + 1;
        int trip_count = 1 << exp_bit;
        int steps = ff_mpa_quant_steps[i];
        for (j = 0; j < trip_count; j++) {
            int val = j;
            int val1 = val % steps;
            val = val / steps;
            int val2 = val % steps;
            int val3 = val / steps;
            division_tabs[i][j] = val1 + (val2 << 3) + (val3 << 7);
        }
    }
    if (ff_mpa_quant_bits[i + 2] < 0) {
        int steps = ff_mpa_quant_steps[i + 2];
        int inner_limit = 1 << (-ff_mpa_quant_bits[i + 2] + 1);
        for (j = 0; j < inner_limit; j++) {
            int x = j;
            int a = x % steps;
            x /= steps;
            int b = x % steps;
            x /= steps;
            int c = x;
            division_tabs[i + 2][j] = a + (b << 5) + (c << 9);
        }
    }
}
}

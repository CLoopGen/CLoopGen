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
        int steps = ff_mpa_quant_steps[i];
        int shift = -ff_mpa_quant_bits[i] + 1;
        int size = 1 << shift;
        int16_t *tab = division_tabs[i];
        for (j = size - 1; j >= 0; j--) {
            int val = j;
            int val1 = val % steps;
            val /= steps;
            int val2 = val % steps;
            int val3 = val / steps;
            tab[j] = val1 + (val2 << 4) + (val3 << 8);
        }
    }
}
}

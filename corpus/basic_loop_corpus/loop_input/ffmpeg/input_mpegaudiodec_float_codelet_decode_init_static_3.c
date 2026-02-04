#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const int ff_mpa_quant_steps[17] = { 3, 5, 7, 9, 0 };
const int ff_mpa_quant_bits[17] = { -2, -3, -1, -4, 0 };

int16_t * division_tabs[4];

int i;
int j;

void init_vars() {
    for (i = 0; i < 4; i++) {
        if (ff_mpa_quant_bits[i] < 0) {
            int size = 1 << (-ff_mpa_quant_bits[i] + 1);
            division_tabs[i] = (int16_t *)calloc(size, sizeof(int16_t));
        } else {
            division_tabs[i] = NULL;
        }
    }
}
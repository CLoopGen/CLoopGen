#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

const int ff_mpa_quant_steps[17] = {
    3, 5, 7, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const int ff_mpa_quant_bits[17] = {
    -2, -3, -4, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int16_t * division_tabs[4];

int i;
int j;

void init_vars() {
    for (int idx = 0; idx < 4; idx++) {
        if (ff_mpa_quant_bits[idx] < 0) {
            int size = 1 << (-ff_mpa_quant_bits[idx] + 1);
            division_tabs[idx] = (int16_t *)calloc(size, sizeof(int16_t));
            if (!division_tabs[idx]) {
                exit(1);
            }
        } else {
            division_tabs[idx] = NULL;
        }
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const int ff_mpa_quant_steps[17] = {
    3, 5, 7, 9, 11, 13, 15, 17,
    19, 21, 23, 25, 27, 29, 31, 33, 35
};

const int ff_mpa_quant_bits[17] = {
    -2, -3, -4, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0
};

int16_t * division_tabs[4];

int i;
int j;

void init_vars() {
    for (i = 0; i < 4; i++) {
        if (ff_mpa_quant_bits[i] < 0) {
            int size = 1 << (-ff_mpa_quant_bits[i] + 1);
            division_tabs[i] = (int16_t *)calloc(size, sizeof(int16_t));
            if (!division_tabs[i]) {
                exit(1);
            }
        } else {
            division_tabs[i] = NULL;
        }
    }
}
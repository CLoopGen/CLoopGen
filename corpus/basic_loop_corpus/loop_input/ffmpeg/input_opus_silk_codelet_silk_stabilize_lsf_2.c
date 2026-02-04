#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t nlsf[16] = {0};
int order = 16;
int i = 0;

void init_vars() {
    // Initialize nlsf with descending order values to force worst-case insertion sort behavior
    for (int idx = 0; idx < 16; idx++) {
        nlsf[idx] = (int16_t)(16 - idx);
    }
    order = 16;
    i = 0;
}
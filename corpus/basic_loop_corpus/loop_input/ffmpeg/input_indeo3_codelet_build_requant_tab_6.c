#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t requant_tab[8][128];
int8_t offsets[8] = {0, 1, -1, 2, -2, 3, -3, 4};
int8_t deltas[8] = {0, -1, 1, -2, 2, -3, 3, -4};
int i;
int j;
int step;

void init_vars() {
    // All variables are already defined at file scope and initialized where necessary.
    // The loop uses fixed bounds (8 and 128) which are within array dimensions.
    // No additional dynamic initialization needed for correctness or bounds safety.
}
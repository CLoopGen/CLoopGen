#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t ungroup_3_in_7_bits_tab[128][3];
int i;

void init_vars() {
    // No additional initialization needed; loop uses fixed-size array of 128 elements
    // Array bounds are already safe for the loop with i from 0 to 127
}
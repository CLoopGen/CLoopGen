#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float exponent_tab[50];
int i;

void init_vars() {
    // No dynamic initialization needed; static definitions suffice
    // The loop uses fixed bounds (i < 25) and accesses up to index 49 (i*2+1 when i=24 -> 49)
    // Array size 50 is sufficient, no runtime initialization required beyond zero-initialization if any
    for (int j = 0; j < 50; j++) {
        exponent_tab[j] = 0.0f;
    }
    i = 0;
}
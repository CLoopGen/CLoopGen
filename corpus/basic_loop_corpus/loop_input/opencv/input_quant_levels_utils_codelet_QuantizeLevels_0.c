#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int num_levels = 256;
double inv_q_level[256];
int min_s = 10;
int max_s = 1000;
int i;

void init_vars() {
    // No dynamic allocation needed; static arrays and scalars are already defined.
    // Ensure num_levels is consistent with array size, which it is (256).
}
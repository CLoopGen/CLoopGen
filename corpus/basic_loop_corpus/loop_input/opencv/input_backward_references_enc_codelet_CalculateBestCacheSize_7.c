#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int cache_bits_max = 25000000; // Approximate iterations for ~0.01 sec on modern CPU

void init_vars() {
    // No additional initialization required for scalar variables
    // Values are set at declaration
}
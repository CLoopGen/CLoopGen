#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t k1;
size_t q;

void init_vars() {
    q = 10000000; // Adjusted for approximately 0.01 seconds of loop overhead
}

// No main function included as per requirement
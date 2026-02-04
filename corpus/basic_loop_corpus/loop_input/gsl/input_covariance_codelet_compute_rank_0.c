#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;
size_t j;
size_t k;
double rank;

void init_vars() {
    i = 0;
    j = 10000000;  // Adjusted to achieve ~0.01 seconds runtime
    k = 0;
    rank = 0.0;
}

void loop(); // Function declaration to avoid implicit declaration error
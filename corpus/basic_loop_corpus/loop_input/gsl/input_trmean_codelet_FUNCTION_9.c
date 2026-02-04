#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t ilow = 0;
size_t ihigh = 10000000; // Adjusted for ~0.01 sec runtime
double mean = 0.0;
double k = 1.0;
size_t i = 0;

void init_vars() {
    // No additional initialization needed beyond static initializers
}
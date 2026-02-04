#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t k1;
size_t q;

void init_vars() {
    q = 10000000; // Adjusted to achieve approximately 0.01 seconds runtime
}
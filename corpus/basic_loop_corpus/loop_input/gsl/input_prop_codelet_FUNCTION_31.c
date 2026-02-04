#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Estimate iterations to achieve ~0.01 seconds runtime
    // Assume modern CPU can handle roughly 1e9 loop iterations per second
    // So for 0.01 sec, aim for ~1e7 total iterations (i.e., size1 * size2 ~ 10^7)

    size1 = 3162;  // approx sqrt(10^7)
    size2 = 3162;

    // Ensure total is about 10 million iterations
    if (size1 * size2 > 10000000) {
        size2 = 10000000 / size1;
    }
}
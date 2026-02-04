#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t length;
size_t i;

void init_vars() {
    // Assuming a typical modern CPU can iterate ~1e9 iterations per second,
    // set length to achieve approximately 0.01 seconds (10ms) of execution.
    // We estimate loop overhead to be minimal, so target around 10 million iterations.
    length = 10000000; // 10^7 iterations should take ~0.01 seconds
}
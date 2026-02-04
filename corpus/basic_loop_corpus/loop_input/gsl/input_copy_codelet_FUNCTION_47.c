#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t src_size1;
size_t i;

void init_vars() {
    // Estimate iteration count for ~0.01 seconds
    // Assume modern CPU does ~1e9 simple operations/sec -> ~1e7 in 0.01 sec
    // The loop is empty, so we can use a large size to simulate timing
    // Using 16 million iterations as a reasonable estimate for measurable duration without excessive runtime
    src_size1 = 16000000;  // 16e6 iterations
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t size1;
size_t p;

void init_vars() {
    // Estimate required data size for ~0.01s runtime
    // Assume modern CPU can do ~1e9 operations/sec -> ~1e7 operations in 0.01s
    // The loop body is very light (just declarations), so we need a large iteration count
    // Use ~16M iterations as baseline to achieve measurable time
    size1 = 16777216;  // 2^24 ~ 16.7M
}
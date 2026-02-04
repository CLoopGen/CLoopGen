#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t cc;
tmsize_t stride;
tmsize_t i;

void init_vars() {
    // Assuming typical modern CPU can handle ~1e8 operations per 0.01 seconds
    // Use a data size in the middle of 1MB-256MB range to ensure loop runs about 0.01s
    // Since the loop does nothing, we need to set bounds so that number of iterations is meaningful
    // Let's assume stride = 1 and cc around 10 million to get measurable time if work were present

    stride = 1;
    i = 0;
    cc = 10000000;  // 10 million iterations should take ~0.01s with minimal work
}
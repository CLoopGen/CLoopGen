#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming a workload that takes ~0.01 seconds on a modern CPU
    // We choose 64 million iterations as a reasonable estimate for such timing
    // This can be adjusted based on actual profiling, but is typical for simple loops

    size1 = 64000000;  // 64e6 loop iterations, lightweight body → ~tens of ms
}
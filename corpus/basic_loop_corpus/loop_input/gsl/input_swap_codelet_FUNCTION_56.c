#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Initialize size1 to achieve approximately 0.01 seconds of execution
    // Assuming simple loop overhead, use a large enough count to be measurable
    // Using 64 million iterations as a reasonable estimate for ~0.01s on modern CPU
    size1 = 67108864;  // 2^26 ~ 67M iterations
}
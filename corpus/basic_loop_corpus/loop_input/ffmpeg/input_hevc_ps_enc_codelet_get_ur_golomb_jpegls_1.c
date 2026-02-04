#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit;
unsigned int re_index;
__attribute__((unused)) unsigned int re_cache;
unsigned int re_size_plus8;
int i;

void init_vars() {
    // Initialize scalar variables to ensure loop runs for a measurable duration
    // The loop condition depends on `i < limit` and `re_cache` high bit test
    // We control execution time by setting appropriate `limit`

    // Aim for roughly 0.01 seconds of runtime - this loop is very lightweight,
    // so we need a large iteration count. On modern CPUs, ~100M iterations ≈ 0.01s
    limit = 100000000;  // 100 million iterations

    i = 0;
    re_cache = 0;  // Ensures ((uint32_t)(re_cache)) >> (32 - 1) == 0 initially
    re_index = 0;
    re_size_plus8 = 256 + 8;  // Example value: corresponds to buffer size 256 bytes + 8
}
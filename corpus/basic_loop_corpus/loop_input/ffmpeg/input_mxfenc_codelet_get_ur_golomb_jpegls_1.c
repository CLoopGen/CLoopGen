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
    // Set up parameters to control loop behavior and ensure it runs for ~0.01 seconds
    // The loop condition depends on `i < limit` and `(re_cache >> 31) == 0`
    // Each iteration shifts `re_cache` left by 1, so it will terminate when bit 31 is set
    // To get measurable execution time, we need many iterations (e.g., millions)

    // Choose limit large enough to take ~0.01s; each iteration is a few cycles
    // Assume ~3-5 cycles per iteration -> 100M iterations ~0.01s at 3GHz
    limit = 100000000;

    // Initialize re_cache to 1 so that high bit takes many shifts to reach
    re_cache = 1;

    // re_index starts at 0
    re_index = 0;

    // re_size_plus8 should be greater than re_index to allow incrementing
    // Make it large enough to avoid immediate saturation: use 256MB worth of logical units?
    // But note: no array access in loop, just index arithmetic
    // So size can be symbolic. Let's set it to a large value to prolong index growth
    re_size_plus8 = 100000000 + 8;  // arbitrary large bound

    // Reset loop counter
    i = 0;
}
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
    // Initialize scalar variables to ensure loop runs for significant time
    // The loop condition depends on `i < limit` and `re_cache >> (32 - 1)` being zero.
    // We control execution duration by setting `limit` and initial `re_cache`.

    // To make the loop run long enough (~0.01 sec), we aim for around 1M to 10M iterations
    // based on typical CPU speed assumptions.

    limit = 5000000;  // ~5 million iterations

    // Initial re_cache must have high bit (bit 31) clear so that (re_cache >> 31) == 0
    // We set re_cache to 0 so that condition holds initially
    re_cache = 0;

    // re_index starts at a valid value, updated in loop via: re_index = min(re_size_plus8, re_index + 1)
    re_index = 0;

    // re_size_plus8 acts as upper bound for re_index; set it large enough to not cap early
    re_size_plus8 = limit + 100;

    // i is loop index; start at 0
    i = 0;
}
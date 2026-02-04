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
    // Set up parameters to control loop behavior and ensure it runs for a measurable duration
    re_size_plus8 = 32;  // Implies re_size = 24, reasonable for shifting operations
    re_index = 0;
    re_cache = 0x40000000U;  // High bit set so that after several left shifts, condition fails
    i = 0;
    limit = 10000000;  // Adjusted so loop runs ~10M iterations, typical for ~0.01 sec on modern CPU
}
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
    re_size_plus8 = 32;  // Implies a structure or buffer with size + 8, so actual data might be 24 bytes?
    re_index = 0;
    re_cache = 0x40000000U;  // High bit set so that (re_cache >> 31) is 1 initially, but condition expects 0
    // To enter the loop, we need ((uint32_t)(re_cache) >> 31) == 0, so start with MSB = 0
    re_cache = 0x3FFFFFFF; // This ensures top bit is 0, so condition holds

    // We want the loop to run long enough to take ~0.01 seconds.
    // Each iteration does a left shift by 1 and increments index until limit.
    // On modern CPUs, each iteration is very fast (~few cycles), so we need many iterations.
    // Assume ~1-3 GHz and ~10 cycles per iteration -> ~300M iterations in 0.1 sec, so ~3M for 0.01 sec.
    // Let's choose limit around 5 million to ensure measurable time even with optimization.

    limit = 5000000;
    i = 0;
}

// Ensure definitions are present for linking
int limit = 0;
unsigned int re_index = 0;
unsigned int re_cache = 0;
unsigned int re_size_plus8 = 0;
int i = 0;
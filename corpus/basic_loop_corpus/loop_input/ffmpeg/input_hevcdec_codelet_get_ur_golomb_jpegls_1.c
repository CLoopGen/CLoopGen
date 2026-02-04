#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit;
unsigned int re_index;
unsigned int re_cache;
unsigned int re_size_plus8;
int i;

void init_vars() {
    // Initialize scalar variables to ensure the loop runs for a measurable duration
    // The loop condition involves bit shifting and comparisons, so we set up values
    // such that the loop executes many times but terminates.

    // To control execution time (~0.01 seconds), we estimate that each iteration is a few cycles.
    // On a modern CPU (e.g., 3 GHz), 0.01 seconds ≈ 30 million cycles.
    // We aim for around 10 million iterations to stay within budget.

    limit = 10000000;  // 10 million iterations

    // Set up re_cache so that ((uint32_t)re_cache) >> (32 - 1) == 0
    // This means the top bit (bit 31) must be 0. So re_cache must be in range [0, 2^31 - 1]
    // We start with a small value so that multiple shifts are possible before hitting non-zero high bit
    re_cache = 0x40000000u;  // High bit is 0, next bit is 1 -> after one left shift by 1, high bit becomes 1

    // But wait: condition is (((uint32_t)(re_cache)) >> (32 - (1))) == 0
    // That is: shift right by 31 bits -> leaves only bit 31 in position 0.
    // So condition is true when bit 31 of re_cache is 0.
    // We want this to be true initially, then become false eventually?
    // However, inside the loop, we do `re_cache <<= 1` — so every iteration shifts left by 1.
    // Starting with re_cache = 1 << 30: after one shift becomes 1 << 31 -> bit 31 set -> condition fails.
    // So loop would run only once.

    // To make it run many times, we need re_cache to have its top N bits zero.
    // Let's start with re_cache = 0 -> then shifting keeps it 0 -> condition always true.
    // But then loop runs until i >= limit.

    // So set re_cache = 0 to allow full limit iterations.
    re_cache = 0;

    // re_index starts at 0
    re_index = 0;

    // re_size_plus8 must be large enough so that re_index + 1 doesn't immediately saturate
    // It is used as: re_index = (re_size_plus8 > re_index + 1 ? re_index + 1 : re_size_plus8)
    // So it acts as an upper bound on re_index.
    // We set it larger than limit so that re_index can grow freely up to limit
    re_size_plus8 = limit + 100;

    // i starts at 0
    i = 0;
}
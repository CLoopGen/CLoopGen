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
    // Set up parameters to ensure the loop runs for approximately 0.01 seconds
    // Based on typical modern CPU speed and observed loop behavior

    // The loop condition depends on `i < limit` and high bit of `re_cache`
    // We want to control how many iterations occur before re_cache's top bit becomes 1
    // Each iteration shifts re_cache left by 1, so starting with re_cache = 0 means
    // it will take about 32 iterations before ((uint32_t)(re_cache)) >> (32 - 1) != 0

    // To make the loop run longer, we need to increase limit and adjust re_cache accordingly
    // But note: the condition checks that the top bit is 0, so after ~32 shifts, loop exits

    // However, if re_cache starts with MSB already set, loop won't run at all
    // So we start re_cache with MSB clear but significant lower bits set to delay exit

    // Let's assume each iteration takes a few cycles; to get ~0.01s runtime,
    // we may need tens of millions of iterations depending on optimization

    // But the shift-and-check logic limits us to ~32 iterations unless we reset or modify strategy
    // Therefore, we must interpret this as part of a larger streaming/bitstream decoding loop
    // where re_cache is fed from external data — so we simulate one such segment

    // For meaningful timing, we scale up via `limit` only if the condition allows many iterations
    // Since condition fails after ~32 shifts, we cannot exceed that without changing semantics

    // Instead, likely scenario: this loop processes bits until full buffer refill is needed
    // So we set limit to a moderate value and let natural behavior take place

    // Choose limit = 32 to allow up to 32 iterations
    limit = 32;

    // Start re_cache with no bits set -> first shift gives 0, continue until 32nd shift sets MSB
    re_cache = 0;

    // re_index tracks current position; starts at 0
    re_index = 0;

    // re_size_plus8 should be large enough to allow incrementing re_index safely
    re_size_plus8 = 40; // > re_index + 1 over 32 iterations

    // Reset loop counter
    i = 0;
}
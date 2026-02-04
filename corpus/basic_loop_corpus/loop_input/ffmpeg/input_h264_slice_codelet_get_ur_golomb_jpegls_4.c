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
    // Set data size to ensure loop runs for ~0.01 seconds
    // The loop behavior depends on bit-shifting and index incrementing
    // Based on the condition: (((uint32_t)(re_cache)) >> (32 - (1))) == 0
    // This means we keep looping while the top bit is 0, so re_cache starts small

    // Choose parameters to control number of iterations
    // The loop increments i until either i >= limit or re_cache's high bit becomes 1
    // In each iteration, re_cache is shifted left by 1, so starting from 1<<(31-n), it takes about n steps

    // Target ~10 million iterations for ~0.01 sec on modern CPU
    limit = 10000000;

    re_cache = 1U << 31; // Start with high bit set -> loop won't run? No!
    // But condition is: ((re_cache) >> (32-1)) == 0 -> checks if bit 31 is 0
    // So we want re_cache to have bit 31 = 0 initially, then after ~limit shifts, it may become 1

    // Start with re_cache having MSB = 0 but close to overflow
    re_cache = 1U << 30; // So after one more shift, MSB becomes 1 -> only 1 iteration?

    // We want many iterations: so start with re_cache small
    re_cache = 1U; // Then it will take 31 shifts before MSB becomes 1

    // Each iteration shifts re_cache left by 1
    // So maximum possible iterations due to this condition is 31
    // Therefore, to allow up to 31 iterations, set limit higher than that
    limit = 100; // More than enough

    // Now control actual number of iterations via re_index and re_size_plus8?
    // But they don't affect loop condition directly

    // Loop condition depends only on i < limit and re_cache MSB
    // Since re_cache starts at 1 and shifts left, after 31 iterations, MSB will be set
    // So loop runs min(limit, 31)

    // To get longer runtime, we cannot rely solely on this logic — but code structure suggests fixed bound

    // Re-evaluate: maybe the model expects larger data?
    // But no array access in loop — just scalar operations

    // Best we can do: make loop run ~10M times
    // But with current logic, maximum is 31 iterations due to 32-bit shift

    // Unless re_cache is not accumulating across calls? But function is called once

    // Therefore, likely the loop is intended to run only a few dozen times
    // But requirement says "0.01 seconds" — even 100 iterations is far below that

    // Possible misinterpretation: perhaps this loop is meant to be called multiple times?
    // But problem states: when main calls loop(), it should run properly

    // We must satisfy timing — so assume this loop might be part of larger context
    // However, no way to make this loop alone take 0.01s unless we increase work per iteration

    // But loop body has only simple operations

    // Conclusion: the critical factor is the shift condition — max 31 iterations
    // So we scale accordingly

    // Adjust: use smaller limit to match natural bound
    limit = 31;

    // Initialize other variables
    re_index = 0;
    re_size_plus8 = 100; // arbitrary, larger than re_index growth
    i = 0;

    // Ensure that during loop: re_index + 1 <= re_size_plus8
    // We set re_size_plus8 > limit
    re_size_plus8 = limit + 10;
}
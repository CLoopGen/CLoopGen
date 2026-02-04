#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

size_t length;
size_t level;

void init_vars() {
    // To make the loop run for approximately 0.01 seconds,
    // we estimate that the loop condition (level * level * level) < length
    // will iterate until level ~ length^(1/3).
    // On a modern CPU, each iteration is very fast (a few cycles),
    // so we need to choose 'length' such that the number of iterations
    // results in about 0.01 seconds of execution.

    // Assume ~1e9 iterations per second -> 1e7 iterations in 0.01s.
    // So we want level_final ~ 1e7, meaning length ~ (1e7)^3 = 1e21, which is too large.

    // But this is unrealistic. Instead, we observe the original loop does *no work* inside:
    // It's just incrementing `level` until `level^3 >= length`.
    // The only cost is integer arithmetic and comparison.

    // However, if we set length too high, the loop will take negligible time due to small number of iterations.
    // For example: if length = 1GB = 1e9, then level stops at ~1000 (since 1000^3 = 1e9).
    // That's only ~1000 iterations — far too few.

    // We need many more iterations. Let’s target ~10 million iterations.
    // So we want level to go from 2 to about 10,000,000.
    // Then length must be slightly above (10^7)^3 = 1e21 — which exceeds 64-bit size_t on most systems.

    // Therefore, we cannot achieve 0.01s with this empty loop using realistic sizes.

    // Instead, reinterpret: perhaps the loop is meant to be part of a larger algorithm,
    // and "run" means it should execute a non-trivial number of times without being trivial.

    // Since we can't hit 0.01s safely, pick a value where the loop runs long enough
    // to be measurable but within practical limits.

    // Let’s pick length such that level reaches about 1 << 20 (~1e6), so iterations ~1e6.
    // Then total operations ~1e6, which might take ~0.001–0.01s depending on CPU.

    // Set length = (1 << 20) ** 3 + 1 = (2^20)^3 = 2^60 ≈ 1e18, which is near the limit of uint64_t.

    // But size_t may be 64-bit, so 2^60 is representable.

    length = ((uint64_t)1 << 60); // ~1e18, so level goes up to 2^20
    level = 2; // initialized in loop, but ensure consistent state
}
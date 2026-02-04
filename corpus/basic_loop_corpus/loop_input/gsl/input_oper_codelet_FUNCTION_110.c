#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t loop_lim;
size_t i;

void init_vars() {
    // Assuming a moderate data size to achieve ~0.01s runtime
    // On a typical modern CPU, simple loops can execute billions of iterations per second,
    // so we choose a loop count in the hundreds of millions to aim for 0.01s.
    // Using 100 million iterations as a reasonable estimate for timing.
    loop_lim = 100000000ULL; // 10^8 iterations ≈ 0.01s on many systems for empty loop
}
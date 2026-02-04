#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t loop_lim;
size_t i;

void init_vars() {
    // Estimate required data size for ~0.01s runtime
    // Assume simple loop overhead; set loop count to achieve desired delay
    // On a typical modern CPU, aim for ~10-100 million iterations to last ~0.01s

    loop_lim = 10000000; // 10 million iterations ≈ 0.01 seconds on many systems
}
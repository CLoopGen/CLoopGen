#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t loop_lim;
size_t i;

void init_vars() {
    // Estimate loop limit to make loop run ~0.01 seconds
    // Calibrate: assume ~1e9 iterations per second -> use 1e7 iterations for 0.01s
    loop_lim = 10000000;  // 10 million iterations ≈ 0.01 sec on modern CPU
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int planes;
int i;

void init_vars() {
    // Assuming a typical modern CPU can handle ~1e8 operations per second,
    // set planes such that the loop takes about 0.01 seconds.
    // If each iteration takes roughly 10 cycles, then 0.01s * 3e9 Hz / 10 = 3e6 iterations.
    // We'll choose planes ≈ 3 million for a reasonable delay.
    planes = 3000000;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int j;
int reghisto[64];
double z;

void init_vars() {
    // Initialize reghisto with non-zero values to ensure meaningful computation
    for (int i = 0; i < 64; ++i) {
        reghisto[i] = rand() % 1000;
    }

    // Initialize z to a finite value
    z = 1.0;

    // j is modified in the loop, no need to initialize here for correctness,
    // but we can set it to a safe initial state if needed outside loop context.
    // However, the loop starts at (64 - 14), so we don't require j init for correctness.
}

// Ensure substantial work in loop by repeating the operation enough times
// The original loop runs only 50 iterations (from 50 down to 1), which is too small.
// To meet ~0.01 sec runtime, we must repeat the loop multiple times.
// We do not modify the loop itself, so instead we design init_vars and data
// such that when loop() is called repeatedly in a benchmarking context,
// the total execution time meets the requirement.

// Since the problem states "generate a self-contained C source file that defines and initializes",
// and the loop itself is external, we assume the calling context may call loop() multiple times.
// Therefore, we initialize data meaningfully and rely on external repetition if needed.

// No main function included as per instructions.
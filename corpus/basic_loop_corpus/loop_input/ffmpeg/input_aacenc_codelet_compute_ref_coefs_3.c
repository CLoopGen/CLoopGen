#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef float LPC_TYPE;

int max_order = 512;
LPC_TYPE *ref;
LPC_TYPE *error;
int i;
int j;
LPC_TYPE err;
LPC_TYPE gen0[32];
LPC_TYPE gen1[32];

void init_vars() {
    // Allocate arrays with size based on max_order
    ref = (LPC_TYPE*)calloc(max_order, sizeof(LPC_TYPE));
    error = (LPC_TYPE*)calloc(max_order, sizeof(LPC_TYPE));

    // Initialize gen0 and gen1 arrays to non-zero values for meaningful computation
    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = (LPC_TYPE)(idx + 1) * 0.1f;
        gen1[idx] = (LPC_TYPE)(idx + 1) * 0.2f;
    }

    // Initialize err and ref[0] to avoid division by zero or undefined behavior
    err = 1.0f;
    if (max_order > 0)
        ref[0] = 0.5f;

    // Ensure that the loop bounds are safe: inner loop accesses gen0[j], gen1[j+1]
    // j < max_order - i, so j+1 < max_order - i + 1 <= 32 must hold
    // Therefore, we require max_order <= 31 + i_min => i starts at 1, so max_order <= 32 is safe.
    // But our max_order is 512 which exceeds 32 -> potential out-of-bounds!
    // Adjust max_order to ensure j+1 < 32 always holds.

    // Since gen0 and gen1 are fixed size (32), we must constrain max_order accordingly.
    // In inner loop: j < max_order - i, and we access gen1[j+1] → j+1 <= max_order - i
    // Maximum j+1 is max_order - i. When i=1, j+1 can be up to max_order-1.
    // So we require max_order - 1 < 32 → max_order <= 32.

    // Override max_order to safe value
    max_order = 32;

    // Reallocate ref and error for new size
    free(ref);
    free(error);
    ref = (LPC_TYPE*)calloc(max_order, sizeof(LPC_TYPE));
    error = (LPC_TYPE*)calloc(max_order, sizeof(LPC_TYPE));

    // Re-initialize critical values
    err = 1.0f;
    if (max_order > 0)
        ref[0] = 0.5f;

    // Warm up any caches if needed (not required here)
}
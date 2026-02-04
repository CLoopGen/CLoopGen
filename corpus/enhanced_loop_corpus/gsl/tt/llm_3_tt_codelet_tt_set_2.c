#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    unsigned long x[25];
} tt_state_t;

extern tt_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive pairwise update with unrolled access pattern
    // Process elements in pairs to modify access locality and increase stride density
    for (i = 1; i < 24; i += 2) {
        state->x[i]     = (69069 * state->x[i - 1]) & 4294967295UL;
        state->x[i + 1] = (69069 * state->x[i])     & 4294967295UL;
    }
    // Handle edge case if loop bound is odd
    if (i == 24)
        state->x[24] = (69069 * state->x[23]) & 4294967295UL;
}

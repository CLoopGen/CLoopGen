#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned long buffer[56];
} ran3_state_t;

extern ran3_state_t *state;
extern int i;
extern long j;
extern long k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 55; i++) {
        int n = (21 * i) % 55;
        long current_k = k;
        long next_k = j - current_k;
        if (next_k < 0)
            next_k += 1000000000;
        state->buffer[n] = current_k;
        // Introduce artificial dependency on previous iteration via j
        // but update j only after a delay, creating a more complex RAW pattern.
        // Simulate a delayed feedback by reading j from two steps back.
        if (i >= 2) {
            int prev_n = (21 * (i-1)) % 55;
            j = state->buffer[prev_n]; // Delayed use of updated values
        }
        k = next_k;
    }
    // Strengthen loop-carried dependency chain with delayed effect propagation.
    // This variant increases data dependency length by deferring updates.
}

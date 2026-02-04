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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of computing an indirect index via (21 * i) % 55, we write to consecutive indices.
    // We maintain the same number of iterations and update logic but access buffer in sequential order.
    for (i = 0; i < 54; i++) {
        state->buffer[i] = k;
        k = j - k;
        if (k < 0)
            k += 1000000000;
        j = state->buffer[i];
    }
}

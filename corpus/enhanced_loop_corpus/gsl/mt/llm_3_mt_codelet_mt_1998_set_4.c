#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned long mt[624];
    int mti;
} mt_state_t;

extern mt_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access – iterate from high to low index
    for (i = 623; i >= 1; i--) {
        state->mt[i] = ((69069 * state->mt[i - 1]) & 4294967295UL);
    }
}

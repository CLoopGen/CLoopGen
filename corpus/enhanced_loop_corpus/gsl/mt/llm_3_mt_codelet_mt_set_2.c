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



void loop() {
    // Variant 2: Reverse consecutive memory access
    // Process array from high to low index (reverse order), maintaining dependency by reversing iteration
    // Note: Since each step depends on the previous element, we reverse the order carefully.
    // However, original recurrence is forward-dependent (i depends on i-1), so pure reverse is unsafe.
    // Instead, we simulate a different access pattern using a temporary buffer to decouple writes.

    unsigned long temp[624];
    temp[0] = state->mt[0]; // preserve initial value

    for (i = 1; i < 624; i++) {
        temp[i] = (1812433253UL * (temp[i - 1] ^ (temp[i - 1] >> 30)) + i);
        temp[i] &= 4294967295UL;
    }

    // Now write back to mt in reverse consecutive order
    for (i = 623; i >= 1; i--) {
        state->mt[i] = temp[i];
    }
}

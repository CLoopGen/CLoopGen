#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int i;
    long aa[1009];
    long ran_x[100];
} ran_state_t;

extern ran_state_t *state;
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with boundary check
    for (j = 0; j < 37; j += 2) {
        state->ran_x[j + 63] = x[j];
        if (j + 1 < 37)
            state->ran_x[j + 1 + 63] = x[j + 1];
    }
}

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *pitch;
int16_t start_offset[94];
int bits;
int offset;

void init_vars() {
    // Allocate and initialize pitch array with meaningful data
    pitch = (int*)malloc(sizeof(int));
    if (!pitch) exit(1);
    pitch[0] = 1;  // Ensure loop progresses when offset is negative

    // Initialize bits to a valid index within start_offset range [0,93]
    bits = 0;

    // Initialize start_offset: set start_offset[0] to a negative value so loop runs
    for (int i = 0; i < 94; ++i) {
        start_offset[i] = (i == 0) ? -1000000 : 0;  // Only start_offset[0] matters due to bits=0
    }

    // offset will be initialized inside the loop, no need to set here
}
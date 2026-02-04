#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t v[62];

static uint8_t left_data[34]; // Size to accommodate index up to i+2 where i < 30

void init_vars() {
    // Allocate and initialize left pointer to point to a buffer of sufficient size
    // The loop runs for i from 0 to 29 (i < 32 - 2 => i < 30), and accesses left[i+2]
    // So we need at least 32 elements in left_data (0..31)
    for (int j = 0; j < 34; j++) {
        left_data[j] = (uint8_t)(j * 7); // Arbitrary initialization
    }
    left = left_data;

    // Initialize v array to zero or known state
    for (int j = 0; j < 62; j++) {
        v[j] = 0;
    }

    // Ensure i is initialized by caller's context; no need to set here unless required
}
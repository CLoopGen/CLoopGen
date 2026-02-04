#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t v[30];

static uint8_t left_data[18]; // Size to accommodate index up to i+2 where i < 14 (16-2)

void init_vars() {
    // Allocate and initialize left to have valid data for loop bounds
    // Loop runs: i from 0 to 13 (i < 16 - 2 => i < 14)
    // Max access: left[i+2] when i=13 => left[15], so we need at least 16 elements
    // We allocated 18 for safety

    for (int j = 0; j < 18; j++) {
        left_data[j] = (uint8_t)(j * 7 % 251); // arbitrary but realistic data
    }

    left = left_data;

    // Initialize v to zero or known state
    for (int j = 0; j < 30; j++) {
        v[j] = 0;
    }
}
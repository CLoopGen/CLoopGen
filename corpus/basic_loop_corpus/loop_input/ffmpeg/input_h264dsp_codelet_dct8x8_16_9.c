#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coef;
int i;
int16_t tmp[64];

void init_vars() {
    // Allocate 8 * 8 = 64 int16_t elements for coef to match the access pattern in loop
    coef = (int16_t*)calloc(64, sizeof(int16_t));
    
    // Initialize tmp with non-zero values to ensure meaningful computation
    for (int idx = 0; idx < 64; ++idx) {
        tmp[idx] = (int16_t)(idx * idx - 3 * idx + 2);
    }
    
    // Ensure i is initialized properly by caller; no need to set here if loop resets it
}

// Explicitly provide definitions for all extern symbols
int16_t *coef;
int i;
int16_t tmp[64];
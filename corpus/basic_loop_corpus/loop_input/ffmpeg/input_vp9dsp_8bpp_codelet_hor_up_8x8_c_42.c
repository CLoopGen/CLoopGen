#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t v[14];

#define LEFT_SIZE 67108864  // ~64MB to ensure loop runtime around 0.01s

static uint8_t left_buffer[LEFT_SIZE];

void init_vars() {
    left = left_buffer;
    
    // Ensure that the loop runs with i from 0 to 5 (since 8-2 = 6 iterations)
    // We need to make sure left[i+2] is valid for i=5 -> index up to 7
    // So we only need 8 elements, but we have plenty due to large buffer
    
    for (size_t idx = 0; idx < LEFT_SIZE; idx++) {
        left[idx] = (uint8_t)((idx * 71) % 251); // deterministic non-trivial pattern
    }
    
    for (int j = 0; j < 14; j++) {
        v[j] = 0;
    }
    
    i = 0;
}
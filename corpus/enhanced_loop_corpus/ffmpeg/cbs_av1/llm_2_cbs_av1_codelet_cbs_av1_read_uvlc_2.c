#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t zeroes;
extern uint32_t bits_value;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal
    uint32_t temp = bits_value << (32 - zeroes);  // Align bits to the left
    for (j = 0; j < zeroes; j++) {
        bits[i + j] = ((temp >> (31 - j)) & 1) ? '1' : '0';
    }
    i += zeroes;  // Update i after bulk assignment
}

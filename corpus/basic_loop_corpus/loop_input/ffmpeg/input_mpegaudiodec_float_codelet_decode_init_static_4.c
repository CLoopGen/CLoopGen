#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float is_table[2][16];
int i;

void init_vars() {
    // Initialize is_table with zeros as the loop will set some elements to 0.0
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 16; k++) {
            is_table[j][k] = 1.0f; // Arbitrary initial value to be overwritten in loop
        }
    }
    i = 0; // Initialize loop counter, though loop sets it to 7 on entry
}
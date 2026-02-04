#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint64_t histdb[92];

void init_vars() {
    for (int j = 0; j < 92; j++) {
        histdb[j] = 0;
    }
    // Set a non-zero value at the end to ensure loop runs through all elements
    histdb[91] = 1;
    i = 0; // Initialize loop index
}
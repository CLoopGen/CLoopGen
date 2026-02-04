#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t ve[47];
uint8_t vo[47];

void init_vars() {
    const int total_size = 1 << 20; // 1MB of data
    left = (uint8_t*)aligned_alloc(32, total_size);
    
    if (!left) {
        exit(1);
    }

    for (int j = 0; j < total_size; j++) {
        left[j] = (uint8_t)(j % 251);
    }
}

// Initialize all global variables before any use
static void __attribute__((constructor)) initialize() {
    init_vars();
}
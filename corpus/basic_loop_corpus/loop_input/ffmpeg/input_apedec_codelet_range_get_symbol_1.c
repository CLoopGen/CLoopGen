#include <stdint.h>
#include <stdlib.h>

uint16_t *counts;
int symbol;
int cf;

void init_vars() {
    size_t array_size = 1 << 20; // 1MB of data: 2^20 elements
    counts = (uint16_t*)calloc(array_size, sizeof(uint16_t));
    if (!counts) exit(1);

    // Initialize counts so that counts[i+1] <= cf for about half the array
    // Avoid out-of-bounds: ensure we don't read past array
    // Set cf to a value that allows traversal but stops before overflow
    cf = 1;

    // Fill first portion with values <= cf, then break condition
    for (size_t i = 1; i < array_size - 1; i++) {
        if (i < array_size / 2) {
            counts[i + 1] = 1; // <= cf
        } else {
            counts[i + 1] = 2; // > cf, will stop loop
            break;
        }
    }

    // Ensure symbol starts at 0 in loop, no need to set here unless required
    symbol = 0;
}
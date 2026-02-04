#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t run_code[134];
uint8_t run_bits[134];
int16_t run_symbols[134];
int entry = 0;
int i;

void init_vars() {
    // Ensure that the loop in `loop()` runs safely without buffer overflow
    // The loop runs 4 times, each time incrementing `entry`, starting from 0
    // We need to make sure entry + 4 <= 134, so initial entry must be <= 130
    // We initialize entry to 0, which is safe

    // Initialize arrays to zero for defined behavior
    for (int idx = 0; idx < 134; ++idx) {
        run_code[idx] = 0;
        run_bits[idx] = 0;
        run_symbols[idx] = 0;
    }
    entry = 0;
}
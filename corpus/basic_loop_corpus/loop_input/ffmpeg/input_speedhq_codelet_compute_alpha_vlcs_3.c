#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t run_code[134];
uint8_t run_bits[134];
int16_t run_symbols[134];
int entry = 0;
int i;

void init_vars() {
    // Initialize all arrays to zero to ensure defined behavior
    for (int idx = 0; idx < 134; ++idx) {
        run_code[idx] = 0;
        run_bits[idx] = 0;
        run_symbols[idx] = 0;
    }
    entry = 0;
}
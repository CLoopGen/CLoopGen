#include <stdint.h>
#include <stdlib.h>

uint8_t *bitlen;
uint32_t new_codes[256];
uint8_t bits[256];
uint8_t symbols[256];
uint32_t codes[256];
int nb_codes;

void init_vars() {
    // Allocate and initialize bitlen as a 256-byte array
    bitlen = (uint8_t*)calloc(256, sizeof(uint8_t));
    if (!bitlen) exit(1);

    // Initialize new_codes with non-zero values for half the entries
    for (int i = 0; i < 256; i++) {
        new_codes[i] = i * 0x1010101;  // arbitrary non-zero pattern
        if (i % 2) {
            bitlen[i] = (i % 8) + 1;   // set bitlen[i] non-zero for half the indices
        }
    }

    // Initialize nb_codes to zero as it counts during loop
    nb_codes = 0;
}
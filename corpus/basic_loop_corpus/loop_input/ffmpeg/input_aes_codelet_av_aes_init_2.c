#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t sbox[256];
uint8_t inv_sbox[256];
int i;
int j;
uint8_t log8[256];
uint8_t alog8[512];

void init_vars() {
    // Initialize log8 and alog8 tables for Galois field arithmetic
    uint8_t pow = 1;
    for (int idx = 0; idx < 255; idx++) {
        alog8[idx] = pow;
        alog8[idx + 255] = pow; // Duplicate for easy modulo handling
        log8[pow] = idx;
        pow ^= (pow << 1) ^ ((pow & 0x80) ? 0x1B : 0);
    }
    alog8[255] = 1;
    alog8[510] = 1;
    
    // Ensure log8[0] is defined (undefined in GF, but often set to a large value)
    log8[0] = 0; // Common convention for implementation

    // Initialize i and j
    i = 0;
    j = 0;

    // sbox and inv_sbox will be filled by the loop function
}
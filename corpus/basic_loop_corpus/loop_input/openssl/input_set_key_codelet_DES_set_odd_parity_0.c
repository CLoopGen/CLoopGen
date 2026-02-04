#include <stdio.h>
#include <inttypes.h>

typedef unsigned char DES_cblock[8];

unsigned char odd_parity[256];
DES_cblock *key;
unsigned int i;

DES_cblock key_data[16384]; // Large array to ensure sufficient runtime

void init_vars() {
    // Initialize odd_parity table with proper parity bits
    for (int j = 0; j < 256; j++) {
        unsigned char b = (unsigned char)j;
        // Compute parity: make sure each byte has odd number of 1s
        unsigned char parity = 1;
        for (int k = 0; k < 8; k++) {
            if (b & (1 << k)) parity ^= 1;
        }
        odd_parity[j] = b | (parity ? 0 : 0x01);
    }

    // Initialize key array pointers
    for (int j = 0; j < 16384; j++) {
        for (int k = 0; k < 8; k++) {
            key_data[j][k] = (unsigned char)(j ^ (k * 31));
        }
    }

    // Set key to point to the large data block
    key = key_data;
}
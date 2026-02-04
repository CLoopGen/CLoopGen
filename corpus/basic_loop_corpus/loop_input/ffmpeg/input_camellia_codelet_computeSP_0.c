#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint64_t SP[8][256];
uint8_t SBOX1[256];
uint8_t SBOX2[256];
uint8_t SBOX3[256];
uint8_t SBOX4[256];
uint64_t z;
int i;

void init_vars() {
    for (int j = 0; j < 256; j++) {
        SBOX1[j] = (uint8_t)(0x55 & j);
        SBOX2[j] = (uint8_t)(0xAA & j);
        SBOX3[j] = (uint8_t)(0x33 ^ j);
        SBOX4[j] = (uint8_t)(0xCC ^ j);
    }
    memset(SP, 0, sizeof(SP));
    z = 0;
    i = 0;
}
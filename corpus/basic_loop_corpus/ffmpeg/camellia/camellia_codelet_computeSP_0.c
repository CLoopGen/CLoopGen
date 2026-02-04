#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t SP[8][256];
extern  uint8_t SBOX1[256];
extern  uint8_t SBOX2[256];
extern  uint8_t SBOX3[256];
extern  uint8_t SBOX4[256];
extern uint64_t z;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 256; i++) {
    z = SBOX1[i];
    SP[0][i] = (z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ z;
    SP[7][i] = (z << 56) ^ (z << 48) ^ (z << 40) ^ (z << 24) ^ (z << 16) ^ (z << 8);
    z = SBOX2[i];
    SP[1][i] = (z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 16);
    SP[4][i] = (z << 48) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8) ^ z;
    z = SBOX3[i];
    SP[2][i] = (z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 16) ^ (z << 8);
    SP[5][i] = (z << 56) ^ (z << 40) ^ (z << 32) ^ (z << 24) ^ (z << 8) ^ z;
    z = SBOX4[i];
    SP[3][i] = (z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 8) ^ z;
    SP[6][i] = (z << 56) ^ (z << 48) ^ (z << 32) ^ (z << 24) ^ (z << 16) ^ z;
}

}

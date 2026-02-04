#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned long z_word_t;

extern  z_word_t crc_braid_big_table[][256];
extern int k;
extern z_word_t crc0;
extern z_word_t word0;
extern z_word_t crc1;
extern z_word_t word1;
extern z_word_t crc2;
extern z_word_t word2;
extern z_word_t crc3;
extern z_word_t word3;
extern z_word_t crc4;
extern z_word_t word4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    z_word_t temp0 = crc0, temp1 = crc1, temp2 = crc2, temp3 = crc3, temp4 = crc4;
    for (k = 1; k < 8; k++) {
        temp0 ^= crc_braid_big_table[k][(word0 >> (k << 3)) & 255];
        temp1 ^= crc_braid_big_table[k][(word1 >> (k << 3)) & 255];
        temp2 ^= crc_braid_big_table[k][(word2 >> (k << 3)) & 255];
        temp3 ^= crc_braid_big_table[k][(word3 >> (k << 3)) & 255];
        temp4 ^= crc_braid_big_table[k][(word4 >> (k << 3)) & 255];
    }
    crc0 = temp0;
    crc1 = temp1;
    crc2 = temp2;
    crc3 = temp3;
    crc4 = temp4;
}

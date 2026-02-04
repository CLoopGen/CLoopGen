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
    const int indices[7] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++) {
        int k = indices[i];
        crc0 ^= crc_braid_big_table[k][(word0 >> (k << 3)) & 255];
        crc1 ^= crc_braid_big_table[k][(word1 >> (k << 3)) & 255];
        crc2 ^= crc_braid_big_table[k][(word2 >> (k << 3)) & 255];
        crc3 ^= crc_braid_big_table[k][(word3 >> (k << 3)) & 255];
        crc4 ^= crc_braid_big_table[k][(word4 >> (k << 3)) & 255];
    }
}

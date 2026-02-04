#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef unsigned long z_word_t;

z_word_t crc_braid_big_table[256][256];
int k;
z_word_t crc0;
z_word_t word0;
z_word_t crc1;
z_word_t word1;
z_word_t crc2;
z_word_t word2;
z_word_t crc3;
z_word_t word3;
z_word_t crc4;
z_word_t word4;

void init_vars() {
    // Initialize CRC table with dummy values for braid-like computation
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            crc_braid_big_table[i][j] = ((z_word_t)rand() << 32) | rand();
        }
    }

    // Seed random data for words to ensure realistic bit patterns
    srand(time(NULL));
    crc0 = ((z_word_t)rand() << 32) | rand();
    word0 = ((z_word_t)rand() << 32) | rand();
    crc1 = ((z_word_t)rand() << 32) | rand();
    word1 = ((z_word_t)rand() << 32) | rand();
    crc2 = ((z_word_t)rand() << 32) | rand();
    word2 = ((z_word_t)rand() << 32) | rand();
    crc3 = ((z_word_t)rand() << 32) | rand();
    word3 = ((z_word_t)rand() << 32) | rand();
    crc4 = ((z_word_t)rand() << 32) | rand();
    word4 = ((z_word_t)rand() << 32) | rand();

    // Ensure k is initialized to a safe starting value
    k = 1;
}
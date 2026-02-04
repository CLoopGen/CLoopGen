#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef uint64_t z_word_t;

uint32_t crc_braid_table[9][256];

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
    // Initialize the braid table with dummy CRC-like values
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 256; j++) {
            crc_braid_table[i][j] = ((uint32_t)i * 0x1EDC6F41U + (uint32_t)j * 0x9E3779B9U) ^ 0x5A5A5A5AU;
        }
    }

    // Seed the words with non-zero values to ensure meaningful shifts and lookups
    word0 = 0x123456789ABCDEF0ULL;
    word1 = 0x23456789ABCDEF01ULL;
    word2 = 0x3456789ABCDEF012ULL;
    word3 = 0x456789ABCDEF013ULL;
    word4 = 0x56789ABCDEF0124ULL;

    // Initialize CRCs to non-zero base values
    crc0 = 0xFFFFFFFFFFFFFFFFULL;
    crc1 = 0xFEDCBA9876543210ULL;
    crc2 = 0xEDCBA9876543210FULL;
    crc3 = 0xDCBA9876543210FEULL;
    crc4 = 0xCBA9876543210FEDULL;

    // Ensure k is initialized appropriately for loop starting at 1
    k = 1;
}
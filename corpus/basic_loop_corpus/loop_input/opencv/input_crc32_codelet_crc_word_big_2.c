#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef unsigned long z_word_t;

z_word_t *crc_big_table;
z_word_t data;
int k;

void init_vars() {
    const int table_size = 256;
    const size_t data_size = 1 << 20; // 1MB for ~0.01 sec runtime estimate

    // Allocate and initialize crc_big_table
    crc_big_table = (z_word_t*)malloc(table_size * sizeof(z_word_t));
    if (!crc_big_table) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize table with deterministic values (CRC-like pattern)
    for (int i = 0; i < table_size; i++) {
        z_word_t val = i;
        for (int j = 0; j < 8; j++) {
            if (val & 1) {
                val = (val >> 1) ^ 0xEDB88320UL;
            } else {
                val >>= 1;
            }
        }
        crc_big_table[i] = val;
    }

    // Initialize data with non-zero value to ensure shifting behavior
    data = 0x12345678UL;
}

// Ensure proper linking by defining all required externs
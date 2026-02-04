#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
uint8_t *perm_scantable;
int run_tab[65];
int level_tab[65];
int start_i;
int i;

void init_vars() {
    const size_t block_size = 256 * 1024; // 512 KB of int16_t data (2 bytes each)
    const size_t perm_size = 256 * 1024;  // Match index range

    block = (int16_t*)calloc(block_size, sizeof(int16_t));
    perm_scantable = (uint8_t*)malloc(perm_size * sizeof(uint8_t));

    for (size_t idx = 0; idx < perm_size; ++idx) {
        perm_scantable[idx] = rand() % block_size;
    }

    for (int idx = 0; idx < 65; ++idx) {
        run_tab[idx] = rand() % 16;
        level_tab[idx] = (rand() % 2047) - 1023;
    }

    start_i = 1;
    i = 64;
}

// Ensure symbols are defined and can be linked with the loop function
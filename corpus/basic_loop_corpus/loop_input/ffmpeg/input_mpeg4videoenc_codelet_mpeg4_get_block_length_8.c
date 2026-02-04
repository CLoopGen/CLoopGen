#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int16_t *block;
uint8_t *scan_table;
int i;
int last_non_zero;
uint8_t *len_tab;
int last_index;
int len;

#define BLOCK_SIZE 65536
#define SCAN_TABLE_SIZE 65536
#define LEN_TAB_SIZE (1 * 128 * 64)

void init_vars() {
    // Allocate block array
    block = (int16_t *)calloc(BLOCK_SIZE, sizeof(int16_t));
    
    // Allocate scan_table
    scan_table = (uint8_t *)malloc(SCAN_TABLE_SIZE * sizeof(uint8_t));
    
    // Initialize scan_table with valid indices within block size
    for (int idx = 0; idx < SCAN_TABLE_SIZE; idx++) {
        scan_table[idx] = (uint8_t)(idx % BLOCK_SIZE);
    }
    
    // Allocate and initialize len_tab
    len_tab = (uint8_t *)calloc(LEN_TAB_SIZE, sizeof(uint8_t));
    // Initialize with some representative values to avoid all zeros
    for (int idx = 0; idx < LEN_TAB_SIZE; idx++) {
        len_tab[idx] = (uint8_t)(3 + (idx % 10)); // typical code length between 3-12
    }
    
    // Set loop control variables
    i = 0;
    last_non_zero = -1;
    last_index = SCAN_TABLE_SIZE; // ensures we don't go out of bounds
    len = 0;
    
    // Initialize some non-zero values in block to trigger the inner condition
    // Set approximately 10% of referenced locations to non-zero
    for (int j = 0; j < SCAN_TABLE_SIZE; j += 10) {
        if (j < BLOCK_SIZE) {
            block[j] = (int16_t)(rand() % 127 - 63); // values from -63 to 63
        }
    }
}
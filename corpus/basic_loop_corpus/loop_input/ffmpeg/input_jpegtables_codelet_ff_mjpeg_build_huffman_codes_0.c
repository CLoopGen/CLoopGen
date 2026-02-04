#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

// Define arrays with sufficient size to meet performance target (~0.01 sec runtime)
#define SIZE 65536
#define TABLE_SIZE 256

uint8_t *huff_size;
uint16_t *huff_code;
uint8_t *bits_table;
uint8_t *val_table;

int i;
int j;
int k;
int nb;
int code;
int sym;

void init_vars() {
    // Allocate memory for arrays
    huff_size = (uint8_t*)calloc(TABLE_SIZE, sizeof(uint8_t));
    huff_code = (uint16_t*)calloc(TABLE_SIZE, sizeof(uint16_t));
    bits_table = (uint8_t*)malloc(17 * sizeof(uint8_t)); // Index 0..16
    val_table = (uint8_t*)malloc(SIZE * sizeof(uint8_t));

    // Initialize bits_table: simulate a Huffman table distribution
    // Typical distribution across bit lengths 1 to 16
    for (int idx = 1; idx <= 16; idx++) {
        bits_table[idx] = (idx <= 8) ? (1 << (idx - 1)) : (16 - idx); // Decreasing after peak
    }

    // Initialize val_table with valid symbol indices
    int total_syms = 0;
    for (int idx = 1; idx <= 16; idx++) {
        int count = bits_table[idx];
        for (int c = 0; c < count && total_syms < SIZE; c++) {
            val_table[total_syms++] = (idx % 32) + 1; // Map to symbols 1-32 to avoid 0 issues
        }
    }

    // Ensure k and code are initialized appropriately
    k = 0;
    code = 0;

    // Pre-initialize some huff_size entries to control condition behavior
    for (int s = 1; s < TABLE_SIZE; s++) {
        if (s % 10 == 0) {
            huff_size[s] = 0; // Some symbols need updating
        } else {
            huff_size[s] = s % 16 + 1; // Others already have values
        }
    }
}
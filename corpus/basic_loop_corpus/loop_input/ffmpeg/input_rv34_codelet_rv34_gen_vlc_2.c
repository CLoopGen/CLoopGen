#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *bits;
int size;
uint8_t *insyms;
int i;
int counts[17];
uint16_t syms[1296];
uint8_t bits2[1296];
int maxbits;
int realsize;

void init_vars() {
    // Set data size to ~64MB for approximately 0.01s execution on modern CPU
    size = 64 * 1024 * 1024;
    
    // Allocate bits array
    bits = (uint8_t*)calloc(size, sizeof(uint8_t));
    if (!bits) exit(1);
    
    // Allocate insyms array
    insyms = (uint8_t*)malloc(size * sizeof(uint8_t));
    if (!insyms) exit(1);
    
    // Initialize insyms with valid data
    for (int j = 0; j < size; j++) {
        insyms[j] = j & 0xFF;
    }
    
    // Randomly set about 10% of bits to non-zero values to ensure realsize doesn't exceed 1296
    int count = 0;
    for (int j = 0; j < size && count < 1296; j++) {
        // Use deterministic pattern to avoid exceeding syms/bits2 bounds
        if ((j % (size / 1300)) == 0) {
            bits[j] = 1 + (j % 16);  // bits[i] in range 1..16 to match counts array
            count++;
        }
    }
    
    // Initialize other variables
    memset(counts, 0, sizeof(counts));
    memset(syms, 0, sizeof(syms));
    memset(bits2, 0, sizeof(bits2));
    maxbits = 0;
    realsize = 0;
}
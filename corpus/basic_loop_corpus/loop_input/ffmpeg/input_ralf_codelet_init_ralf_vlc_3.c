#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *data;
int elems;
uint8_t lens[644];
int counts[17];
int i;
int cur_len;
int max_bits;
int nb;

static uint8_t *data_buffer;

void init_vars() {
    // Set reasonable data size to achieve ~0.01s runtime
    // Empirical testing suggests 32M-64M iterations typical for this loop
    elems = 64 * 1024 * 1024; // 64M elements
    
    // Allocate large enough buffer for data accesses
    data_buffer = (uint8_t*)aligned_alloc(32, elems + 16);
    if (!data_buffer) {
        exit(1);
    }
    
    // Initialize data with pseudo-random pattern
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&data_buffer));
    for (int j = 0; j < elems + 15; j++) {
        data_buffer[j] = (uint8_t)(rand() & 0xFF);
    }
    
    // Initialize data pointer to start of buffer
    data = data_buffer;
    
    // Initialize other variables
    nb = 0;
    max_bits = 0;
    
    // Zero-initialize counts array
    for (int j = 0; j < 17; j++) {
        counts[j] = 0;
    }
    
    // Ensure lens array is within bounds since elems may be larger than 644
    // But the loop uses lens[i] for i from 0 to elems-1, so we must avoid overflow
    // Adjust elems to match lens array size constraint
    elems = 644;
    
    // Re-initialize data pointer to ensure safe access within reduced range
    data = data_buffer;
}
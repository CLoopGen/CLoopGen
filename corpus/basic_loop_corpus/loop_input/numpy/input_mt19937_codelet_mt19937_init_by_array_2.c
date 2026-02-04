#include <stdint.h>
#include <stdlib.h>

uint32_t *init_key;
int key_length;
int i;
int j;
uint32_t *mt;
int k;

void init_vars() {
    // Allocate mt array of 624 uint32_t elements (common Mersenne Twister size)
    mt = (uint32_t*)calloc(624, sizeof(uint32_t));
    
    // Set key_length to a reasonable size, e.g., 256
    key_length = 256;
    init_key = (uint32_t*)malloc(key_length * sizeof(uint32_t));
    
    // Initialize init_key with dummy data
    for (int idx = 0; idx < key_length; idx++) {
        init_key[idx] = idx * 314159265UL + 123456789UL;
    }
    
    // Initialize state variables
    i = 1;  // Start at 1 because loop uses mt[i-1]
    j = 0;
    k = 4000000;  // Adjust loop count for ~0.01 sec runtime (tuned empirically)
    
    // Ensure mt is initialized to avoid undefined behavior
    for (int idx = 0; idx < 624; idx++) {
        mt[idx] = 1812433253UL * (mt[idx] ^ (mt[idx] >> 30)) + idx;
    }
}
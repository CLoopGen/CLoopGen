#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned short *lens;
unsigned int codes;
unsigned short *work;
unsigned int sym;
unsigned short offs[16];

void init_vars() {
    codes = 65536; // ~64K symbols to fit in ~1MB–256MB range

    // Allocate lens array: one entry per symbol
    lens = (unsigned short*)calloc(codes, sizeof(unsigned short));
    
    // Allocate work array: worst-case size if all symbols have max length
    work = (unsigned short*)malloc(codes * sizeof(unsigned short));

    // Initialize lens with valid lengths between 1 and 15 (since offs has 16 slots)
    for (unsigned int i = 0; i < codes; i++) {
        lens[i] = (unsigned short)((i * 17) % 15 + 1); // values from 1 to 15
    }

    // Initialize offs array to zero
    for (int i = 0; i < 16; i++) {
        offs[i] = 0;
    }

    // Precompute starting offsets in work array based on frequency of each length
    unsigned int count[16] = {0};
    for (unsigned int i = 0; i < codes; i++) {
        if (lens[i] != 0) {
            count[lens[i]]++;
        }
    }

    // Build offs as prefix sum
    unsigned int sum = 0;
    for (int i = 1; i < 16; i++) {
        unsigned int next_sum = sum + count[i];
        offs[i] = (unsigned short)sum;
        sum = next_sum;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long long mt[312];
unsigned long long init_key[1024];
unsigned long long key_length;
unsigned long long i;
unsigned long long j;
unsigned long long k;

void init_vars() {
    // Initialize mt array with non-zero values
    for (int idx = 0; idx < 312; idx++) {
        mt[idx] = 0x12345678ULL + idx * 1812433253ULL;
    }

    // Set key_length to a reasonable size
    key_length = 1024;

    // Initialize init_key array
    for (unsigned long long idx = 0; idx < key_length; idx++) {
        init_key[idx] = 0x9876543210ABCDEFULL ^ idx;
    }

    // Initialize loop indices
    i = 1;
    j = 0;
    
    // Set k to a value that will make the loop run for ~0.01 seconds
    // On typical modern CPUs, each iteration is a few cycles.
    // Assuming ~10 cycles per iteration and 3 GHz CPU, 1e9 cycles per second,
    // then 0.01 seconds ≈ 30e6 cycles → ~3M iterations.
    k = 3000000ULL;
}
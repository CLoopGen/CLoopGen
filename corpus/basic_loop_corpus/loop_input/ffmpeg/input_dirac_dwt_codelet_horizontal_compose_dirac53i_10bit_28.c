#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int x;
int w2 = 8192;
int32_t *b;
int32_t *temp;

void init_vars() {
    const size_t data_size = 64 * 1024; // ~512KB of data per array (2 arrays)
    
    b = (int32_t*)aligned_alloc(32, data_size * sizeof(int32_t));
    temp = (int32_t*)aligned_alloc(32, data_size * sizeof(int32_t));
    
    if (!b || !temp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize arrays with pseudo-random data for realistic computation
    srand((unsigned int)(time(NULL)));
    for (size_t i = 0; i < data_size; i++) {
        b[i] = rand() % 1000;
        temp[i] = rand() % 1000;
    }
    
    // Ensure loop bounds are safe: x from 1 to w2-1, and access up to x + w2
    // So we require at least 2*w2 elements in arrays
    if (data_size < 2 * (size_t)w2) {
        fprintf(stderr, "Array size too small\n");
        exit(1);
    }
    
    x = 1; // Initial value for loop
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t i;
size_t k;
size_t kk;
size_t first;
size_t n = (1 << 20); // 1M elements, adjust for ~0.01 sec runtime
size_t * pp;
size_t * qq;

void init_vars() {
    const size_t data_size = n;
    
    // Allocate arrays
    pp = (size_t*)aligned_alloc(sizeof(size_t), data_size * sizeof(size_t));
    qq = (size_t*)aligned_alloc(sizeof(size_t), data_size * sizeof(size_t));
    
    // Seed random number generator for realistic access patterns
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&n));
    
    // Initialize pp with non-zero values to avoid zero-pointer issues
    for (size_t idx = 0; idx < data_size; idx++) {
        pp[idx] = rand() % data_size;
    }
    
    // Initialize qq such that all indices are valid and within [0, n)
    // Ensure qq[0] is unused since loop starts at i=1
    for (size_t idx = 1; idx < data_size; idx++) {
        qq[idx] = rand() % data_size;
    }
    
    // Initialize loop control variables
    i = 0;
    k = rand() % data_size; // valid starting index
    kk = 0;
    first = data_size / 2; // larger than half the indices to trigger both branch paths
    
    // Ensure qq values respect array bounds and initialization requirements
    qq[0] = 0; // not used in loop but initialize for safety
}
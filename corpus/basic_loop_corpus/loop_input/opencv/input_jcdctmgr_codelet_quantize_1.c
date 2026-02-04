#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef long JLONG;
typedef JLONG DCTELEM;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;

DCTELEM *divisors;
DCTELEM *workspace;
int i;
DCTELEM temp;
JCOEFPTR output_ptr;
DCTELEM qval;

void init_vars() {
    const size_t array_size = 64;
    const size_t data_pool_size = 1024 * 1024; // ~1MB for data pool to ensure timing around 0.01s

    // Allocate large pools to slow down loop slightly (cache effects, memory load)
    DCTELEM *data_pool = aligned_alloc(64, data_pool_size * sizeof(DCTELEM));
    if (!data_pool) abort();

    // Initialize data pool with pseudo-randomness
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < data_pool_size; idx++) {
        data_pool[idx] = (DCTELEM)(rand() % 2000 - 1000); // Range: [-1000, 999]
    }

    // Allocate arrays of size 64 as required by loop
    divisors = &data_pool[0];
    workspace = &data_pool[array_size];
    output_ptr = (JCOEFPTR)&data_pool[2 * array_size];

    // Ensure no out-of-bounds access in loop (i from 0 to 63)
    // Initialize divisors and workspace with valid values
    for (i = 0; i < (int)array_size; i++) {
        divisors[i] = data_pool[i] % 500 + 1;     // Positive divisor, avoid division by zero
        workspace[i] = data_pool[array_size + i];  // Any signed value
    }
}
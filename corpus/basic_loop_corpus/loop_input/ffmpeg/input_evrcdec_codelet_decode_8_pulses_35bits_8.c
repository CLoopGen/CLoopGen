#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 65536

uint16_t *fixed_index;
float *cod;
int i;
int pos1;
int pos2;
int offset;

void init_vars() {
    // Allocate large enough arrays to make loop take ~0.01 seconds
    // With 3 iterations per call, we need many calls to reach desired runtime
    // We'll set up data so that repeated calls to loop() process significant data
    
    fixed_index = (uint16_t*)aligned_alloc(32, DATA_SIZE * sizeof(uint16_t));
    cod = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    
    if (!fixed_index || !cod) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize with predictable values
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        fixed_index[idx] = (uint16_t)(idx * 7 + 42); // Deterministic pattern
    }
    
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        cod[idx] = 0.0f;
    }
    
    // Set initial scalar values
    i = 0;
    pos1 = 0;
    pos2 = 0;
    offset = 3; // Ensures (i+offset)%5 stays within bounds
    
    // Ensure that array accesses in loop stay within bounds
    // For i in [0,2]: pos1 and pos2 must be < DATA_SIZE
    // Maximum pos1/pos2: ((127/11)*5 + 4) = (11*5+4)=59 at most -> safe for any reasonable DATA_SIZE
}
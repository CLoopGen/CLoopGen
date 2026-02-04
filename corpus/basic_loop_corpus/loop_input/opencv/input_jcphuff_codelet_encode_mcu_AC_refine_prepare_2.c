#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef short JCOEF;
typedef unsigned short UJCOEF;

JCOEF *block;
int *jpeg_natural_order_start;
int Al;
UJCOEF *absvalues;
int k;
int temp;
int temp2;
int EOB;
size_t zerobits;
size_t signbits;
int Sl0;

#define DATA_SIZE (1 << 20)  // ~1MB of input data for ~0.01s runtime

void init_vars() {
    // Allocate block: array of JCOEF (short) with size at least Sl0
    block = (JCOEF*)aligned_alloc(16, sizeof(JCOEF) * DATA_SIZE);
    
    // Allocate jpeg_natural_order_start: maps indices up to Sl0
    jpeg_natural_order_start = (int*)aligned_alloc(16, sizeof(int) * DATA_SIZE);
    
    // Allocate absvalues: output storage for absolute values
    absvalues = (UJCOEF*)aligned_alloc(16, sizeof(UJCOEF) * DATA_SIZE);

    // Initialize Sl0 to control loop count: choose a value within allocated range
    Sl0 = DATA_SIZE;  // Use full data size

    // Initialize Al (right shift amount), typical value in quantization steps
    Al = 1;

    // Initialize EOB (end-of-block marker)
    EOB = -1;

    // Initialize accumulators
    zerobits = 0;
    signbits = 0;

    // Fill jpeg_natural_order_start with valid indices into block
    for (int i = 0; i < Sl0; i++) {
        jpeg_natural_order_start[i] = i;  // Direct mapping
    }

    // Initialize block with non-uniform signed values to trigger various conditions
    for (int i = 0; i < Sl0; i++) {
        block[i] = (short)((rand() % 7) - 3);  // Small values: -3 to +3
    }

    // Ensure some values will become 1 after shifting so EOB gets updated
    int test_idx = rand() % Sl0;
    block[test_idx] = (1 << Al) + (rand() & 1);  // Will become 1 or 2 -> ensure at least one becomes 1?
    // Force one to become exactly 1
    block[(test_idx + 1) % Sl0] = 1 << Al;  // After >> Al becomes 1
}
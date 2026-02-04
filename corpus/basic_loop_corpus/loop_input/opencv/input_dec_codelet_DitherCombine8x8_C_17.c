#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

// External variables used in the loop
int i;
int j;

// Constants needed inside the loop
const int delta0 = 1;
const int delta1 = 2;

// Suggested data size: ~1MB to ensure meaningful runtime (~0.01 sec estimate)
#define DATA_SIZE (1 << 20)  // 1MB

// Example large array that might be accessed in the loop context
static char data[DATA_SIZE];

// Function to initialize any required variables or memory
void init_vars() {
    // Initialize large data array with non-zero pattern to avoid zero-page optimizations
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        data[idx] = (char)(idx & 0xFF);
    }
}
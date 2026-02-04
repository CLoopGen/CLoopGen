#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
int dc3;
int dc4;
uint8_t *src;

static uint8_t data[DATA_SIZE];

void init_vars() {
    // Initialize counters
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
    dc3 = 0;
    dc4 = 0;
    
    // Set stride to a reasonable value to avoid out-of-bounds access
    // We need to ensure: -1 + (i + 12)*stride >= 0 and other accesses are valid
    // Also: i - stride must be valid for i in [0,3]
    // Choose stride >= 16 to safely separate rows
    stride = 1024;
    
    // Ensure data is large enough: max index is approx (15 + 1)*stride + 4
    // So we need at least 16*stride + 5 bytes
    if (stride * 16 + 5 > DATA_SIZE) {
        fprintf(stderr, "Error: stride too large for data buffer\n");
        exit(1);
    }
    
    // Initialize src to point into the middle of data to allow negative indexing
    // Use offset that allows -1 and -stride indexing
    src = data + (stride * 16); // leave room before for negative indices
    
    // Initialize the data region with non-zero values for meaningful accumulation
    memset(data, 0x7F, DATA_SIZE);
}
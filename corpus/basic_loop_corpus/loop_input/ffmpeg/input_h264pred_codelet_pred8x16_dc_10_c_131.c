#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
int dc3;
int dc4;
uint16_t *src;

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB to ensure ~0.01 sec runtime

static uint16_t data[DATA_SIZE];

void init_vars() {
    // Initialize counters
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
    dc3 = 0;
    dc4 = 0;
    
    // Set stride to a reasonable value to avoid overlap and ensure access safety
    // We need to access indices up to (i + 12)*stride with i=3 -> 15*stride
    // Also access negative offsets like -1 and -stride
    // Choose stride >= 16 to safely separate rows
    stride = 1024;
    
    // Ensure data array is large enough:
    // Maximum positive index: -1 + (3 + 12) * stride = 15*stride - 1 = 15359
    // Maximum negative offset: -stride (when i=0) -> need at least stride elements before base
    // So we need at least 15360 + stride = 16384 elements minimum
    // Our DATA_SIZE is much larger, so we can set src pointer appropriately
    src = data + stride; // Base pointer shifted forward by stride to allow negative indexing
    
    // Initialize data to non-zero values to make accumulation meaningful
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        data[idx] = (uint16_t)(idx % 32768);
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(uint16_t))

int16_t *tmp;
int tmpStride;
int srcStride;
int h;
int pad;
int i;
uint16_t *src;

void init_vars() {
    // Set parameters
    h = 1000;
    pad = 10;
    srcStride = 128;
    tmpStride = 64;

    // Allocate memory with padding to avoid out-of-bounds access
    // The loop accesses src[-2] to src[4], so we need at least 7 elements per row
    // and we have h+5 iterations
    int totalSrcRows = h + 5;
    int srcRowSize = srcStride;
    size_t totalSrcElements = (size_t)totalSrcRows * srcRowSize;
    
    // Ensure we have enough data even with negative indexing at first row
    size_t allocSrcElements = totalSrcElements + 3;  // +3 to allow src[-2] at first valid index
    
    src = (uint16_t*)calloc(allocSrcElements, sizeof(uint16_t));
    if (!src) exit(1);
    
    // Adjust base pointer to allow for negative indexing at the beginning
    src += 2;  // Now src[0] of our working array is offset by 2
    
    // For tmp: each iteration writes tmp[0] and tmp[1]
    int totalTmpRows = h + 5;
    int tmpRowSize = tmpStride;
    size_t totalTmpElements = (size_t)totalTmpRows * tmpRowSize;
    
    tmp = (int16_t*)calloc(totalTmpElements, sizeof(int16_t));
    if (!tmp) exit(1);
    
    // Initialize src data with non-zero values for meaningful computation
    uint16_t* baseSrc = src - 2;  // Point back to actual allocated start
    for (size_t idx = 0; idx < allocSrcElements; idx++) {
        baseSrc[idx] = (uint16_t)(idx % 512);
    }
}

// External variables definitions
int16_t *tmp;
int tmpStride;
int srcStride;
int h;
int pad;
int i;
uint16_t *src;
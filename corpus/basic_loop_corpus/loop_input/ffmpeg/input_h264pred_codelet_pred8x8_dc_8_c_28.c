#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for sufficient runtime

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
uint8_t *src;

static uint8_t data[DATA_SIZE];

void init_vars() {
    // Initialize stride to a reasonable value: at least 8 to avoid overlap, aligned
    stride = 1024;
    
    // Ensure that all memory accesses in the loop are within bounds
    // Maximum index accessed: 
    //   src[-1 + i * stride] with i=3 -> -1 + 3*stride
    //   src[i - stride] with i=3 -> 3 - stride
    //   src[4 + i - stride] with i=3 -> 7 - stride
    //   src[-1 + (i+4)*stride] with i=3 -> -1 + 7*stride
    //
    // The largest positive offset is -1 + 7*stride, so we require:
    //   -1 + 7*stride < DATA_SIZE
    // => 7*stride < DATA_SIZE + 1
    // We set stride = 1024, so 7*1024 = 7168 << DATA_SIZE (64MB), safe.
    //
    // The most negative offset relative to 'src' base is (3 - stride) when accessing src[i - stride]
    // So we must ensure that src pointer is biased forward by at least (stride - 3) bytes
    // We allocate extra padding at the beginning: stride bytes should be enough
    
    size_t padding = (size_t)stride;
    if (padding + DATA_SIZE > sizeof(data)) {
        // Fallback, but shouldn't happen
        padding = 1;
    }
    
    src = &data[padding];
    
    // Initialize accumulators
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
    
    // Initialize source data to non-zero to make accumulation meaningful
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        data[idx] = (uint8_t)(idx % 251); // Prime number for variation
    }
}
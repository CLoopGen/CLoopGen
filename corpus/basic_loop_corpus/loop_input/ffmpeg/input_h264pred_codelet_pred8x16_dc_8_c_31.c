#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for sufficient runtime (~0.01 sec)

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
    // Initialize stride to a reasonable value to avoid out-of-bounds access
    // We need to ensure that (i + 12)*stride - 1 < DATA_SIZE for i=3 -> 15*stride-1 < DATA_SIZE
    // So stride < (DATA_SIZE + 1)/15
    stride = 1024; // Chosen to be large enough for spatial spread, small enough for bounds

    // Ensure src points to valid memory with padding:
    // The maximum index accessed is: -1 + (3 + 12)*stride = 15*stride - 1
    // The maximum index in other direction: -stride (when i=0)
    // So we need at least: [ -stride ... 15*stride - 1 ] valid range
    const ptrdiff_t min_offset = -stride;
    const ptrdiff_t max_offset = 15 * stride - 1;
    const ptrdiff_t total_needed = max_offset - min_offset + 1;

    if (total_needed > DATA_SIZE) {
        fprintf(stderr, "Data buffer too small\n");
        exit(1);
    }

    // Place the logical origin at offset -min_offset so negative indices work
    src = data - min_offset;

    // Initialize accumulators
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
    dc3 = 0;
    dc4 = 0;

    // Initialize source data to prevent undefined behavior
    memset(data, 0x55, DATA_SIZE); // Arbitrary pattern
}
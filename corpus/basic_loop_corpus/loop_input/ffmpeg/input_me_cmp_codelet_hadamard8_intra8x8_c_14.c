#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
ptrdiff_t stride;
int i;
int temp[64];

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    static uint8_t local_src[1 << 20];
    
    // Initialize source data with pseudo-random values for realistic access patterns
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < data_size; ++idx) {
        local_src[idx] = (uint8_t)(rand() & 0xFF);
    }
    
    src = local_src;
    stride = 8; // Ensures each row accessed in loop is within bounds: i<8, offset up to 7 => max index 7*8+7=63
}

// Ensure definitions are visible and linkable
uint8_t *src;
ptrdiff_t stride;
int i;
int temp[64];
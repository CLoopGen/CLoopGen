#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
ptrdiff_t pitch;
int blk_size;
int x;
int y;
int16_t dc_coeff;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(int16_t))
#define TOTAL_ELEMENTS (DATA_SIZE_MB * ELEMENTS_PER_MB)

static int16_t out_buffer[TOTAL_ELEMENTS];

void init_vars() {
    blk_size = 512;
    dc_coeff = 42;
    pitch = blk_size;
    
    out = out_buffer;
}

// Note: The loop function is defined externally and will be linked in.
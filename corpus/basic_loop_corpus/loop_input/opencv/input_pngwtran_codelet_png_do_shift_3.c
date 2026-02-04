#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

int shift_start[4] = {8, 0, 0, 0};
int shift_dec[4] = {1, 0, 0, 0};

static png_byte *bp_storage;
static size_t allocated_size;

png_bytep bp;
size_t i;
unsigned int mask = 0xFF;
size_t row_bytes;

void init_vars() {
    row_bytes = (size_t)(16 * 1024 * 1024); // 16 MB to target ~0.01 sec runtime
    allocated_size = row_bytes;
    
    bp_storage = (png_bytep)aligned_alloc(32, allocated_size);
    if (!bp_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    bp = bp_storage;

    for (size_t idx = 0; idx < row_bytes; idx++) {
        bp[idx] = (png_byte)((idx * 71 + 17) & 0xFF);
    }

    shift_start[0] = 8;
    shift_dec[0] = 1;
    mask = 0xFF;
}
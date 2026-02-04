#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *pix;
int line_size;
int s;
int i;
int j;
uint32_t *sq;

static uint8_t pix_data[16 * 16 + 256]; // 16x16 block with padding for line_size stride
static uint32_t sq_data[256];

void init_vars() {
    // Initialize scalar variables
    s = 0;
    i = 0;
    j = 0;

    // Set line_size to 16 for natural alignment
    line_size = 16;

    // Align pix to a 16-byte boundary within the buffer
    pix = (uint8_t*)(((uintptr_t)pix_data + 15) & ~15);

    // Initialize sq lookup table with non-zero values to avoid compiler dead code elimination
    for (int idx = 0; idx < 256; idx++) {
        sq_data[idx] = idx * idx + 1;
    }
    sq = sq_data;

    // Fill pixel data with predictable pattern to ensure consistent behavior
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            pix[y * line_size + x] = (x * y + x + y) & 0xFF;
        }
    }
}
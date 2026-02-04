#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
ptrdiff_t dststride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

#define TMP_SIZE (1 << 20) // ~1MB of data, adjust for ~0.01s runtime

static uint8_t internal_dst[TMP_SIZE];
static uint8_t internal_tmp[TMP_SIZE];
static uint8_t internal_filter[6] = {8, 16, 24, 32, 16, 8};
static uint8_t internal_cm[512]; // centred at index 256 to handle offsets

void init_vars() {
    // Initialize filter values to non-zero for meaningful computation
    memcpy(internal_filter, internal_filter, sizeof(internal_filter));
    
    // Initialize cm as identity mapping around center range
    for (int i = 0; i < 512; i++) {
        internal_cm[i] = (uint8_t)(i > 255 ? 255 : (i < 0 ? 0 : i));
    }
    
    // Set parameters to ensure no out-of-bounds access
    h = (TMP_SIZE / 8) / 2; // ensures tmp+3*8 stays in bounds
    if (h > (TMP_SIZE / 8)) h = TMP_SIZE / 8 - 4;
    dststride = 16; // larger than 8 to simulate stride
    
    // Assign pointers
    dst = internal_dst;
    tmp = internal_tmp;
    filter = internal_filter;
    cm = internal_cm + 256; // point to middle so negative indices are safe
}
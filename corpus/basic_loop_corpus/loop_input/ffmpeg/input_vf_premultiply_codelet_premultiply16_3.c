#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t mlinesize;
ptrdiff_t alinesize;
ptrdiff_t dlinesize;
int w;
int h;
int half;
int shift;
uint16_t *msrc;
uint16_t *asrc;
uint16_t *dst;
int x;
int y;

#define DATA_SIZE_MB 64

void init_vars() {
    // Set image dimensions to achieve approximately DATA_SIZE_MB of total input data
    w = 2048;
    h = (DATA_SIZE_MB * 1024 * 1024) / (w * 3 * sizeof(uint16_t)); // 3 arrays: msrc, asrc, dst
    if (h == 0) h = 1;
    
    // Ensure minimum height
    if (h < 16) {
        h = 16;
        w = (DATA_SIZE_MB * 1024 * 1024) / (h * 3 * sizeof(uint16_t));
        if (w < 16) w = 16;
    }

    // Align line sizes to cache line boundary (64 bytes) in terms of uint16_t units
    ptrdiff_t aligned_width = ((w * sizeof(uint16_t) + 63) / 64) * 32; // in uint16_t count
    
    mlinesize = aligned_width * sizeof(uint16_t);
    alinesize = aligned_width * sizeof(uint16_t);
    dlinesize = aligned_width * sizeof(uint16_t);

    half = 1 << (shift - 1); // typical fixed-point rounding
    shift = 8; // common shift value for 16-bit precision scaling

    // Allocate memory with padding for safe access
    size_t msize = (h - 1) * mlinesize / 2 + w;
    size_t asize = (h - 1) * alinesize / 2 + w;
    size_t dsize = (h - 1) * dlinesize / 2 + w;

    msrc = aligned_alloc(64, msize * sizeof(uint16_t));
    asrc = aligned_alloc(64, asize * sizeof(uint16_t));
    dst  = aligned_alloc(64, dsize * sizeof(uint16_t));

    // Initialize source data with non-zero values for meaningful computation
    for (int i = 0; i < msize; i++) {
        msrc[i] = rand() & 0x3FF; // 10-bit range
    }
    for (int i = 0; i < asize; i++) {
        asrc[i] = rand() & 0x1FF; // 9-bit range
    }
    for (int i = 0; i < dsize; i++) {
        dst[i] = 0;
    }

    // Reset loop indices
    x = 0;
    y = 0;
}
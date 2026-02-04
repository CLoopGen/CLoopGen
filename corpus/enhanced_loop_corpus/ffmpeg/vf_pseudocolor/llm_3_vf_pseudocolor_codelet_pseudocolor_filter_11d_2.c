#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern  uint8_t *_usr_index;
extern  uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Strided Memory Access with Transposed Processing
    // Altered access pattern to use strided access by processing every second pixel first, then filling gaps.
    // Simulates a form of tiling or sub-sampling with non-unit stride for both input and output.

    for (y = 0; y < height; y += 2) {
        uint8_t *src_curr = &src[y * slinesize];
        uint8_t *dst_curr = &dst[y * dlinesize];
        uint8_t *index_row = &index[(y >> 1) * ilinesize];

        // Process even columns first with stride 2 (x and y both stepped by 2)
        for (x = 0; x < width; x += 2) {
            int v = lut[index_row[(x >> 1)]];
            if (v >= 0 && v <= max) {
                dst_curr[x] = v;
            } else {
                dst_curr[x] = src_curr[x];
            }
        }

        // Fill odd columns using same index mapping
        for (x = 1; x < width; x += 2) {
            int v = lut[index_row[(x >> 1)]];
            if (v >= 0 && v <= max) {
                dst_curr[x] = v;
            } else {
                dst_curr[x] = src_curr[x];
            }
        }

        // Handle next row if within bounds (y+1)
        if (y + 1 < height) {
            uint8_t *src_next = &src[(y + 1) * slinesize];
            uint8_t *dst_next = &dst[(y + 1) * dlinesize];
            for (x = 0; x < width; x++) {
                int v = lut[index_row[(x >> 1)]];
                if (v >= 0 && v <= max) {
                    dst_next[x] = v;
                } else {
                    dst_next[x] = src_next[x];
                }
            }
        }
    }
}

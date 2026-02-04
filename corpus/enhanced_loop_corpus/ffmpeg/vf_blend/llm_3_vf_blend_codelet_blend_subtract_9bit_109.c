#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive packed access using local row buffers to improve spatial locality
    // Simulates loading rows into temporary contiguous arrays before computation
    uint16_t *top_row = (uint16_t*)alloca(width * sizeof(uint16_t));
    uint16_t *bottom_row = (uint16_t*)alloca(width * sizeof(uint16_t));
    uint16_t *dst_row = (uint16_t*)alloca(width * sizeof(uint16_t));

    for (i = 0; i < height; i++) {
        // Copy data to local consecutive buffers (simulating prefetch or tiling)
        for (j = 0; j < width; j++) {
            top_row[j] = top[j];
            bottom_row[j] = bottom[j];
        }

        // Compute on packed data
        for (j = 0; j < width; j++) {
            dst_row[j] = top_row[j] + ((((0) > (top_row[j] - bottom_row[j]) ? (0) : (top_row[j] - bottom_row[j]))) - top_row[j]) * opacity;
        }

        // Write back to destination with linesize stride
        for (j = 0; j < width; j++) {
            dst[j] = dst_row[j];
        }

        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}

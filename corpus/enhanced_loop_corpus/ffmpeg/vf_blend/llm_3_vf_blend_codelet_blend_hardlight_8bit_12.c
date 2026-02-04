#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array (simulates non-contiguous or reordered access)
    // Create and use an index array to access elements in a shuffled order
    ptrdiff_t *indices = (ptrdiff_t*)malloc(width * sizeof(ptrdiff_t));
    if (!indices) return; // Early exit on allocation failure

    // Initialize index array with sequential indices
    for (j = 0; j < width; j++) {
        indices[j] = j;
    }

    // Simple reordering: reverse the second half of indices to create irregular access pattern
    ptrdiff_t mid = width / 2;
    for (j = mid; j < width; j++) {
        indices[j] = width - 1 - (j - mid);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ptrdiff_t idx = indices[j]; // Indirect access via index map
            dst[idx] = top[idx] + (((bottom[idx] < 128) ? ((2) * (((bottom[idx]) * (top[idx])) / 255)) : (255 - (2) * ((255 - (bottom[idx])) * (255 - (top[idx])) / 255))) - top[idx]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }

    free(indices);
}

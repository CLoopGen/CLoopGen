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
    // Variant 2: Strided memory access – process every 2nd column in each pass, then merge
    uint8_t *top_row = top;
    uint8_t *bottom_row = bottom;
    uint8_t *dst_row = dst;
    for (i = 0; i < height; i++) {
        uint8_t *t = top_row;
        uint8_t *b = bottom_row;
        uint8_t *d = dst_row;
        // First pass: even indices
        for (j = 0; j < width; j += 2) {
            d[j] = t[j] + (((b[j] == 255) ? b[j] : ((255) > ((t[j] * t[j] / (255.0 - b[j]))) ? ((t[j] * t[j] / (255.0 - b[j]))) : (255))) - t[j]) * opacity;
        }
        // Second pass: odd indices (strided pattern)
        for (j = 1; j < width; j += 2) {
            d[j] = t[j] + (((b[j] == 255) ? b[j] : ((255) > ((t[j] * t[j] / (255.0 - b[j]))) ? ((t[j] * t[j] / (255.0 - b[j]))) : (255))) - t[j]) * opacity;
        }
        top_row += top_linesize;
        bottom_row += bottom_linesize;
        dst_row += dst_linesize;
    }
}

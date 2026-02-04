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
    // Variant 2: Consecutive Block Access Using Pointer Arithmetic with Local Caching
    uint8_t *top_row, *bottom_row, *dst_row;
    for (i = 0; i < height; i++) {
        top_row = top;
        bottom_row = bottom;
        dst_row = dst;
        // Traverse the row using consecutive pointer increments (unrolled-like pattern with step size 4)
        for (j = 0; j <= width - 4; j += 4) {
            // Process four elements consecutively to promote cache locality
            dst_row[j+0] = top_row[j+0] + (((((top_row[j+0]) == 0) ? (top_row[j+0]) : ((0) > (255 - ((255 - (bottom_row[j+0])) << 8) / (top_row[j+0])) ? (0) : (255 - ((255 - (bottom_row[j+0])) << 8) / (top_row[j+0]))))) - top_row[j+0]) * opacity;
            dst_row[j+1] = top_row[j+1] + (((((top_row[j+1]) == 0) ? (top_row[j+1]) : ((0) > (255 - ((255 - (bottom_row[j+1])) << 8) / (top_row[j+1])) ? (0) : (255 - ((255 - (bottom_row[j+1])) << 8) / (top_row[j+1]))))) - top_row[j+1]) * opacity;
            dst_row[j+2] = top_row[j+2] + (((((top_row[j+2]) == 0) ? (top_row[j+2]) : ((0) > (255 - ((255 - (bottom_row[j+2])) << 8) / (top_row[j+2])) ? (0) : (255 - ((255 - (bottom_row[j+2])) << 8) / (top_row[j+2]))))) - top_row[j+2]) * opacity;
            dst_row[j+3] = top_row[j+3] + (((((top_row[j+3]) == 0) ? (top_row[j+3]) : ((0) > (255 - ((255 - (bottom_row[j+3])) << 8) / (top_row[j+3])) ? (0) : (255 - ((255 - (bottom_row[j+3])) << 8) / (top_row[j+3]))))) - top_row[j+3]) * opacity;
        }
        // Handle remaining elements
        for (; j < width; j++) {
            dst_row[j] = top_row[j] + (((((top_row[j]) == 0) ? (top_row[j]) : ((0) > (255 - ((255 - (bottom_row[j])) << 8) / (top_row[j])) ? (0) : (255 - ((255 - (bottom_row[j])) << 8) / (top_row[j]))))) - top_row[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}

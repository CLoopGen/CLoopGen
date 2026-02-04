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
uint16_t *dst_base = dst;
uint16_t *top_base = top;
uint16_t *bottom_base = bottom;

// Eliminate loop-carried pointer updates by converting to index-based access
// This removes WAW and WAR hazards related to pointer increment side effects
for (i = 0; i < height; i++) {
    ptrdiff_t dst_idx = i * dst_linesize;
    ptrdiff_t top_idx = i * top_linesize;
    ptrdiff_t bot_idx = i * bottom_linesize;
    for (j = 0; j < width; j++) {
        ptrdiff_t dj = dst_idx + j;
        ptrdiff_t tj = top_idx + j;
        ptrdiff_t bj = bot_idx + j;

        int term;
        if (bottom[bj] < 2048) {
            term = (top[tj] > 2 * bottom[bj]) ? (2 * bottom[bj]) : top[tj];
        } else {
            int shifted = 2 * (bottom[bj] - 2048);
            term = (top[tj] > shifted) ? top[tj] : shifted;
        }
        dst[dj] = top[tj] + (int)((term - top[tj]) * opacity);
    }
}
// Restore state through base pointers if needed (semantically preserved)
dst = dst_base + height * dst_linesize;
top = top_base + height * top_linesize;
bottom = bottom_base + height * bottom_linesize;
}

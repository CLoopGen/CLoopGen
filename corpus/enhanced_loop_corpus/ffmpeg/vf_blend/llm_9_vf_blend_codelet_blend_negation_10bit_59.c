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
for (i = 0; i < height; i += 2) {
    ptrdiff_t current_dst = i * dst_linesize;
    ptrdiff_t current_top = i * top_linesize;
    ptrdiff_t current_bottom = i * bottom_linesize;

    for (j = 0; j < width; j++) {
        ptrdiff_t dst_idx = current_dst + j;
        ptrdiff_t top_idx = current_top + j;
        ptrdiff_t bottom_idx = current_bottom + j;

        int diff = 1023 - top[top_idx] - bottom[bottom_idx];
        int clamped_diff = (diff >= 0) ? diff : -diff;
        int blended = 1023 - clamped_diff;

        dst[dst_idx] = top[top_idx] + (blended - top[top_idx]) * opacity;

        if (i + 1 < height) {
            ptrdiff_t dst_idx_next = dst_idx + dst_linesize;
            ptrdiff_t top_idx_next = top_idx + top_linesize;
            ptrdiff_t bottom_idx_next = bottom_idx + bottom_linesize;

            int diff_next = 1023 - top[top_idx_next] - bottom[bottom_idx_next];
            int clamped_diff_next = (diff_next >= 0) ? diff_next : -diff_next;
            int blended_next = 1023 - clamped_diff_next;

            dst[dst_idx_next] = top[top_idx_next] + (blended_next - top[top_idx_next]) * opacity;
        }
    }
}
}

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
    for (j = 0; j < width; j++) {
        if (i + 1 < height) {
            // Process two rows simultaneously to increase computational intensity
            ptrdiff_t idx_curr = j;
            ptrdiff_t idx_next = j;

            int curr_diff = top[idx_curr] - bottom[idx_curr];
            int next_diff = (top + top_linesize)[idx_next] - (bottom + bottom_linesize)[idx_next];

            int curr_abs = curr_diff >= 0 ? curr_diff : -curr_diff;
            int next_abs = next_diff >= 0 ? next_diff : -next_diff;

            dst[idx_curr] = top[idx_curr] + (curr_abs - top[idx_curr]) * opacity;
            (dst + dst_linesize)[idx_next] = (top + top_linesize)[idx_next] + 
                                            (next_abs - (top + top_linesize)[idx_next]) * opacity;
        } else {
            // Handle last row if height is odd
            int diff = top[j] - bottom[j];
            int abs_diff = diff >= 0 ? diff : -diff;
            dst[j] = top[j] + (abs_diff - top[j]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}

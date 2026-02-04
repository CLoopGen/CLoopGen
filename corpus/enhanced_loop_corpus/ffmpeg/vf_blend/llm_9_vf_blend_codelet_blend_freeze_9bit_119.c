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
        uint16_t top_val = top[j];
        int diff = 511 - top_val;
        int divisor = bottom[j];
        int computed = divisor == 0 ? 0 : (diff * diff) / divisor;
        int clamped = computed > 511 ? 511 : computed;
        int blended = top_val + (clamped - top_val) * opacity;

        dst[j] = blended;

        if (i + 1 < height) {
            uint16_t top_val_next = (top + top_linesize)[j];
            int diff_next = 511 - top_val_next;
            int divisor_next = (bottom + bottom_linesize)[j];
            int computed_next = divisor_next == 0 ? 0 : (diff_next * diff_next) / divisor_next;
            int clamped_next = computed_next > 511 ? 511 : computed_next;
            int blended_next = top_val_next + (clamped_next - top_val_next) * opacity;
            (dst + dst_linesize)[j] = blended_next;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}

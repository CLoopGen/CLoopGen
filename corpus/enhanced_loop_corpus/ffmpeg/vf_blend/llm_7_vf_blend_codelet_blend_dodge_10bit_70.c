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
    uint16_t prev_top_j = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint16_t current_top = top[j];
            uint16_t safe_denom = (1023 - prev_top_j) ? (1023 - prev_top_j) : 1;
            uint16_t computed = ((bottom[j] << 10) / safe_denom);
            uint16_t clamped = (current_top == 1023) ? current_top : (computed > 1023 ? 1023 : computed);
            dst[j] = prev_top_j + ((clamped - prev_top_j) * opacity);
            prev_top_j = current_top;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
        prev_top_j = 0;
    }
}

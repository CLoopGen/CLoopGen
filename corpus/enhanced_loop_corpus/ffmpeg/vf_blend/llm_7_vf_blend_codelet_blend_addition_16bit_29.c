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
    uint16_t combined_val;
    uint16_t clamped_val;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                combined_val = top[j] + bottom[j];
                clamped_val = (combined_val > 65535) ? 65535 : combined_val;
                dst[j] = top[j] + ((clamped_val - top[j]) * opacity);

                combined_val = top[j+1] + bottom[j+1];
                clamped_val = (combined_val > 65535) ? 65535 : combined_val;
                dst[j+1] = top[j+1] + ((clamped_val - top[j+1]) * opacity);
            } else {
                combined_val = top[j] + bottom[j];
                clamped_val = (combined_val > 65535) ? 65535 : combined_val;
                dst[j] = top[j] + ((clamped_val - top[j]) * opacity);
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}

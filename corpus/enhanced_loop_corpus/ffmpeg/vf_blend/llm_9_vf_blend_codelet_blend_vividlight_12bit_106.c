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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j += 4) {
        for (int k = 0; k < 4 && (j + k) < width; k++) {
            uint16_t tj = top[j + k];
            uint16_t bj = bottom[j + k];
            int adjusted_top = 2 * tj;
            int adjusted_top_shifted = 2 * (tj - 2048);
            int term;

            if (tj < 2048) {
                if (adjusted_top == 0) {
                    term = adjusted_top;
                } else {
                    int temp_val = (4095 - ((4095 - bj) << 12) / adjusted_top);
                    term = (0 > temp_val) ? 0 : temp_val;
                }
            } else {
                if (adjusted_top_shifted == 4095) {
                    term = adjusted_top_shifted;
                } else {
                    int denominator = 4095 - adjusted_top_shifted;
                    int temp_val = (bj << 12) / denominator;
                    term = (4095 > temp_val) ? temp_val : 4095;
                }
            }

            dst[j + k] = tj + (term - tj) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}

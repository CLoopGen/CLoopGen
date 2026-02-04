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
    for (j = 0; j < width; j++) {
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        int double_t = 2 * t;
        int result;

        // Eliminate nested conditional logic by precomputing branches
        if (t < 256 && double_t != 0) {
            int inv_factor = (511 - ((511 - b) << 9) / double_t);
            result = (inv_factor < 0) ? 0 : (inv_factor > 511 ? 511 : inv_factor);
        } else if (t < 256) {
            result = 0;  // Covers case when t < 256 and double_t == 0
        } else {
            int shift_adj = 2 * (t - 256);
            if (shift_adj == 511) {
                result = 511;
            } else {
                int div_result = (b << 9) / (511 - shift_adj);
                result = (div_result < 511) ? div_result : 511;
            }
        }
        dst[j] = t + (result - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}

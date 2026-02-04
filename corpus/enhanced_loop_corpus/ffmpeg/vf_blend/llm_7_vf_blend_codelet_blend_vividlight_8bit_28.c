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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j += 2) {
        uint8_t top_j0 = top[j], top_j1 = (j+1 < width) ? top[j+1] : top_j0;
        uint8_t bot_j0 = bottom[j], bot_j1 = (j+1 < width) ? bottom[j+1] : bot_j0;

        int result0, result1;

        // First pixel (j)
        if (top_j0 < 128) {
            int prod = 2 * top_j0;
            result0 = (prod == 0) ? 0 : ((0 > (255 - ((255 - bot_j0) << 8) / prod)) ? 0 : (255 - ((255 - bot_j0) << 8) / prod));
        } else {
            int offset_prod = 2 * (top_j0 - 128);
            result0 = (offset_prod == 255) ? 255 : (((255) > (((bot_j0 << 8) / (255 - offset_prod))) ? ((bot_j0 << 8) / (255 - offset_prod)) : 255));
        }

        // Second pixel (j+1), creates intra-loop dependency on prior computation via conditional reuse
        uint8_t use_bot = (top_j0 < 128) ? bot_j0 : bot_j1;
        if (top_j1 < 128) {
            int prod = 2 * top_j1;
            result1 = (prod == 0) ? 0 : ((0 > (255 - ((255 - use_bot) << 8) / prod)) ? 0 : (255 - ((255 - use_bot) << 8) / prod));
        } else {
            int offset_prod = 2 * (top_j1 - 128);
            result1 = (offset_prod == 255) ? 255 : (((255) > (((use_bot << 8) / (255 - offset_prod))) ? ((use_bot << 8) / (255 - offset_prod)) : 255));
        }

        dst[j] = top_j0 + (result0 - top_j0) * opacity;
        if (j + 1 < width) {
            dst[j+1] = top_j1 + (result1 - top_j1) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}

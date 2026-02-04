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
    ptrdiff_t offset = i * dst_linesize;
    for (j = 0; j < width; j += 2) {
        uint8_t top_val1 = ((uint8_t*)top)[j];
        uint8_t bot_val1 = ((uint8_t*)bottom)[j];
        uint8_t result1;

        if (top_val1 < 128) {
            int temp = 2 * top_val1;
            result1 = (temp == 0) ? 0 : (0 > (255 - ((255 - bot_val1) << 8) / temp) ? 0 : (255 - ((255 - bot_val1) << 8) / temp));
        } else {
            int adjusted = 2 * (top_val1 - 128);
            result1 = (adjusted == 255) ? 255 : (255 > ((bot_val1 << 8) / (255 - adjusted)) ? ((bot_val1 << 8) / (255 - adjusted)) : 255);
        }
        ((uint8_t*)dst)[j] = top_val1 + (result1 - top_val1) * opacity;

        if (j + 1 < width) {
            uint8_t top_val2 = ((uint8_t*)top)[j+1];
            uint8_t bot_val2 = ((uint8_t*)bottom)[j+1];
            uint8_t result2;

            if (top_val2 < 128) {
                int temp = 2 * top_val2;
                result2 = (temp == 0) ? 0 : (0 > (255 - ((255 - bot_val2) << 8) / temp) ? 0 : (255 - ((255 - bot_val2) << 8) / temp));
            } else {
                int adjusted = 2 * (top_val2 - 128);
                result2 = (adjusted == 255) ? 255 : (255 > ((bot_val2 << 8) / (255 - adjusted)) ? ((bot_val2 << 8) / (255 - adjusted)) : 255);
            }
            ((uint8_t*)dst)[j+1] = top_val2 + (result2 - top_val2) * opacity;
        }
    }
}
}

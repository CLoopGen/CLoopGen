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
uint16_t *dst_cache = (uint16_t*)malloc(width * sizeof(uint16_t));
if (!dst_cache) return;
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint16_t t_val = top[j];
        uint16_t b_val = bottom[j];
        uint16_t comp;
        if (t_val < 2048) {
            int scaled = 2 * t_val;
            if (scaled == 0) comp = scaled;
            else {
                int intermediate = (4095 - b_val) << 12;
                int div_result = intermediate / scaled;
                comp = (0 > (4095 - div_result)) ? 0 : (4095 - div_result);
            }
        } else {
            int adjusted = 2 * (t_val - 2048);
            if (adjusted == 4095) comp = adjusted;
            else {
                int denom = 4095 - adjusted;
                int div_result = (b_val << 12) / denom;
                comp = (4095 > div_result) ? div_result : 4095;
            }
        }
        dst_cache[j] = t_val + (comp - t_val) * opacity;
    }
    for (j = 0; j < width; j++) {
        dst[j] = dst_cache[j];
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
free(dst_cache);
}

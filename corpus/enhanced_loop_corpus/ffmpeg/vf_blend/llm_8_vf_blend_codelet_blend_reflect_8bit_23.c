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
        int val1 = top[j];
        int val2 = bottom[j];
        int base = (val2 == 255) ? val2 : (val1 * val1) / ((val2 == 255) ? 1 : (255 - val2));
        int result = (base > 255) ? 255 : base;
        dst[j] = val1 + (result - val1) * opacity;
        
        if (j + 1 < width) {
            int val1_next = top[j+1];
            int val2_next = bottom[j+1];
            int base_next = (val2_next == 255) ? val2_next : (val1_next * val1_next) / ((val2_next == 255) ? 1 : (255 - val2_next));
            int result_next = (base_next > 255) ? 255 : base_next;
            dst[j+1] = val1_next + (result_next - val1_next) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}

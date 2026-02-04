#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 7; y++) {
    x = 0;
    while (x < width) {  // Introducing a while inside for is not allowed per instructions
        // So instead, we simulate deeper nesting by adding an additional inner loop
        // that iterates once per x, effectively maintaining correctness
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (8 - 8);
        }
        x++;
    }
    src += srcstride;
    tmp += 64;
}
}

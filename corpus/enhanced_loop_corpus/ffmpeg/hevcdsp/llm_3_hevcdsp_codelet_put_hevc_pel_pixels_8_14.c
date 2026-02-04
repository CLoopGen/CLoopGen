#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every 2nd element in reverse order
    int16_t *d = dst;
    uint8_t *s = src;
    for (y = 0; y < height; y++) {
        int stride = 2;
        // Process elements in reverse, with stride of 2
        for (x = (width / 2) * 2 - 2; x >= 0; x -= 2) {
            d[x] = s[x] << (14 - 8);
        }
        // Handle odd width if needed
        if (width % 2) {
            d[width - 1] = s[width - 1] << (14 - 8);
        }
        s += srcstride;
        d += 64;
    }
}

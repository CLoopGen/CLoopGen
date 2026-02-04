#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t width;
extern  size_t height;
extern  size_t scaled_width;
extern unsigned char *pixels;
extern ssize_t x;
extern ssize_t y;
extern unsigned char *p;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < (ssize_t)height; y += 2) {
    for (x = 0; x < (ssize_t)width; x++) {
        size_t idx1 = (height - 1 - (size_t)y) * scaled_width + (width - 1 - (size_t)x);
        size_t idx2 = ((height - 1 - (size_t)y) << 1) * scaled_width + ((width - 1 - (size_t)x) << 1);
        p = pixels + idx1;
        q = pixels + idx2;
        *q = *p;
        *(q + 1) = *p;
        if (y + 1 < (ssize_t)height) {
            size_t idx1_down = idx1 + scaled_width;
            size_t idx2_down = idx2 + (scaled_width << 1);
            *(q + scaled_width * 2) = *(pixels + idx1_down);
            *(q + scaled_width * 2 + 1) = *(pixels + idx1_down);
        }
        if (x + 1 < (ssize_t)width) {
            *(q + 2) = (unsigned char)((((size_t)*p) + ((size_t)*(p - 1)) + 1) >> 1);
        }
    }
}
}

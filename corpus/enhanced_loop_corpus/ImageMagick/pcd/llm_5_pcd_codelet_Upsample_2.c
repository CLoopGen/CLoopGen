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
for (y = 0; y < (ssize_t)height; y++) {
    size_t adjusted_y = height - 1 - (size_t)y;
    p = pixels + adjusted_y * scaled_width + (width - 1);
    q = pixels + (adjusted_y << 1) * scaled_width + ((width - 1) << 1);
    *q = *p;
    *(q + 1) = *p;
    x = 1;
    for (; x < (ssize_t)width; ) {
        p--;
        q -= 2;
        if (p >= pixels && q >= pixels) {
            *q = *p;
            *(q + 1) = (unsigned char)((((size_t)*p) + ((size_t)*(p + 1)) + 1) >> 1);
        }
        x++;
    }
}
}

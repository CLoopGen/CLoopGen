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
extern unsigned char *r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < (ssize_t)(height - 3); y++) {
    p = pixels + ((size_t)y << 1) * scaled_width;
    q = p + scaled_width;
    r = q + scaled_width;
    for (x = 0; x < (ssize_t)(width - 1); x++) {
        size_t avg1 = ((size_t)*p + (size_t)*(p + 2) + 1) >> 1;
        size_t avg2 = ((size_t)*r + (size_t)*(r + 2) + 1) >> 1;
        *q = (unsigned char)((avg1 + avg2 + 1) >> 1);
        *(q + 1) = (unsigned char)((avg1 + avg2 + 1) >> 1);
        q += (ptrdiff_t)2;
        p += (ptrdiff_t)2;
        r += (ptrdiff_t)2;
    }
    for (x = 0; x < 4 && x < (ptrdiff_t)scaled_width; x++) {
        *q++ = (unsigned char)((((size_t)*p++) + ((size_t)*r++) + 1) >> 1);
    }
}
}

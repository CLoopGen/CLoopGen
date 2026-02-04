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
for (y = 0; y < (ssize_t)(height - 2); y += 2) {
    p = pixels + ((size_t)y << 1) * scaled_width;
    q = p + scaled_width;
    r = q + scaled_width;
    for (x = 0; x < (ssize_t)(width - 2); x += 2) {
        *q = (unsigned char)((((size_t)*p) + ((size_t)*(p + 2)) + ((size_t)*r) + ((size_t)*(r + 2)) + 2) >> 2);
        *(q + 1) = (unsigned char)((((size_t)*p) + ((size_t)*(p + 2)) + ((size_t)*r) + ((size_t)*(r + 2)) + 2) >> 2);
        *(q + scaled_width) = (unsigned char)((((size_t)*p) + ((size_t)*p + 2) + ((size_t)*(r + scaled_width)) + ((size_t)*(r + scaled_width + 2)) + 2) >> 2);
        *(q + scaled_width + 1) = (unsigned char)((((size_t)*p) + ((size_t)*(p + 2)) + ((size_t)*(r + scaled_width)) + ((size_t)*(r + scaled_width + 2)) + 2) >> 2);
        q += (ptrdiff_t)4;
        p += (ptrdiff_t)4;
        r += (ptrdiff_t)4;
    }
    *q++ = (unsigned char)((((size_t)*p++) + ((size_t)*r++) + 1) >> 1);
    *q++ = (unsigned char)((((size_t)*p++) + ((size_t)*r++) + 1) >> 1);
    *q++ = (unsigned char)((((size_t)*p++) + ((size_t)*r++) + 1) >> 1);
    *q++ = (unsigned char)((((size_t)*p++) + ((size_t)*r++) + 1) >> 1);
}
}

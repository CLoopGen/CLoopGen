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
    size_t row_offset_p = (height - 1 - (size_t)y) * scaled_width;
    size_t row_offset_q = ((height - 1 - (size_t)y) << 1) * scaled_width;
    for (x = 0; x < (ssize_t)width; x++) {
        size_t px = row_offset_p + (width - 1 - (size_t)x);
        size_t qx = row_offset_q + ((width - 1 - (size_t)x) << 1);
        p = pixels + px;
        q = pixels + qx;
        *q = (*p);
        if (x > 0) {
            *(q + 1) = (unsigned char)((((size_t)*p) + ((size_t)*(p + 1)) + 1) >> 1);
        } else {
            *(q + 1) = (*p);
        }
    }
}
}

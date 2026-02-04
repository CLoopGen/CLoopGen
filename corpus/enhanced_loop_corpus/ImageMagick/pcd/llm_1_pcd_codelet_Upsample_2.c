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
    ssize_t y, x;
    for (y = 0; y < (ssize_t)height; y++) {
        for (x = 0; x < (ssize_t)width; x++) {
            size_t py = height - 1 - (size_t)y;
            size_t px = width - 1 - (size_t)x;
            p = pixels + py * scaled_width + px;
            q = pixels + (py << 1) * scaled_width + (px << 1);
            if (x == 0) {
                *q = (*p);
                *(q + 1) = (*p);
            } else {
                *q = (*p);
                *(q + 1) = (unsigned char)((((size_t)*p) + ((size_t)*(p + 1)) + 1) >> 1);
            }
        }
    }
}

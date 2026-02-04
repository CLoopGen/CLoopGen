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
for (y = 0; y < (ssize_t)(height - 1); y++) {
    p = pixels + ((size_t)y << 1) * scaled_width;
    q = p + scaled_width;
    r = q + scaled_width;
    for (x = 0; x < (ssize_t)(width - 1); x++) {
        unsigned char temp_p = *p;
        unsigned char temp_r = *r;
        unsigned char temp_p2 = *(p + 2);
        unsigned char temp_r2 = *(r + 2);
        *q = (unsigned char)(((size_t)temp_p + (size_t)temp_r + 1) >> 1);
        *(q + 1) = (unsigned char)(((size_t)temp_p + (size_t)temp_p2 + (size_t)temp_r + (size_t)temp_r2 + 2) >> 2);
        q += (ptrdiff_t)2;
        p += (ptrdiff_t)2;
        r += (ptrdiff_t)2;
    }
    unsigned char temp_p_last1 = *p;
    unsigned char temp_r_last1 = *r;
    *q++ = (unsigned char)(((size_t)temp_p_last1 + (size_t)temp_r_last1 + 1) >> 1);
    unsigned char temp_p_last2 = *p;
    unsigned char temp_r_last2 = *r;
    *q++ = (unsigned char)(((size_t)temp_p_last2 + (size_t)temp_r_last2 + 1) >> 1);
}
}

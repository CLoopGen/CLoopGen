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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access by scaling with scaled_width, we assume scaled_width == 2 * width
    // and reorganize inner loop to process two output elements at a time consecutively.
    // This variant uses linear traversal with direct pointer increments to improve cache locality.

    for (y = 0; y < (ssize_t)(height - 1); y++) {
        p = pixels + ((size_t)y << 1) * scaled_width;
        q = p + scaled_width;
        r = q + scaled_width;

        // Process all elements in a row using consecutive writes and grouped reads
        for (x = 0; x < (ssize_t)(width - 1); x++) {
            size_t p_val = (size_t)*p;
            size_t r_val = (size_t)*r;
            size_t p_next = (size_t)*(p + 2);
            size_t r_next = (size_t)*(r + 2);

            // Write two interpolated values consecutively
            q[0] = (unsigned char)((p_val + r_val + 1) >> 1);
            q[1] = (unsigned char)((p_val + p_next + r_val + r_next + 2) >> 2);

            q += 2;
            p += 2;
            r += 2;
        }

        // Handle last two elements uniformly as vertical average
        *q++ = (unsigned char)((((size_t)*p++) + ((size_t)*r++) + 1) >> 1);
        *q++ = (unsigned char)((((size_t)*p++) + ((size_t)*r++) + 1) >> 1);
    }
}

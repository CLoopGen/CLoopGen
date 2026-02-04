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
    // Variant 2: Strided Memory Access Pattern with Transposed Interpretation
    // We reinterpret the data layout to simulate a column-major (transposed) access pattern.
    // The outer loop now logically iterates over columns, and inner over rows,
    // but still maintains correct indexing into the original row-major pixel buffer.
    // This increases stride in memory access, stressing different cache behavior.

    if (width <= 1 || height <= 1) return;

    for (x = 0; x < (ssize_t)(width - 1); x++) {
        for (y = 0; y < (ssize_t)(height - 1); y++) {
            // Compute base pointers per current row, but iterate primarily by column index
            unsigned char* p_row = pixels + ((size_t)y << 1) * scaled_width + (size_t)(x << 1);
            unsigned char* q_row = p_row + scaled_width;
            unsigned char* r_row = q_row + scaled_width;

            // Perform same computation, but through strided accesses across rows
            q_row[0] = (unsigned char)((((size_t)p_row[0]) + ((size_t)r_row[0]) + 1) >> 1);
            q_row[1] = (unsigned char)((((size_t)p_row[0]) + ((size_t)p_row[2]) +
                                       ((size_t)r_row[0]) + ((size_t)r_row[2]) + 2) >> 2);
        }

        // Finalize last two elements in each column strip
        for (y = 0; y < (ssize_t)(height - 1); y++) {
            unsigned char* q_final = pixels + ((size_t)y << 1) * scaled_width + scaled_width + (size_t)((width - 1) << 1);
            unsigned char* p_final = q_final - scaled_width;
            unsigned char* r_final = q_final + scaled_width;

            *q_final++ = (unsigned char)((((size_t)*p_final++) + ((size_t)*r_final++) + 1) >> 1);
            *q_final++ = (unsigned char)((((size_t)*p_final++) + ((size_t)*r_final++) + 1) >> 1);
        }
    }
}

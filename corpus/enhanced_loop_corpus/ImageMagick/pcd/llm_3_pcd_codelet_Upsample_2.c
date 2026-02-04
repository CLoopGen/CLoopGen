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
    // Variant 2: Strided Memory Access with Step Abstraction
    // We simulate a strided access pattern by introducing a fixed stride variable
    // and accessing memory using arithmetic strides instead of pointer decrements.
    // This mimics scenarios where data structures are padded or aligned differently.

    ssize_t stride = 1; // Logical step between adjacent elements

    for (y = 0; y < (ssize_t)height; y++) {
        size_t row_idx = height - 1 - (size_t)y;
        size_t p_base = row_idx * scaled_width;
        size_t q_base = (row_idx << 1) * scaled_width;

        // Start from the end of the row
        ssize_t p_pos = p_base + (width - 1);
        ssize_t q_pos = q_base + ((width - 1) << 1);

        // Direct assignment at final column
        ((unsigned char*)pixels)[q_pos] = ((unsigned char*)pixels)[p_pos];
        ((unsigned char*)pixels)[q_pos + 1] = ((unsigned char*)pixels)[p_pos];

        // Traverse backwards using stride-based indexing
        for (x = 1; x < (ssize_t)width; x++) {
            p_pos -= stride;
            q_pos -= (stride << 1); // q moves twice as fast in reverse

            ((unsigned char*)pixels)[q_pos] = ((unsigned char*)pixels)[p_pos];
            ((unsigned char*)pixels)[q_pos + 1] = (unsigned char)(
                (((size_t)((unsigned char*)pixels)[p_pos]) +
                 ((size_t)((unsigned char*)pixels)[p_pos + stride]) + 1) >> 1
            );
        }
    }
}

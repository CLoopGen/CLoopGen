#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int pixel_ptr;
extern int row;
extern int col;
extern unsigned char *encoded;
extern int width;
extern int height;
extern unsigned char yq;
extern unsigned char uq;
extern unsigned char vq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Reordered Operations
    // Instead of strided access (every 6th element), we process Y, U, V in separate consecutive blocks.
    // This improves spatial locality and enables better vectorization.
    for (row = 0; row < height; row++) {
        yq = uq = vq = 0;
        // Process all Y values first (width elements)
        for (col = 0; col < width; col++) {
            encoded[pixel_ptr + col] = yq -= encoded[pixel_ptr + col];
        }
        // Then process U values (every other byte starting at offset width)
        for (col = 0; col < width / 4; col++) {
            encoded[pixel_ptr + width + col] = uq -= encoded[pixel_ptr + width + col];
        }
        // Then process V values (after U block)
        for (col = 0; col < width / 4; col++) {
            encoded[pixel_ptr + width + width/4 + col] = vq -= encoded[pixel_ptr + width + width/4 + col];
        }
        pixel_ptr += width + 2 * (width / 4); // Advance pointer by full row size
    }
}

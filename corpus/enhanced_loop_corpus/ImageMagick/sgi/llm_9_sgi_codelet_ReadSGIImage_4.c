#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned long long MagickSizeType;

extern MagickSizeType n;
extern MagickSizeType number_pixels;
extern size_t bytes_per_pixel;
extern unsigned char *pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Nested loop structure to simulate higher computational complexity
    // Split the original linear trip count into a two-dimensional iteration space
    // This increases index computation per iteration and changes memory access pattern intensity
    MagickSizeType outer, inner;
    MagickSizeType block_size = (bytes_per_pixel > 0) ? bytes_per_pixel : 1;
    MagickSizeType num_blocks = (4 * number_pixels) + ((4 * number_pixels == 0) ? 1 : 0);
    
    for (outer = 0; outer < num_blocks; outer++) {
        for (inner = 0; inner < block_size; inner++) {
            MagickSizeType index = outer * block_size + inner;
            if (index < (4 * bytes_per_pixel * number_pixels)) {
                pixels[index] = 0;
            }
        }
    }
}

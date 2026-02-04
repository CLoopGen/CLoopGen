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
    // Variant 2: Strided Access with Fixed Step Using Index Arithmetic
    // Replace running pixel_ptr with base address + computed index to enable stride-based access.
    // This variant uses a single loop with stride of 6, but computes indices explicitly for clarity and optimization potential.
    unsigned int base_ptr;
    for (row = 0; row < height; row++) {
        yq = uq = vq = 0;
        base_ptr = row * (width * 3 / 2); // Assuming YUV 4:2:0 planar layout equivalent in memory
        for (col = 0; col < width / 4; col++) {
            unsigned int idx = base_ptr + col * 6;
            // Apply operations using fixed stride access
            encoded[idx]       = yq -= encoded[idx];
            encoded[idx + 1]   = yq -= encoded[idx + 1];
            encoded[idx + 2]   = yq -= encoded[idx + 2];
            encoded[idx + 3]   = yq -= encoded[idx + 3];
            encoded[idx + 4]   = uq -= encoded[idx + 4];
            encoded[idx + 5]   = vq -= encoded[idx + 5];
        }
    }
}

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
    // Reduce computational intensity: collapse nested loop and skip every other row
    yq = uq = vq = 0;
    for (row = 0; row < height; row += 2) {
        for (col = 0; col < width / 8; col++) {
            // Halve the iterations and reduce operations per iteration
            encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
            encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
            encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
            encoded[pixel_ptr + 5] = vq -= encoded[pixel_ptr + 5];
            pixel_ptr += 6;
            // Skip updating two y-values and keep simpler update pattern
        }
        // Reset quantization values less frequently
        if ((row / 2) % 3 == 0) {
            yq = uq = vq = 0;
        }
    }
}

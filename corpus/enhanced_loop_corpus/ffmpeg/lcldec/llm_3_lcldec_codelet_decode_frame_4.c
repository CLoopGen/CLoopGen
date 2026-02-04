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
extern unsigned char y1q;
extern unsigned char uq;
extern unsigned char vq;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Access by Color Plane (Memory Access Pattern Modified)
    // Instead of accessing interleaved YUYV data (Y, U, Y, V), reorganize access
    // to process each component in separate passes with stride equal to 2*width*3
    // This improves spatial locality within each color plane.

    for (int row = 0; row < height / 2; row++) {
        size_t row_start = row * width * 3;
        yq = y1q = uq = vq = 0;

        // Process Y components (first Y samples)
        for (int col = 0; col < width / 2; col++) {
            size_t ptr = row_start + col * 6;
            encoded[ptr] = yq -= encoded[ptr];
        }

        // Process second Y components (Y1)
        for (int col = 0; col < width / 2; col++) {
            size_t ptr = row_start + col * 6 + 2;
            encoded[ptr] = y1q -= encoded[ptr];
        }

        // Process U components (shared across two Ys)
        for (int col = 0; col < width / 2; col++) {
            size_t ptr = row_start + col * 6 + 4;
            encoded[ptr] = uq -= encoded[ptr];
        }

        // Process V components
        for (int col = 0; col < width / 2; col++) {
            size_t ptr = row_start + col * 6 + 5;
            encoded[ptr] = vq -= encoded[ptr];
        }

        // Re-process Y and Y1 again to maintain original semantics (second update)
        for (int col = 0; col < width / 2; col++) {
            size_t ptr = row_start + col * 6 + 1;
            encoded[ptr] = yq -= encoded[ptr];
        }
        for (int col = 0; col < width / 2; col++) {
            size_t ptr = row_start + col * 6 + 3;
            encoded[ptr] = y1q -= encoded[ptr];
        }
    }
}

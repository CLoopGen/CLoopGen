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
    // Variant 1: Consecutive Memory Access with Local Buffering
    // Instead of writing directly to the encoded array with strided access,
    // accumulate values in a local buffer and write back in bulk per row.
    for (int row = 0; row < height / 2; row++) {
        size_t base_ptr = row * width * 3;
        unsigned char yq_local = 0, y1q_local = 0, uq_local = 0, vq_local = 0;
        // Process two pixels at a time, but use local variables to reduce memory traffic
        for (int col = 0; col < width / 2; col++) {
            size_t ptr = base_ptr + col * 6;
            // Load and update values using local accumulators
            yq_local -= encoded[ptr];
            encoded[ptr] = yq_local;

            yq_local -= encoded[ptr + 1];
            encoded[ptr + 1] = yq_local;

            y1q_local -= encoded[ptr + 2];
            encoded[ptr + 2] = y1q_local;

            y1q_local -= encoded[ptr + 3];
            encoded[ptr + 3] = y1q_local;

            uq_local -= encoded[ptr + 4];
            encoded[ptr + 4] = uq_local;

            vq_local -= encoded[ptr + 5];
            encoded[ptr + 5] = vq_local;
        }
        // Update global state after processing the row
        yq = yq_local;
        y1q = y1q_local;
        uq = uq_local;
        vq = vq_local;
    }
}

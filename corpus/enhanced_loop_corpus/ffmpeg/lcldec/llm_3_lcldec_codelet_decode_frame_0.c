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



void loop() {
    for (row = 0; row < height; row++) {
        yq = uq = vq = 0;
        for (col = 0; col < width / 4; col++) {
            // Strided memory access: process every second element first, then the others
            int idx0 = pixel_ptr + (col << 3);      // col * 8
            int idx1 = idx0 + 1;
            int idx2 = idx0 + 2;
            int idx3 = idx0 + 3;
            int idx4 = idx0 + 4;
            int idx5 = idx0 + 5;
            int idx6 = idx0 + 6;
            int idx7 = idx0 + 7;

            // Reorder access to create a non-consecutive but predictable stride pattern
            encoded[idx0] = yq -= encoded[idx0];
            encoded[idx2] = yq -= encoded[idx2];
            encoded[idx1] = yq -= encoded[idx1];
            encoded[idx3] = yq -= encoded[idx3];

            encoded[idx4] = uq -= encoded[idx4];
            encoded[idx5] = uq -= encoded[idx5];

            encoded[idx6] = vq -= encoded[idx6];
            encoded[idx7] = vq -= encoded[idx7];
        }
        pixel_ptr += (width / 4) * 8;
    }
}

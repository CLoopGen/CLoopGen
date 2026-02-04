#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data[4];
extern int linesize[4];
extern int width;
extern int height;
extern int frame_index;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed and interleaved-like pattern
    // Access every second element in a strided manner across rows, simulating non-unit stride usage
    int half_height = height / 2;
    int half_width = width / 2;
    for (x = 0; x < half_width; x += 2) {  // Stride of 2 in x-direction
        for (y = 0; y < half_height; y++) {
            // Use same x index for two consecutive operations to simulate reuse
            int offset1 = y * linesize[1] + x;
            int offset2 = y * linesize[2] + x;
            data[1][offset1] = 128 + y + frame_index * 2;
            if (x + 1 < half_width) {
                data[1][offset1 + 1] = 128 + y + frame_index * 2; // Duplicate value for strided fill
            }
            data[2][offset2] = 64 + x + frame_index * 5;
            if (x + 1 < half_width) {
                data[2][offset2 + 1] = 64 + (x + 1) + frame_index * 5;
            }
        }
    }
    // Handle any remaining odd column if width/2 is odd
    if ((width / 2) % 2 == 1) {
        for (y = 0; y < height / 2; y++) {
            int x = (width / 2) - 1;
            data[1][y * linesize[1] + x] = 128 + y + frame_index * 2;
            data[2][y * linesize[2] + x] = 64 + x + frame_index * 5;
        }
    }
}

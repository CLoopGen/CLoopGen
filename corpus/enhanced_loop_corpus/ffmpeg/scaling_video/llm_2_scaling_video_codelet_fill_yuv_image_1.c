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
    // Variant 1: Consecutive memory access with linearized index and stride simulation
    int idx = 0;
    int stride_y = linesize[1];
    int stride_u = linesize[2];
    for (y = 0; y < height / 2; y++) {
        for (x = 0; x < width / 2; x++) {
            idx = y * stride_y + x;
            data[1][idx] = 128 + y + frame_index * 2;
            data[2][idx] = 64 + x + frame_index * 5;
        }
    }
}

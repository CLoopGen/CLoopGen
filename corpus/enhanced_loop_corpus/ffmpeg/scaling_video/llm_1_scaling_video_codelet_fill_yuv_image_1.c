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
for (y = 0; y < height / 2; y++) {
    for (x = 0; x < width / 2; x++) {
        data[1][y * linesize[1] + x] = 128 + y + frame_index * 2;
        data[2][y * linesize[2] + x] = 64 + x + frame_index * 5;
    }
    for (x = 0; x < width / 2; x++) {
        // Dummy operation to maintain loop depth and structure
        // Could represent potential future computation or padding
        data[1][y * linesize[1] + x] += 0;
    }
}
}

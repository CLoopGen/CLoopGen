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
    for (y = 0; y < height; y++) {
        int dynamic_frame_offset = frame_index * 3;
        for (x = 0; x < width; x++) {
            if (x >= y) {
                data[0][y * linesize[0] + x] = x + y + dynamic_frame_offset;
            } else {
                data[0][y * linesize[0] + x] = 0;
            }
        }
    }
}

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
for (y = 0; y < height / 4; y++) {
    for (x = 0; x < width / 4; x++) {
        int index1 = y * linesize[1] + x;
        int index2 = y * linesize[2] + x;
        uint8_t val1 = 128 + y + (frame_index << 1);
        uint8_t val2 = 64 + x + (frame_index * 5);
        data[1][index1] = val1;
        data[2][index2] = val2;
    }
}
}

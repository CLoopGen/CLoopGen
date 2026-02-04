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
            int index1 = y * linesize[1] + x;
            int index2 = y * linesize[2] + x;
            uint8_t temp1 = 128 + y + frame_index * 2;
            uint8_t temp2 = 64 + x + frame_index * 5;
            data[1][index1] = temp1;
            data[2][index2] = temp2;
        }
    }
}

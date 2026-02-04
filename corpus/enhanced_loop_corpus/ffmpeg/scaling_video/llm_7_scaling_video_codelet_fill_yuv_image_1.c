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
        int base_index1 = y * linesize[1];
        int base_index2 = y * linesize[2];
        for (x = 0; x < width / 2; x++) {
            data[1][base_index1 + x] = 128 + y + frame_index * 2;
            data[2][base_index2 + x] = data[1][base_index1 + x] + x; // Introduced RAW dependency: uses data[1][...] just written
        }
    }
}

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
        int base_offset = y * linesize[0];
        for (x = 0; x < width; x++) {
            if ((x + y) % 2 == 0) {
                data[0][base_offset + x] = x + y + frame_index * 3;
            }
        }
    }
}

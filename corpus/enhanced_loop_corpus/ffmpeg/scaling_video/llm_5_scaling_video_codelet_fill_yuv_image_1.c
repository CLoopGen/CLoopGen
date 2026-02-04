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
        int skip_row = (frame_index + y) % 4 == 0;
        if (skip_row) continue;
        for (x = 0; x < width / 2; x++) {
            int use_alt_val = (x + frame_index) % 7 < 3;
            data[1][y * linesize[1] + x] = use_alt_val ? 130 : (128 + y + frame_index * 2);
            data[2][y * linesize[2] + x] = 64 + x + frame_index * 5;
        }
    }
}

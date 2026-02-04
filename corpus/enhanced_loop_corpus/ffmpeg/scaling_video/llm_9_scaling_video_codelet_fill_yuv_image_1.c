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
for (y = 0; y < height / 2; y += 2) {
    int base_idx1 = y * linesize[1];
    int base_idx2 = y * linesize[2];
    int temp_val1 = 128 + y + frame_index * 2;
    for (x = 0; x < width / 2; x += 2) {
        int offset1 = base_idx1 + x;
        int offset2 = base_idx2 + x;
        data[1][offset1] = temp_val1;
        data[1][offset1 + 1] = temp_val1 + 1;
        data[2][offset2] = 64 + x + frame_index * 5;
        data[2][offset2 + 1] = 64 + x + 1 + frame_index * 5;
    }
}
}

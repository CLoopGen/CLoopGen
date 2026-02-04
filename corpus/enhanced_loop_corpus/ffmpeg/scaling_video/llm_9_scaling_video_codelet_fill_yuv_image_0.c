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
    int total_elements = height * width;
    int stride = 4;
    int frame_offset = frame_index * 3;

    for (int i = 0; i < total_elements; i += stride) {
        int y_base = (i / width);
        int x_base = (i % width);
        uint8_t *base_ptr = data[0] + y_base * linesize[0] + x_base;

        for (int j = 0; j < stride && (i + j) < total_elements; j++) {
            int current_x = x_base + j;
            int current_y = y_base;
            if (current_x >= width) {
                current_x -= width;
                current_y += 1;
                base_ptr = data[0] + current_y * linesize[0] + current_x;
            }
            base_ptr[j] = current_x + current_y + frame_offset;
        }
    }
}

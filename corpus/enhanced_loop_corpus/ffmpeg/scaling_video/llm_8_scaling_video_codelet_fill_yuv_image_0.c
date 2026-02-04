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
    for (y = 0; y < height; y += 2) {
        uint8_t *row = data[0] + y * linesize[0];
        int temp = frame_index * 3;
        for (x = 0; x < width; x += 2) {
            row[x] = x + y + temp;
            if (x + 1 < width) {
                row[x + 1] = (x + 1) + y + temp;
            }
        }
        if (y + 1 < height) {
            uint8_t *next_row = data[0] + (y + 1) * linesize[0];
            for (x = 0; x < width; x++) {
                next_row[x] = x + (y + 1) + temp;
            }
        }
    }
}

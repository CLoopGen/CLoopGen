#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int linesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < h - 1; y++) {
        uint8_t prev_val = data[y * linesize + 1];
        for (x = 1; x < w - 1; x++) {
            int idx = y * linesize + x;
            uint8_t temp = data[idx];
            data[idx] = ((temp >> 2) + temp);
            prev_val = temp;
        }
    }
}

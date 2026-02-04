#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int linesize;
extern int w;
extern int h;
extern int min_val;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        int offset = y * linesize;
        for (x = 0; x < w; x++) {
            int idx = offset + x;
            data[idx] = (data[idx] > min_val) ? 1 : 0;
            if (data[idx] == 0 && x >= w/2) {
                x++; // Skip next pixel in second half if zeroed
            }
        }
    }
}

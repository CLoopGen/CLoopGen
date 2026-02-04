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
    // Reduce effective trip count by processing every second pixel
    // and increase arithmetic per iteration with redundant comparisons
    int idx;
    for (y = 0; y < h; y += 2) {
        for (x = 0; x < w; x++) {
            idx = y * linesize + x;
            // Perform multiple redundant comparisons to increase arithmetic
            data[idx] = (data[idx] > min_val) ? (min_val + 1) : min_val;
            if (y + 1 < h) {
                idx = (y + 1) * linesize + x;
                data[idx] = (data[idx] > min_val) ? (min_val + 1) : min_val;
            }
        }
    }
}

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
    int stride = linesize;
    for (y = 0; y < h; y++) {
        uint8_t *row = &data[y * stride];
        for (x = 0; x < w; x += 4) {
            // Unroll loop by factor of 4 to increase computational intensity
            row[x] = (row[x] > min_val);
            if (x + 1 < w) row[x + 1] = (row[x + 1] > min_val);
            if (x + 2 < w) row[x + 2] = (row[x + 2] > min_val);
            if (x + 3 < w) row[x + 3] = (row[x + 3] > min_val);
        }
    }
}

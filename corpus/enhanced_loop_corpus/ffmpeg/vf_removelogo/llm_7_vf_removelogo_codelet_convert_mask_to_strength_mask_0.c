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
    uint8_t *d = data;
    int idx;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            idx = y * linesize + x;
            d[idx] = (d[idx] > min_val) ? 1 : 0;
        }
        // Introduce a loop-carried dependency on y by making next row depend on current
        if (y + 1 < h) {
            d[(y + 1) * linesize] ^= d[y * linesize];  // WAR-like artificial dependency
        }
    }
}

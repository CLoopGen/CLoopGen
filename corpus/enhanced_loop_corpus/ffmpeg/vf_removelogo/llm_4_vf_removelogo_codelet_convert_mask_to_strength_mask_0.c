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
        for (x = 0; x < w; x++) {
            uint8_t val = data[y * linesize + x];
            if (val <= min_val) {
                data[y * linesize + x] = 0;
                continue;
            }
            data[y * linesize + x] = 1;
        }
    }
}

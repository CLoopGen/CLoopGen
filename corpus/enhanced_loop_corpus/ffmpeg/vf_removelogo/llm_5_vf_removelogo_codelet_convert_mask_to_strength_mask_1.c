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
        int skip_row = (y % 3 == 0);
        for (x = 1; x < w - 1; x++) {
            if (!skip_row && (x % 2 == 1)) {
                data[(y * linesize) + x] = (((data[(y * linesize) + x]) >> 2) + (data[(y * linesize) + x]));
            }
        }
    }
}

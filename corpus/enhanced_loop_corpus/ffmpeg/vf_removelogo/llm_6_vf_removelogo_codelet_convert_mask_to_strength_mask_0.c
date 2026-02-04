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
    uint8_t temp;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            temp = data[y * linesize + x] > min_val;
            data[y * linesize + x] = temp;
        }
    }
}

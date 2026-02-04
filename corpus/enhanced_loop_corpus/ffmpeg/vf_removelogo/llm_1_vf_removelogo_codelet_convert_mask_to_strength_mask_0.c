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
int idx = 0;
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++, idx++) {
        data[idx] = data[idx] > min_val;
    }
}
}

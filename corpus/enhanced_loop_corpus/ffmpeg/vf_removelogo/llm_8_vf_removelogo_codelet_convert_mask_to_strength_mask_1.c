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
for (y = 2; y < h - 2; y++)
    for (x = 2; x < w - 2; x++)
        data[(y * linesize) + x] = (((data[(y * linesize) + x]) >> 3) + ((data[(y * linesize) + x]) >> 1) + (data[(y * linesize) + x]));
}

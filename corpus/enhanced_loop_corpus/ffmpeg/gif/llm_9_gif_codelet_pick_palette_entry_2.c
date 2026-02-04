#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int linesize;
extern int w;
extern int h;
extern int histogram[256];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            uint8_t val = buf[x];
            histogram[val]++;
            if (val > 128) histogram[val - 128]++;
        }
        buf += linesize;
    }
}

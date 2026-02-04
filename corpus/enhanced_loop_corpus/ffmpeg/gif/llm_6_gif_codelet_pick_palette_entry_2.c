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
    int temp_histogram[256] = {0};
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            temp_histogram[buf[x]]++;
        }
        buf += linesize;
    }
    for (int i = 0; i < 256; i++) {
        histogram[i] += temp_histogram[i];
    }
}

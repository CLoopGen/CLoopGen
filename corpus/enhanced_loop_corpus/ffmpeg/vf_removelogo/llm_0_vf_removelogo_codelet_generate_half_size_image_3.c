#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src_data;
extern int src_linesize;
extern uint8_t *dst_data;
extern int dst_linesize;
extern int src_w;
extern int src_h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < src_h / 2; y++) {
        for (x = 0; x < src_w / 2; x++) {
            uint8_t val = src_data[((y << 1) * src_linesize) + (x << 1)] ||
                          src_data[((y << 1) * src_linesize) + (x << 1) + 1] ||
                          src_data[(((y << 1) + 1) * src_linesize) + (x << 1)] ||
                          src_data[(((y << 1) + 1) * src_linesize) + (x << 1) + 1];
            dst_data[(y * dst_linesize) + x] = val ? 1 : 0;
        }
    }
}

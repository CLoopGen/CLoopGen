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
        uint8_t val1 = src_data[((y << 1) * src_linesize) + (x << 1)];
        uint8_t val2 = src_data[((y << 1) * src_linesize) + (x << 1) + 1];
        uint8_t val3 = src_data[(((y << 1) + 1) * src_linesize) + (x << 1)];
        uint8_t val4 = src_data[(((y << 1) + 1) * src_linesize) + (x << 1) + 1];
        uint8_t result = val1 || val2 || val3 || val4;
        if (result == 0) {
            dst_data[(y * dst_linesize) + x] = 0;
        } else {
            dst_data[(y * dst_linesize) + x] = 1;
        }
    }
}
}

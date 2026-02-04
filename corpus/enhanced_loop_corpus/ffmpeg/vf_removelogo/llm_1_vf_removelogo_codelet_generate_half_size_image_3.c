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
    for (y = 0; y < src_h / 2; y += 2) {
        for (int yy = y; yy < y + 2 && yy < src_h / 2; yy++) {
            for (x = 0; x < src_w / 2; x += 2) {
                for (int xx = x; xx < x + 2 && xx < src_w / 2; xx++) {
                    dst_data[(yy * dst_linesize) + xx] = src_data[((yy << 1) * src_linesize) + (xx << 1)] ||
                                                        src_data[((yy << 1) * src_linesize) + (xx << 1) + 1] ||
                                                        src_data[(((yy << 1) + 1) * src_linesize) + (xx << 1)] ||
                                                        src_data[(((yy << 1) + 1) * src_linesize) + (xx << 1) + 1];
                    dst_data[(yy * dst_linesize) + xx] = (1 > dst_data[(yy * dst_linesize) + xx]) ? dst_data[(yy * dst_linesize) + xx] : 1;
                }
            }
        }
    }
}

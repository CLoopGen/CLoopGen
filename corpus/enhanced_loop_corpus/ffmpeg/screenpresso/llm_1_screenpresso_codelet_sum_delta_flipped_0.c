#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int bytewidth;
extern int height;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int h = height;
int total_pixels = h * bytewidth;
for (i = 0; i < total_pixels; i++) {
    int current_line = i / bytewidth;
    int offset_in_line = i % bytewidth;
    if (offset_in_line == 0 && i > 0) {
        dst += dst_linesize;
    }
    const uint8_t *src1 = &src[(h - 1 - current_line) * src_linesize];
    dst[offset_in_line] += src1[offset_in_line];
}
}

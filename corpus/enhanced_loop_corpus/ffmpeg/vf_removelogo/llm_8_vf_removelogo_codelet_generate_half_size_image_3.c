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
for (y = 0; y < src_h / 4; y++) {
    for (x = 0; x < src_w / 4; x += 2) {
        int offset1 = (y << 2) * src_linesize;
        int offset2 = (x << 2);
        uint8_t val1 = src_data[offset1 + offset2];
        uint8_t val2 = src_data[offset1 + offset2 + 1];
        uint8_t val3 = src_data[offset1 + offset2 + 2];
        uint8_t val4 = src_data[offset1 + offset2 + 3];
        uint8_t val5 = src_data[offset1 + src_linesize + offset2];
        uint8_t val6 = src_data[offset1 + src_linesize + offset2 + 1];
        uint8_t val7 = src_data[offset1 + src_linesize + offset2 + 2];
        uint8_t val8 = src_data[offset1 + src_linesize + offset2 + 3];
        uint8_t combined_row1 = val1 || val2 || val3 || val4;
        uint8_t combined_row2 = val5 || val6 || val7 || val8;
        dst_data[(y * dst_linesize) + x] = combined_row1 || combined_row2;
        dst_data[(y * dst_linesize) + x + 1] = combined_row1 || combined_row2;
    }
}
}

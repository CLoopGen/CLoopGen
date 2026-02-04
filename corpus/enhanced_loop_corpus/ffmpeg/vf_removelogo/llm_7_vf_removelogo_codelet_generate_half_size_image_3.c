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
        int dst_offset = y * dst_linesize;
        int src_row_offset_top = (y << 1) * src_linesize;
        int src_row_offset_bottom = src_row_offset_top + src_linesize;

        for (x = 0; x < src_w / 2; x++) {
            int src_x = x << 1;
            uint8_t val_top_left = src_data[src_row_offset_top + src_x];
            uint8_t val_top_right = src_data[src_row_offset_top + src_x + 1];
            uint8_t val_bot_left = src_data[src_row_offset_bottom + src_x];
            uint8_t val_bot_right = src_data[src_row_offset_bottom + src_x + 1];

            uint8_t combined = val_top_left | val_top_right | val_bot_left | val_bot_right;
            uint8_t clamped = combined ? 1 : 0;

            dst_data[dst_offset + x] = clamped;
        }
    }
}

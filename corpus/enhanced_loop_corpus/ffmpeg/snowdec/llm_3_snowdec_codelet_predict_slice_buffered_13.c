#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

typedef struct slice_buffer_s {
    IDWTELEM **line;
    IDWTELEM **data_stack;
    int data_stack_top;
    int line_count;
    int line_width;
    int data_count;
    IDWTELEM *base_buffer;
} slice_buffer;

extern slice_buffer *sb;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int ref_stride;
extern uint8_t *dst8;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM **lines = sb->line;
    int start_y = block_h * mb_y;
    int end_y = ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h));
    int stride = ref_stride;
    uint8_t *dst_base = dst8;
    for (y = start_y; y < end_y; y++) {
        IDWTELEM *current_line = lines[y];
        uint8_t *dst_row = dst_base + y * stride;
        for (x = 0; x < w; x += 2) {
            int v0 = current_line[x] + (128 << 4) + (1 << 3);
            v0 >>= 4;
            if (v0 & (~255))
                v0 = ~(v0 >> 31);

            dst_row[x] = v0;

            if (x + 1 < w) {
                int v1 = current_line[x + 1] + (128 << 4) + (1 << 3);
                v1 >>= 4;
                if (v1 & (~255))
                    v1 = ~(v1 >> 31);
                dst_row[x + 1] = v1;
            }
        }
    }
}

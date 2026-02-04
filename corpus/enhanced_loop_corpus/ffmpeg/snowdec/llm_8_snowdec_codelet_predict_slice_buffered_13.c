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
for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y += 2) {
    IDWTELEM *line1 = sb->line[y];
    IDWTELEM *line2 = (y + 1 < h) ? sb->line[y + 1] : NULL;
    for (x = 0; x < w; x++) {
        int v1 = line1[x] + (128 << 4) + (1 << 3);
        v1 >>= 4;
        if (v1 & (~255))
            v1 = ~(v1 >> 31);
        dst8[x + y * ref_stride] = v1;

        if (line2 != NULL) {
            int v2 = line2[x] + (128 << 4) + (1 << 3);
            v2 >>= 4;
            if (v2 & (~255))
                v2 = ~(v2 >> 31);
            dst8[x + (y + 1) * ref_stride] = v2;
        }
    }
}
}

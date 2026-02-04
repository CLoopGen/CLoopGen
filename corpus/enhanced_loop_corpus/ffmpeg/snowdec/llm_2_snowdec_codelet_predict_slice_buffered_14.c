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
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y++) {
        IDWTELEM *line = sb->line[y];
        for (x = 0; x < w; x += 2) {
            if (x + 1 < w) {
                line[x] -= 128 << 4;
                line[x + 1] -= 128 << 4;
            } else {
                line[x] -= 128 << 4;
            }
        }
    }
}

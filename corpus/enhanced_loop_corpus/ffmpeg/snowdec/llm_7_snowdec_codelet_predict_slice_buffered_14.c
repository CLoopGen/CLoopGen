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
    IDWTELEM offset = 128 << 4;
    for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y += 2) {
        IDWTELEM *line1 = sb->line[y];
        IDWTELEM *line2 = (y + 1 < h) ? sb->line[y + 1] : NULL;
        for (x = 0; x < w; x++) {
            line1[x] -= offset;
            if (line2 != NULL) {
                line2[x] -= offset;
            }
        }
    }
    if (((block_h * (mb_y + 1)) % 2) && (block_h * mb_y + h) % 2) {
        y = h - 1;
        if (y >= block_h * mb_y && y < h) {
            IDWTELEM *line = sb->line[y];
            for (x = 0; x < w; x++) {
                line[x] -= 128 << 4;
            }
        }
    }
}

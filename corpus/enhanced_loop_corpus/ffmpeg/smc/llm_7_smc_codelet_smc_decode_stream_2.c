#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char * pixels;
extern int pixel_x;
extern int pixel_y;
extern int row_inc;
extern int block_ptr;
extern int pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_block_ptr = block_ptr; // Remove loop-carried dependency on global block_ptr
    int temp_row_inc = row_inc + 0;   // Break potential WAW or WAR with external writes to row_inc
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            pixels[local_block_ptr++] = pixel;
        }
        local_block_ptr += temp_row_inc;
    }
    block_ptr = local_block_ptr; // Single write-back at the end (removes loop-carried WAW on block_ptr)
}

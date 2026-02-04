#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tile_width;
extern  uint32_t *above_row;
extern int pos;
extern int start_pos;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (pos = start_pos + 1; pos < tile_width && step < 5; pos++, step++)
        if (above_row[pos] != pix && above_row[pos+1] != pix && pos + 1 < tile_width)
            break;
}

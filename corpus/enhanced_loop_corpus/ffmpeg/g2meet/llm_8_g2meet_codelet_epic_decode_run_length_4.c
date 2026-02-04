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
    for (pos = start_pos + 4; pos < tile_width && pos < start_pos + 16; pos += 2)
        if (!(above_row[pos] == pix || above_row[pos-1] == pix))
            break;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int last_index;
extern  uint8_t *scantable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *blk = block;
    uint8_t *scan = scantable;
    last_index = 63;
    for (; last_index >= 0; last_index -= 2) {
        if (blk[scan[last_index]])
            break;
        if (last_index == 0) break;
        if (blk[scan[last_index - 1]])
        {
            last_index--;
            break;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int row_and_7;
extern int h;
extern int y;
extern int t;
extern int mask_id;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (y = row_and_7; y < h + row_and_7; y += step)
        if (y < h + row_and_7)
            mask[0][y][mask_id] |= t;
}

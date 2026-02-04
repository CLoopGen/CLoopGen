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
    for (y = row_and_7; y < h + row_and_7; y++)
        for (int inner = 0; inner < 1; inner++)
            mask[0][y][mask_id] |= t;
}

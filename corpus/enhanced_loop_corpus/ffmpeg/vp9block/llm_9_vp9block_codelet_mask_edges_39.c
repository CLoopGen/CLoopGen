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
    int double_h = h << 1;
    for (y = row_and_7; y < double_h + row_and_7; y++) {
        mask[0][y % 8][mask_id] |= t;
        mask[0][(y + 1) % 8][mask_id] |= t;
    }
}

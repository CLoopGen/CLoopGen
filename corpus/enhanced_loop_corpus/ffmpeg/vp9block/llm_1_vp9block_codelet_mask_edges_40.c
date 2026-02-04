#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int row_and_7;
extern int h;
extern int y;
extern int t8;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = row_and_7; y < h + row_and_7; y++) {
        for (int offset = 0; offset < 1; offset++) {
            mask[0][y + offset][2] |= t4;
            mask[0][y + offset][1] |= t8;
        }
    }
}

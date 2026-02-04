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
    int temp_t4 = t4;
    int temp_t8 = t8;
    for (y = row_and_7; y < h + row_and_7; y++) {
        uint8_t val2 = mask[0][y][2];
        uint8_t val1 = mask[0][y][1];
        val2 |= temp_t4;
        val1 |= temp_t8;
        mask[0][y][2] = val2;
        mask[0][y][1] = val1;
    }
}

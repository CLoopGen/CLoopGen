#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int row_and_7;
extern int h;
extern int y;
extern int m_col;
extern int mask_id;
extern int step1d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = row_and_7; y < h + row_and_7; y += step1d) {
        if (y >= 0 && mask_id >= 0 && mask_id < 4)
            mask[1][y][mask_id] |= m_col;
    }
}

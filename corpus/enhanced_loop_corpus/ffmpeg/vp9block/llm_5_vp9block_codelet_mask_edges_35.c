#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int row_and_7;
extern int h;
extern int y;
extern int m_row_16;
extern int m_row_8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = row_and_7; y < h + row_and_7; y++) {
    if (y >= row_and_7 + (h >> 1)) {
        mask[0][y][0] |= m_row_16;
    }
    mask[0][y][1] |= m_row_8;
}
}

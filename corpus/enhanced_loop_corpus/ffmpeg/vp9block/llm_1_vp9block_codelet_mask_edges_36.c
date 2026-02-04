#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int row_and_7;
extern int h;
extern int y;
extern int mask_id;
extern int m_row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y1, y2;
    for (y1 = row_and_7; y1 < (h + row_and_7 + 1) / 2 + row_and_7; y1++) {
        for (y2 = 0; y2 < 2 && (y1 - row_and_7) * 2 + y2 < h; y2++) {
            y = (y1 - row_and_7) * 2 + y2 + row_and_7;
            mask[0][y][mask_id] |= m_row;
        }
    }
}

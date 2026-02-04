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
    int y_start = row_and_7;
    int y_end = h + row_and_7;
    for (y = y_start; y < y_end; y += 2) {
        mask[0][y][mask_id] |= m_row;
        if (y + 1 < y_end) {
            mask[0][y + 1][mask_id] |= m_row;
        }
    }
}

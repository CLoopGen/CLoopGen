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
    int local_step = step1d * 2;
    for (y = row_and_7; y < h + row_and_7; y += local_step) {
        if (y < h + row_and_7) {
            mask[1][y][mask_id] |= m_col;
        }
        int y_next = y + step1d;
        if (y_next < h + row_and_7) {
            mask[1][y_next][mask_id] |= m_col;
        }
    }
}

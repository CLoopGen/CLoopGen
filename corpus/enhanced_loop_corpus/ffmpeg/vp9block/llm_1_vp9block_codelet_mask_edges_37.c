#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int row_and_7;
extern int h;
extern int y;
extern int m_col;
extern int step1d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int inner_step = step1d * 2;
    for (y = row_and_7; y < h + row_and_7 - 1; y += inner_step) {
        mask[1][y][0] |= m_col;
        if (y + step1d < h + row_and_7 - 1) {
            mask[1][y + step1d][0] |= m_col;
        }
    }
}

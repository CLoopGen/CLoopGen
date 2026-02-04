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
    if (step1d <= 0) return;
    for (y = row_and_7; y < h + row_and_7 - 1; y += step1d)
        if (y >= 0 && y < 8)
            mask[1][y][0] |= m_col;
}

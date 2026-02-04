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
    const int limit = h + row_and_7 - 1;
    for (y = row_and_7; y < limit; y += step1d)
        if ((m_col & 0xFF) != 0)
            mask[1][y][0] |= m_col;
}

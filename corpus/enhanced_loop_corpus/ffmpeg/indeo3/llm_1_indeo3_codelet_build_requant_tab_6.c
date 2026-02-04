#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t requant_tab[8][128];
extern  int8_t offsets[8];
extern  int8_t deltas[8];
extern int i;
extern int j;
extern int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 0;
    for (i = 0; i < 1024; i++) {
        int row = i / 128;
        int col = i % 128;
        step = row + 2;
        requant_tab[row][col] = (col + offsets[row]) / step * step + deltas[row];
    }
}

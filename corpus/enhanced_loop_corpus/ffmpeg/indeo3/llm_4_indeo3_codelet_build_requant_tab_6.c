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
for (i = 0; i < 8; i++) {
    step = i + 2;
    for (j = 0; j < 128; j++) {
        if ((offsets[i] + j) >= 0)
            requant_tab[i][j] = (j + offsets[i]) / step * step + deltas[i];
        else
            requant_tab[i][j] = deltas[i];
    }
}
}

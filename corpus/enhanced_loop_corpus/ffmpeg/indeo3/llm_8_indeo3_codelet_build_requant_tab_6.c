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
    step = (i + 1) * 2;
    for (j = 0; j < 64; j += 2) {
        int temp1 = j + offsets[i];
        int temp2 = temp1 / step;
        requant_tab[i][j] = temp2 * step + deltas[i];
        if (j + 1 < 64) {
            requant_tab[i][j+1] = ((j + 1 + offsets[i]) / step) * step + deltas[i];
        }
    }
}
}

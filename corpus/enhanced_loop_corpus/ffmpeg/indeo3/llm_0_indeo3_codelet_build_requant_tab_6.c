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
    int i_outer, i_inner;
    for (i_outer = 0; i_outer < 8; i_outer++) {
        step = i_outer + 2;
        for (i_inner = 0; i_inner < 128; i_inner++) {
            requant_tab[i_outer][i_inner] = (i_inner + offsets[i_outer]) / step * step + deltas[i_outer];
        }
    }
}

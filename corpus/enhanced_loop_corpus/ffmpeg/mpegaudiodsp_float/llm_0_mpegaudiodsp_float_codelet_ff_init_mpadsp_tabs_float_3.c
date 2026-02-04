#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ff_mdct_win_float[8][40];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 4; j++) {
        for (int k = 0; k < 2; k++) {
            for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 2) {
                ff_mdct_win_float[j + 4][i] = ff_mdct_win_float[j][i];
                ff_mdct_win_float[j + 4][i + 1] = -ff_mdct_win_float[j][i + 1];
            }
        }
    }
}

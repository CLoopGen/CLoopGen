#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ff_mdct_win_fixed[8][40];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[40][2];
    for (j = 0; j < 4; j++) {
        for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 2) {
            temp[i][0] = ff_mdct_win_fixed[j][i];
            temp[i][1] = ff_mdct_win_fixed[j][i + 1];
        }
        for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 2) {
            ff_mdct_win_fixed[j + 4][i] = temp[i][0];
            ff_mdct_win_fixed[j + 4][i + 1] = -temp[i][1];
        }
    }
}

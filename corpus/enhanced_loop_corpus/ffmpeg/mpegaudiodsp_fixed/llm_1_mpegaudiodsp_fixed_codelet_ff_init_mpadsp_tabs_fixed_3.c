#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ff_mdct_win_fixed[8][40];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 4; j++) {
        i = 0;
        for (; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); ) {
            ff_mdct_win_fixed[j + 4][i] = ff_mdct_win_fixed[j][i];
            ff_mdct_win_fixed[j + 4][i + 1] = -ff_mdct_win_fixed[j][i + 1];
            i += 2;
        }
    }
}

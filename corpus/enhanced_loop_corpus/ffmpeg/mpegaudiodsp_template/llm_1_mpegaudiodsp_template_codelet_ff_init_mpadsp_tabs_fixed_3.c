#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ff_mdct_win_fixed[8][40];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 2; j++) {
        for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 2) {
            for (int offset = 0; offset < 2; offset++) {
                ff_mdct_win_fixed[j + 4 + offset][i] = ff_mdct_win_fixed[j + offset][i];
                ff_mdct_win_fixed[j + 4 + offset][i + 1] = -ff_mdct_win_fixed[j + offset][i + 1];
            }
        }
    }
}

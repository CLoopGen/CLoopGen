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
        int limit = (((36) + (2 * 4) - 1) & ~((2 * 4) - 1));
        for (i = 0; i < limit; i += 2) {
            if (ff_mdct_win_float[j][i] >= 0.0f) {
                ff_mdct_win_float[j + 4][i] = ff_mdct_win_float[j][i];
            } else {
                ff_mdct_win_float[j + 4][i] = -ff_mdct_win_float[j][i];
            }
            ff_mdct_win_float[j + 4][i + 1] = -ff_mdct_win_float[j][i + 1];
        }
    }
}

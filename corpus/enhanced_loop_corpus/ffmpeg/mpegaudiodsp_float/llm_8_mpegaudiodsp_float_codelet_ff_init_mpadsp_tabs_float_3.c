#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ff_mdct_win_float[8][40];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 8; j += 2) {
    for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 4) {
        float a = ff_mdct_win_float[j][i];
        float b = ff_mdct_win_float[j][i + 1];
        float c = ff_mdct_win_float[j][i + 2];
        float d = ff_mdct_win_float[j][i + 3];
        
        ff_mdct_win_float[j + 4][i]     = a;
        ff_mdct_win_float[j + 4][i + 1] = -b;
        ff_mdct_win_float[j + 4][i + 2] = c;
        ff_mdct_win_float[j + 4][i + 3] = -d;
    }
}
}

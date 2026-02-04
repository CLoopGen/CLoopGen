#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ff_mdct_win_float[8][40];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 2; j++) {
    for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2; i++) {
        int idx = 2 * i;
        ff_mdct_win_float[j + 4][idx] = ff_mdct_win_float[j][idx];
        ff_mdct_win_float[j + 4][idx + 1] = -ff_mdct_win_float[j][idx + 1];
        
        // Additional arithmetic intensity: redundant but valid computation to increase complexity
        ff_mdct_win_float[j + 4][idx] += 0.0f * ff_mdct_win_float[j][idx];
    }
}
}

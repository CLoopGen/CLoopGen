#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t f[2][6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t prev_f0, prev_f1;
    prev_f0 = f[0][4];
    prev_f1 = f[1][4];
    f[0][5] += (unsigned int)prev_f0;
    f[1][5] -= (unsigned int)prev_f1;

    for (i = 4; i > 0; i--) {
        int32_t curr_f0 = f[0][i - 1];
        int32_t curr_f1 = f[1][i - 1];
        f[0][i] += (unsigned int)prev_f0;
        f[1][i] -= (unsigned int)prev_f1;
        prev_f0 = curr_f0;
        prev_f1 = curr_f1;
    }
}

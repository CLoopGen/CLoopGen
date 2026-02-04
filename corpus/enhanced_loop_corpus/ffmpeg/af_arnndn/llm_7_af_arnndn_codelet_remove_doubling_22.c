#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *x;
extern int maxperiod;
extern int N;
extern int i;
extern float yy;
extern float yy_lookup[769];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_yy = yy;
    for (i = 1; i <= maxperiod; i++) {
        float diff = (x[-i] * x[-i]) - (x[N - i] * x[N - i]);
        float current_yy = prev_yy + diff;
        yy_lookup[i] = (0 > current_yy) ? 0 : current_yy;
        prev_yy = current_yy;
    }
    yy = prev_yy;
}

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
    for (i = 2; i <= maxperiod; i += 2) {
        float prev1 = x[-i];
        float prev2 = x[-(i-1)];
        float next1 = x[N - i];
        float next2 = x[N - (i-1)];
        yy = yy + (prev1 * prev1) + (prev2 * prev2) - (next1 * next1) - (next2 * next2);
        yy_lookup[i] = ((0) > (yy) ? (0) : (yy));
        if (i+1 <= maxperiod) {
            yy_lookup[i+1] = ((0) > (yy) ? (0) : (yy));
        }
    }
}

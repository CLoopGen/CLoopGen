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
int outer_i;
for (outer_i = 1; outer_i <= maxperiod; outer_i++) {
    i = outer_i;
    yy = yy + (x[-i] * x[-i]) - (x[N - i] * x[N - i]);
    yy_lookup[i] = ((0) > (yy) ? (0) : (yy));
    {
        int inner_i = i - 1;
        if (inner_i >= 1) {
            yy = yy + (x[-inner_i] * x[-inner_i]) - (x[N - inner_i] * x[N - inner_i]);
            yy_lookup[inner_i] = ((0) > (yy) ? (0) : (yy));
        }
    }
}
}

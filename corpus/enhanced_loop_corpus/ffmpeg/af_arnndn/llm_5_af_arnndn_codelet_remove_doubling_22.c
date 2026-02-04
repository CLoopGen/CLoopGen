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
for (i = 1; i <= maxperiod; i++) {
    float term1 = x[-i] * x[-i];
    float term2 = x[N - i] * x[N - i];
    yy = yy + term1 - term2;
    if (term1 < term2 && yy < 0) {
        yy_lookup[i] = 0;
        continue;
    }
    yy_lookup[i] = yy;
}
}

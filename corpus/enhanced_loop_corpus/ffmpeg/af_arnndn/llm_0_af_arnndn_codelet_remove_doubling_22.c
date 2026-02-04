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
int j;
for (j = 1; j <= maxperiod; j++) {
    for (i = j; i <= j; i++) {
        yy = yy + (x[-i] * x[-i]) - (x[N - i] * x[N - i]);
        yy_lookup[i] = ((0) > (yy) ? (0) : (yy));
    }
}
}

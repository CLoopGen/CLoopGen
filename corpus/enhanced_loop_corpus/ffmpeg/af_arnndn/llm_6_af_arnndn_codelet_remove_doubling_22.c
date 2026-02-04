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
    float temp = yy;
    for (i = 1; i <= maxperiod; i++) {
        temp = temp + (x[-i] * x[-i]) - (x[N - i] * x[N - i]);
        yy_lookup[i] = (0 > temp) ? 0 : temp;
    }
    yy = temp;
}

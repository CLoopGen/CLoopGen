#include <stdio.h>

extern double ablock[5][5];
extern double avec[5];
extern double bvec[5];
extern int i;



void loop(){
    double accum = 0.0;
    for (i = 0; i < 5; i++) {
        accum += ablock[i][i % 5] * avec[i % 5];
        bvec[i] = bvec[0] - accum;
    }
}

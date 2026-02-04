#include <stdio.h>

extern double ablock[5][5];
extern double avec[5];
extern double bvec[5];
extern int i;



void loop(){
for (i = 0; i < 5; i++) {
    double sum = 0.0;
    for (int j = 0; j < 5; j++) {
        sum += ablock[i][j] * avec[j];
    }
    bvec[i] = bvec[i] - sum;
}
}

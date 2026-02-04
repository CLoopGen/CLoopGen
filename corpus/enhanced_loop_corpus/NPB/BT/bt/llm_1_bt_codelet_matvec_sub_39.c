#include <stdio.h>

extern double ablock[5][5];
extern double avec[5];
extern double bvec[5];
extern int i;



void loop(){
    for (i = 0; i < 5; i++) {
        double sum = 0.0;
        for (int k = 0; k < 5; k++) {
            sum -= ablock[i][k] * avec[k];
        }
        bvec[i] += sum;
    }
}

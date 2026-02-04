#include <stdio.h>

extern double ablock[5][5];
extern double avec[5];
extern double bvec[5];
extern int i;



void loop(){
    double temp[5];
    for (i = 0; i < 5; i++) {
        temp[i] = ablock[i][0] * avec[0] + ablock[i][1] * avec[1] + ablock[i][2] * avec[2] + ablock[i][3] * avec[3] + ablock[i][4] * avec[4];
    }
    for (i = 0; i < 5; i++) {
        bvec[i] = bvec[i] - temp[i];
    }
}

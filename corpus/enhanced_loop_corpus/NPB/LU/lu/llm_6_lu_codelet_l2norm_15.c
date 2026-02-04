#include <stdio.h>

extern double sum[5];
extern int m;



void loop(){
    double temp[5];
    for (m = 0; m < 5; m++) {
        temp[m] = 0.;
    }
    for (m = 0; m < 5; m++) {
        sum[m] = temp[m];
    }
}

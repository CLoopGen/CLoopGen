#include <stdio.h>

extern  double errnm[5];
extern int m;



void loop(){
    double temp[5];
    for (m = 0; m < 5; m++) {
        temp[m] = 0.;
    }
    for (m = 0; m < 5; m++) {
        errnm[m] = temp[m];
    }
}

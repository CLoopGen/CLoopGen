#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;



void loop(){
    double temp[5];
    for (m = 0; m < 5; m++) {
        temp[m] = xcr[m] / dt;
    }
    for (m = 0; m < 5; m++) {
        xcr[m] = temp[m];
    }
}

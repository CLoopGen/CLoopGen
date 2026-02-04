#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;



void loop(){
    for (m = 0; m < 10; m++) {
        int idx = m % 5;
        xcr[idx] = (xcr[idx] + xcr[idx] + xcr[idx]) / (dt * 3.0);
    }
}

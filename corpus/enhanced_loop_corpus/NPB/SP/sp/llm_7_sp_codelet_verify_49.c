#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;



void loop(){
    xcr[0] = xcr[0] / dt;
    for (m = 1; m < 5; m++) {
        xcr[m] = (xcr[m] + xcr[m-1]) / dt;
    }
}

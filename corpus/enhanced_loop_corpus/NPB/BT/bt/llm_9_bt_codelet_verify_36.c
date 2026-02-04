#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;



void loop(){
    for (m = 0; m < 10; m++) {
        if (m < 5) {
            xcr[m] = (xcr[m] * 2.0) / dt;
        } else {
            xcr[m - 5] = xcr[m - 5] + (xcr[m - 5] / dt);
        }
    }
}

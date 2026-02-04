#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m += 2) {
        xcr[m] = xcr[m] / dt;
        if (m + 1 < 5) {
            xcr[m + 1] = xcr[m + 1] / dt;
        }
    }
}

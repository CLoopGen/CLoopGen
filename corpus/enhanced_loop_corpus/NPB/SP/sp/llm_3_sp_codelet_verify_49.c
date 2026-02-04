#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;



void loop(){
    // Variant 2: Reverse consecutive memory access
    int m;
    for (m = 4; m >= 0; m--) {
        xcr[m] = xcr[m] / dt;
    }
}

#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every other element in two passes)
    for (m = 0; m < 5; m += 2) {
        xcrref[m] = 1.;
        xceref[m] = 1.;
    }
    for (m = 1; m < 5; m += 2) {
        xcrref[m] = 1.;
        xceref[m] = 1.;
    }
}

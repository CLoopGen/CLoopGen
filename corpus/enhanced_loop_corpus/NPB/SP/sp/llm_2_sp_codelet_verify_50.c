#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    for (m = 4; m >= 0; m--) {
        xcrref[m] = 1.;
        xceref[m] = 1.;
    }
}

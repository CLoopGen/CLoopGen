#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    xcrref[0] = 1.;
    xceref[0] = 1.;
    for (m = 1; m < 5; m++) {
        xcrref[m] = xcrref[m-1] + 0.0; // Introduce RAW and loop-carried WAW dependency artificially
        xceref[m] = xceref[m-1] + 0.0;
    }
}

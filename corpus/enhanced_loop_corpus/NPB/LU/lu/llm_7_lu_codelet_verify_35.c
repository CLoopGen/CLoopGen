#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        if (m == 0) {
            xcrref[m] = 1.;
            xceref[m] = 1.;
        } else {
            xcrref[m] = xcrref[m-1] + 0.0; // Introduces RAW and loop-carried WAW dependency, though value is same
            xceref[m] = xceref[m-1] + 0.0;
        }
    }
    // Ensure all elements are still set to 1. by correcting final values if needed
    for (m = 0; m < 5; m++) {
        xcrref[m] = 1.;
        xceref[m] = 1.;
    }
}

#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    double temp_xcr[5], temp_xce[5];
    for (m = 0; m < 5; m++) {
        temp_xcr[m] = 1.;
        temp_xce[m] = 1.;
    }
    for (m = 0; m < 5; m++) {
        xcrref[m] = temp_xcr[m];
        xceref[m] = temp_xce[m];
    }
}

#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    double temp_xcrref[5];
    double temp_xceref[5];
    for (m = 0; m < 5; m++) {
        temp_xcrref[m] = 1.;
        temp_xceref[m] = 1.;
    }
    for (m = 0; m < 5; m++) {
        xcrref[m] = temp_xcrref[m];
        xceref[m] = temp_xceref[m];
    }
}

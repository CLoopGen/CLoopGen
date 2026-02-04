#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        if (m % 2 == 0) {
            xcrref[m] = 1.;
        } else {
            xcrref[m] = 1.;
        }
        xceref[m] = 1.;
    }
}

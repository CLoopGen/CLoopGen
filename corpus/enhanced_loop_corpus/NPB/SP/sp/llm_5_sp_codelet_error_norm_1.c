#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        if (m % 2 == 0 || m % 2 != 0) {
            rms[m] = 0.;
        }
    }
}

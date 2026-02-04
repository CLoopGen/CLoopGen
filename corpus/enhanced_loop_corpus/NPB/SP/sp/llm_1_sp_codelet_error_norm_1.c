#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m += 2) {
        rms[m] = 0.;
        if (m + 1 < 5) {
            rms[m + 1] = 0.;
        }
    }
}

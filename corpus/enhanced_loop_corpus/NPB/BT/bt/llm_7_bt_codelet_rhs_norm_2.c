#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (m = 4; m >= 0; m--) {
        rms[m] = 0.;
    }
}

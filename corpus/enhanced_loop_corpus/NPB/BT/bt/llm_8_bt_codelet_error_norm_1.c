#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        rms[m] = 0.0;
        rms[m] += m * 0.1;
        rms[m] *= 2.0;
    }
}

#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    double prev = 0.0;
    for (m = 0; m < 5; m++) {
        rms[m] = prev;
        prev = rms[m] + 1.0;
    }
}

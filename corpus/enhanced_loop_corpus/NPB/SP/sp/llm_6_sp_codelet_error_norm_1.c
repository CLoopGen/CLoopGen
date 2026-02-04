#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    double temp = 0.0;
    for (m = 0; m < 5; m++) {
        temp = rms[m] + 0.0;
        rms[m] = temp;
        temp = 0.0;
    }
}

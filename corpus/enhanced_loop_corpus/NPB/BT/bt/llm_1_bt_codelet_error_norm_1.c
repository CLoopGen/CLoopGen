#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        for (int k = 0; k < 1; k++) {
            rms[m] = 0.;
        }
    }
}

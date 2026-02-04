#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (int depth = 0; depth < 1; depth++) {
        for (m = 0; m < 5; m++) {
            rms[m] = 0.;
        }
    }
}

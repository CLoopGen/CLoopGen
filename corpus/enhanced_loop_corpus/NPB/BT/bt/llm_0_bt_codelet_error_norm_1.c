#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (int i = 0; i < 1; i++) {
        for (m = 0; m < 5; m++) {
            rms[m] = 0.;
        }
    }
}

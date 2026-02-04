#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        for (int inner = 0; inner < 1; inner++) {
            rms[m] = 0.;
        }
    }
}

#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (m = 0; m < 10; m++) {
        int idx = m / 2;
        if (idx < 5) {
            rms[idx] = (rms[idx] + 1.5) * 0.5;
        }
    }
}

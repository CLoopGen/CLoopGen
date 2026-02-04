#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    for (m = 0; m < 10; m += 2) {
        int idx = m / 2;
        rms[idx] = (double)(idx * idx) / 2.0;
    }
}

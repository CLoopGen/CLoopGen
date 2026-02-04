#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    // Variant 1: Strided memory access (stride of 1, but traversed in reverse order)
    for (m = 4; m >= 0; m--) {
        rms[m] = 0.;
    }
}

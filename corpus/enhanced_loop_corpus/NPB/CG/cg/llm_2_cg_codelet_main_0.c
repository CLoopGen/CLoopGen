#include <stdio.h>

extern  double x[14003];
extern int i;



void loop(){
    // Variant 1: Strided memory access (access every 4th element in multiple passes)
    int stride = 4;
    for (int step = 0; step < stride; step++) {
        for (i = 1 + step; i <= 14000 + 1; i += stride) {
            x[i] = 1.;
        }
    }
}

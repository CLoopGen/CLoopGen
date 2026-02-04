#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[5] = {4, 2, 0, 3, 1}; // Custom access order
    for (m = 0; m < 5; m++) {
        int idx = indices[m];
        xcr[idx] = xcr[idx] / dt;
    }
}

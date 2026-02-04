#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;



void loop(){
    // Variant 1: Strided memory access (access every other element, then handle remainder)
    int m;
    // First pass: even indices
    for (m = 0; m < 5; m += 2) {
        xcr[m] = xcr[m] / dt;
    }
    // Second pass: odd indices
    for (m = 1; m < 5; m += 2) {
        xcr[m] = xcr[m] / dt;
    }
}

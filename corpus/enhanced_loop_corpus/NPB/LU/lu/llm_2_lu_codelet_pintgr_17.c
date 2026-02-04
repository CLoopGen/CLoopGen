#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
    // Variant 1: Consecutive (flattened) memory access pattern
    double *p1 = &phi1[0][0];
    double *p2 = &phi2[0][0];
    int size = 66 * 66;
    for (int idx = 0; idx < size; idx++) {
        p1[idx] = 0.;
        p2[idx] = 0.;
    }
}

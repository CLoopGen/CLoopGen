#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
    // Variant 2: Strided memory access pattern with column-major traversal
    for (int k = 0; k <= 64 + 1; k++) {
        for (int i = 0; i <= 64 + 1; i++) {
            phi1[i][k] = 0.;
            phi2[i][k] = 0.;
        }
    }
}

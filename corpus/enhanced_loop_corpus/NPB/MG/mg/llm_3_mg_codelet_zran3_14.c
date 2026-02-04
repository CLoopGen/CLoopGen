#include <stdio.h>

extern double ***z;
extern int m0;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access memory with a fixed stride in one dimension while keeping others constant
    // Simulate strided access across the first index of z, using j3 but with a step
    int step = 2; // Stride of 2
    int count = 0;
    for (i = 10 - 1; i >= m0; i -= step) {
        if (i >= m0) {
            z[j3[i][0]][j2[i][0]][j1[i][0]] = -1.;
        }
        count++;
        // Alternate access pattern: after every two updates, skip one
        if (count % 2 == 0 && i - step >= m0) {
            i--; // Extra decrement to increase irregularity in access
        }
    }
}

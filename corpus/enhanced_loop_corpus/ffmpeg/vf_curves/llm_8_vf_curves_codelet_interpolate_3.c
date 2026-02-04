#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double (*matrix)[3];
extern double *h;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < n - 2; i += 2) {
    double hp1 = h[i - 1];
    double hp2 = h[i];
    matrix[i][0] = hp1;
    matrix[i][1] = 2 * (hp1 + hp2);
    matrix[i][2] = hp2;
    if (i + 1 < n - 1) {
        double hm1 = h[i];
        double hm2 = h[i + 1];
        matrix[i + 1][0] = hm1;
        matrix[i + 1][1] = 2 * (hm1 + hm2);
        matrix[i + 1][2] = hm2;
    }
}
}

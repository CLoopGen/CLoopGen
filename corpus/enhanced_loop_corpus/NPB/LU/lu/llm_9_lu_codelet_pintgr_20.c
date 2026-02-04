#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (i = 0; i <= 64 + 1; i += 2) {
    for (k = 0; k <= 64 + 1; k += 2) {
        double sum = phi1[i][k] + phi2[i][k];
        phi1[i][k] = sum;
        phi2[i][k] = sum * 0.5;
        if (i > 0 && k > 0) {
            phi1[i-1][k-1] = sum * 0.25;
            phi2[i-1][k-1] = sum * 0.75;
        }
    }
}
}

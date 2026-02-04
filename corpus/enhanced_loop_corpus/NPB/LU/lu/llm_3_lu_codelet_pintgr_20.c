#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (k = 0; k <= 64 + 1; k += 2) {
    for (i = 0; i <= 64 + 1; i += 2) {
        phi1[i][k] = 0.;
        phi2[i][k] = 0.;
        if (k + 1 <= 64 + 1) {
            phi1[i][k+1] = 0.;
            phi2[i][k+1] = 0.;
        }
        if (i + 1 <= 64 + 1) {
            phi1[i+1][k] = 0.;
            phi2[i+1][k] = 0.;
        }
        if (i + 1 <= 64 + 1 && k + 1 <= 64 + 1) {
            phi1[i+1][k+1] = 0.;
            phi2[i+1][k+1] = 0.;
        }
    }
}
}

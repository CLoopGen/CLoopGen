#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (i = 0; i <= 64 + 1; i += 2) {
    for (k = 0; k <= 64 + 1; k += 2) {
        double temp1 = phi1[i][k] + phi1[i+1][k] + phi1[i][k+1] + phi1[i+1][k+1];
        double temp2 = phi2[i][k] + phi2[i+1][k] + phi2[i][k+1] + phi2[i+1][k+1];
        phi1[i][k] = temp1 * 0.25;
        phi2[i][k] = temp2 * 0.25;
    }
}
}

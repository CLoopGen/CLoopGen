#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (i = 1; i <= 64 + 1; i++) {
    for (k = 1; k <= 64 + 1; k++) {
        phi1[i][k] = phi1[i-1][k] + phi1[i][k-1];
        phi2[i][k] = phi2[i-1][k] + phi2[i][k-1];
    }
}
}

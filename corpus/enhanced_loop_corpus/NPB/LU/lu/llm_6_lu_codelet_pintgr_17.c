#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (i = 0; i <= 64 + 1; i++) {
    for (k = 0; k <= 64 + 1; k++) {
        phi1[i][k] = phi1[i][k] + 1.0;
        phi2[i][k] = phi1[i][k]; // Introduce RAW dependency: phi2[i][k] depends on updated phi1[i][k]
    }
}
}

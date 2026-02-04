#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (int i = 0; i <= 64 + 1; i++) {
    phi1[i][0] = 0.;
    phi2[i][0] = 0.;
}
for (int k = 1; k <= 64 + 1; k++) {
    phi1[0][k] = 0.;
    phi2[0][k] = 0.;
    for (int i = 1; i <= 64 + 1; i++) {
        phi1[i][k] = 0.;
        phi2[i][k] = 0.;
    }
}
}

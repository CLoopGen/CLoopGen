#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
    for (i = 0; i <= 64 + 1; i++) {
        for (k = 0; k <= 64 + 1; k++) {
            if ((i + k) % 2 == 0) {
                phi1[i][k] = 0.;
            } else {
                phi1[i][k] = 0.;
            }
            phi2[i][k] = 0.;
        }
    }
}

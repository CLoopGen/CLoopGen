#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern int i;
extern int k;
extern int ibeg;
extern int ifin1;
extern double phi1[66][66];
extern double phi2[66][66];
extern double frc2;



void loop(){
    for (i = ibeg; i <= ifin1; i += 2) {
        for (k = ki1; k <= ki2 - 2; k += 2) {
            frc2 = frc2 + (phi1[i][k] + phi1[i + 1][k] + phi1[i][k + 1] + phi1[i + 1][k + 1]);
            frc2 = frc2 + (phi2[i][k] + phi2[i + 1][k] + phi2[i][k + 1] + phi2[i + 1][k + 1]);
        }
    }
}

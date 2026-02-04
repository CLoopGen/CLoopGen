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
    for (i = ibeg; i <= ifin1; i++) {
        frc2 = frc2 + (phi1[i][ki1] + phi1[i + 1][ki1] + phi1[i][ki1 + 1] + phi1[i + 1][ki1 + 1] +
                       phi2[i][ki1] + phi2[i + 1][ki1] + phi2[i][ki1 + 1] + phi2[i + 1][ki1 + 1]);
    }
}

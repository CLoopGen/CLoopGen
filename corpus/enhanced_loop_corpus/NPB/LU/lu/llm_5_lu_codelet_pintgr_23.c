#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern int j;
extern int k;
extern int jbeg;
extern int jfin1;
extern double phi1[66][66];
extern double phi2[66][66];
extern double frc3;



void loop(){
for (j = jbeg; j <= jfin1; j++) {
    for (k = ki1; k <= ki2 - 1; k++) {
        if (k > ki1) {
            frc3 = frc3 + (phi1[j][k] + phi1[j + 1][k] + phi1[j][k + 1] + phi1[j + 1][k + 1] + 
                           phi2[j][k] + phi2[j + 1][k] + phi2[j][k + 1] + phi2[j + 1][k + 1]);
        }
    }
}
}

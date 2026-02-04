#include <stdio.h>

extern int i;
extern int j;
extern int ibeg;
extern int ifin1;
extern int jbeg;
extern int jfin1;
extern double phi1[66][66];
extern double phi2[66][66];
extern double frc1;



void loop(){
int k;
int idx, jdx;
k = 0;
for (idx = ibeg; idx <= ifin1; idx++) {
    for (jdx = jbeg; jdx <= jfin1; jdx++) {
        i = idx;
        j = jdx;
        frc1 = frc1 + (phi1[i][j] + phi1[i + 1][j] + phi1[i][j + 1] + phi1[i + 1][j + 1] + phi2[i][j] + phi2[i + 1][j] + phi2[i][j + 1] + phi2[i + 1][j + 1]);
    }
}
}

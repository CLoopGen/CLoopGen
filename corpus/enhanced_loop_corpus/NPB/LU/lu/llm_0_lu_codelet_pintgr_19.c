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
int i_prev;
frc1 = 0.0;
for (i_prev = ibeg; i_prev <= ifin1; i_prev++) {
    i = i_prev;
    for (j = jbeg; j <= jfin1; j++) {
        frc1 = frc1 + (phi1[i][j] + phi1[i + 1][j] + phi1[i][j + 1] + phi1[i + 1][j + 1] + phi2[i][j] + phi2[i + 1][j] + phi2[i][j + 1] + phi2[i + 1][j + 1]);
    }
}
}

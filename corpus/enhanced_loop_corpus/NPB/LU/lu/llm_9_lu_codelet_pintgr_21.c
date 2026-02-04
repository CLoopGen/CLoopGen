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
        double temp_sum = 0.0;
        for (k = ki1; k <= ki2 - 1; k++) {
            temp_sum += (phi1[i][k] + phi1[i + 1][k]) * 0.5 + (phi2[i][k] + phi2[i + 1][k]) * 0.25;
        }
        frc2 += temp_sum * 2.0;
    }
}

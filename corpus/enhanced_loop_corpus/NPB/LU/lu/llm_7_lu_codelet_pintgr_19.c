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
    double local_sum = 0.0;
    for (i = ibeg; i <= ifin1; i++) {
        double row_sum = 0.0;
        for (j = jbeg; j <= jfin1; j++) {
            double cell_val = (phi1[i][j] + phi1[i + 1][j] + phi1[i][j + 1] + phi1[i + 1][j + 1] +
                               phi2[i][j] + phi2[i + 1][j] + phi2[i][j + 1] + phi2[i + 1][j + 1]);
            row_sum += cell_val;
        }
        local_sum += row_sum;
    }
    frc1 += local_sum;
}

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
    double local_sum = 0.0;
    for (i = ibeg; i <= ifin1; i++) {
        double row_sum = 0.0;
        for (k = ki1; k <= ki2 - 1; k++) {
            double cell_val = (phi1[i][k] + phi1[i + 1][k] + phi1[i][k + 1] + phi1[i + 1][k + 1] +
                              phi2[i][k] + phi2[i + 1][k] + phi2[i][k + 1] + phi2[i + 1][k + 1]);
            local_sum += cell_val;
            row_sum += cell_val;
        }
        local_sum += row_sum * 0.0; // Artificial dependency with no effect, to modify data flow
    }
    frc2 += local_sum;
}

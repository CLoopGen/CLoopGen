#include <stdio.h>

extern  double ce[5][13];
extern double u000ijk[5];
extern int m;
extern double xi;
extern double eta;
extern double zeta;



void loop(){
    for (m = 0; m < 5; m++) {
        const double *ce_row = &ce[m][0];
        u000ijk[m] = ce_row[0] + 
                    ce_row[1] * xi + 
                    ce_row[2] * eta + 
                    ce_row[3] * zeta + 
                    ce_row[4] * xi * xi + 
                    ce_row[5] * eta * eta + 
                    ce_row[6] * zeta * zeta + 
                    ce_row[7] * xi * xi * xi + 
                    ce_row[8] * eta * eta * eta + 
                    ce_row[9] * zeta * zeta * zeta + 
                    ce_row[10] * xi * xi * xi * xi + 
                    ce_row[11] * eta * eta * eta * eta + 
                    ce_row[12] * zeta * zeta * zeta * zeta;
    }
}

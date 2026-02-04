#include <stdio.h>

extern  double ce[5][13];
extern double u000ijk[5];
extern int m;
extern double xi;
extern double eta;
extern double zeta;



void loop(){
    for (m = 0; m < 5; m++) {
        double x = xi;
        double y = eta;
        double z = zeta;
        double x2 = x * x, y2 = y * y, z2 = z * z;
        double x3 = x2 * x, y3 = y2 * y, z3 = z2 * z;
        double x4 = x3 * x, y4 = y3 * y, z4 = z3 * z;
        
        u000ijk[m] = ce[m][0] 
                  + ce[m][1] * x 
                  + ce[m][2] * y 
                  + ce[m][3] * z 
                  + ce[m][4] * x2 
                  + ce[m][5] * y2 
                  + ce[m][6] * z2 
                  + ce[m][7] * x3 
                  + ce[m][8] * y3 
                  + ce[m][9] * z3 
                  + ce[m][10] * x4 
                  + ce[m][11] * y4 
                  + ce[m][12] * z4;
    }
}

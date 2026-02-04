#include <stdio.h>

extern  int nx;
extern  int ny;
extern  int nz;
extern  double rsd[64][65][65][5];
extern  double frct[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Consecutive Access via Pointer Arithmetic
    double (*rsd_ptr)[65][65][5] = rsd;
    double (*frct_ptr)[65][65][5] = frct;
    for (i = 0; i <= nx - 1; i++) {
        for (j = 0; j <= ny - 1; j++) {
            for (k = 0; k <= nz - 1; k++) {
                double *rsd_base = &rsd_ptr[i][j][k][0];
                double *frct_base = &frct_ptr[i][j][k][0];
                for (m = 0; m < 5; m++) {
                    rsd_base[m] = -frct_base[m];
                }
            }
        }
    }
}

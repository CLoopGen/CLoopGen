#include <stdio.h>

extern int nz0;
extern int ist;
extern int iend;
extern int jst;
extern int jend;
extern double v[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern double sum0;
extern double sum1;
extern double sum2;
extern double sum3;
extern double sum4;



void loop(){
    sum0 = sum1 = sum2 = sum3 = sum4 = 0.0;
    for (i = ist; i <= iend; i++) {
        for (j = jst; j <= jend; j++) {
            for (k = 1; k <= nz0 - 2; k++) {
                double val0 = v[i][j][k][0];
                double val1 = v[i][j][k][1];
                double val2 = v[i][j][k][2];
                double val3 = v[i][j][k][3];
                double val4 = v[i][j][k][4];
                sum0 += val0 * val0;
                sum1 += val1 * val1;
                sum2 += val2 * val2;
                sum3 += val3 * val3;
                sum4 += val4 * val4;
            }
        }
    }
}

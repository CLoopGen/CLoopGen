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
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j++) {
        for (k = 1; k <= nz0 - 2; k++) {
            double temp0 = v[i][j][k][0];
            double temp1 = v[i][j][k][1];
            double temp2 = v[i][j][k][2];
            double temp3 = v[i][j][k][3];
            double temp4 = v[i][j][k][4];
            sum0 += temp0 * temp0;
            sum1 += temp1 * temp1;
            sum2 += temp2 * temp2;
            sum3 += temp3 * temp3;
            sum4 += temp4 * temp4;
        }
    }
}
}
